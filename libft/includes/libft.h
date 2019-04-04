/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 09:34:16 by ccodiga           #+#    #+#             */
/*   Updated: 2019/01/15 14:14:30 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include "libftprintf.h"
# define IS_WHITESPACE(x) (x == ' ' || x == '\n' || x == '\t')

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				size_array(char **array);
void				replace(char **string, char *to_replace, char *replacement);
char				*strjoin_more(int nbr_param, ...);
int					ft_strlen_char(char *str, char c);
void				free_array(char **array);
int					search_str_in_array(char **array, char *string);
char				**copy_array(char **old_array);
int					ft_printf(const char *restrict format, ...);
void				ft_strclr(char *s);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
int					cnt_digits(long long i, char *base);
void				ft_lstadd(t_list **alst, t_list *l_new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strstr_index(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
	size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
int					ft_isdigit(int c);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s1);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				print_binary_variable(uint64_t variable, int size);
void				print_binary_string(char *message, int len);
char				*hold_and_free(char *old, char *addition);
char				**ft_strsplit_whitespace(char const *s);
int					ft_strchr_index(const char *s, int c);


#endif
