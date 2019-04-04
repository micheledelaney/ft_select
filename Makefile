NAME = ft_select

SRC =	main.c \
		signal_handling.c \
		print_files.c \
		read_process_key.c \
		initialize.c \
		print_selected_files.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

MINISHELL_SRCS = $(addprefix srcs/,$(SRC))

LIB = ./libft/libft.a

INC= -I./includes

$(NAME): $(LIB)
	@gcc $(FLAGS) $(INC) $(MINISHELL_SRCS) $(LIB) -lcurses -o $(NAME);
	@echo compiling ft_select

all: $(NAME)

$(LIB):
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
