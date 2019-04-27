MACHINE := $(shell uname)

NAME = ft_select

SRC =	main.c \
		signal_handling.c \
		term_config.c \
		print_files.c \
		read_process_key.c \
		initialize.c \
		print_selected_files.c \
		ft_putchar_int.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

MINISHELL_SRCS = $(addprefix srcs/,$(SRC))

LIBFT = ./libft/libft.a

ifeq ($(MACHINE), Linux)
LIBS = -lcurses
endif
ifeq ($(MACHINE), Darwin)
LIBS = -ltermcap
endif

INC= -I./includes

$(NAME): $(LIBFT)
	@gcc $(FLAGS) $(INC) $(MINISHELL_SRCS) $(LIBFT) $(LIBS) -o $(NAME);
	@echo compiling ft_select

all: $(NAME)

$(LIBFT):
	@make -C libft/

clean:
	@rm -rf $(OBJ) libft/$(OBJ)
	@echo deleting binary files

fclean: clean
	@rm -rf $(NAME) libft/libft.a
	@make fclean -C libft
	@echo deleting libft.a and ft_select

re: fclean all

.PHONY : all, re, clean, fclean
