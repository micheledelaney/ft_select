NAME = ft_select

SRC =	./ft_select.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

MINISHELL_SRCS = $(addprefix srcs/,$(SRC))

LIB = ./libft/libft.a

INC= -I./includes

$(NAME): $(LIB)
	@gcc $(FLAGS) $(INC) $(MINISHELL_SRCS) $(LIB) -o $(NAME);
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
