# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 09:43:28 by ccodiga           #+#    #+#              #
#    Updated: 2019/01/15 14:05:34 by ccodiga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIBFT =	ft_memset.c \
		replace.c \
		size_array.c \
		ft_strlen_char.c \
		search_str_in_array.c \
		free_array.c \
		strjoin_more.c \
		copy_array.c \
		hold_and_free.c \
		print_binary.c \
		get_next_line.c \
		cnt_digits.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcmp.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_isdigit.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strrchr.c \
		ft_strchr_index.c \
		ft_strstr.c \
		ft_strstr_index.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_strsplit_whitespace.c

FT_PRINTF =	printing.c \
			diverse.c \
			conversions_scdif.c \
			conversions_poux.c \
			casting.c \
			helper.c \
			floats.c \
			casting.c \
			ft_printf.c \

CFLAGS = -Wall -Wextra -Werror

OBJSFD = objects

FT_PRINTF_SRCS = $(addprefix srcs/ft_printf/,$(FT_PRINTF))

LIBFT_SRCS = $(addprefix srcs/,$(LIBFT))

SRCS = $(LIBFT_SRCS) $(FT_PRINTF_SRCS)

OBJECTS = $(LIBFT:.c=.o) $(FT_PRINTF:.c=.o)

OBJS = $(addprefix $(OBJSFD)/, $(OBJECTS))

VPATH =	srcs:srcs/ft_printf

all: $(NAME)

$(NAME): $(OBJS)
	@ar src $@ $(OBJS)
	@ranlib $@
	@echo "libft.a is created"

$(OBJSFD):
	@mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	@$(CC) $(CFLAGS) $(HDR) -c $< -o $@

HDR = -I./includes

clean:
	@/bin/rm -f $(OBJS)
	@rm -rf $(OBJSFD)
	@echo "objects deleted"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "library deleted"

re: fclean all
