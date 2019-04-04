/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 09:34:16 by ccodiga           #+#    #+#             */
/*   Updated: 2018/12/07 12:44:46 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFTPRINTF_H
# define _LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include "libft.h"
# define IS_DIGIT(x) ('0' <= x && x <= '9')
# define IS_ALPHA(x) (('A' <= x && => 'Z') || ('a' <= x && x <= 'z'))
# define IS_CONVERSION(x) (x == 's' || x == 'c' || x == 'd' || C2(x) || C3(x))
# define C2(x) (x == 'i' || x == 'p' || x == 'o' || x == 'u' || x == 'x')
# define C3(x) (x == 'X' || x == 'f' || x == 'U' || x == 'O' || C4(x))
# define C4(x) (x == 'S' || x == 'D' || x == 'F' || x == 'C')
# define IS_FLAG(x) (x == 'l' || x == 'h' || x == 'L' || x == 'z' || x == 'j')
# define OPT(x) (IS_FLAG(x) || x == '*' || OPT2(x))
# define OPT2(x) (x == '-' || IS_DIGIT(x) || x == '.' || x == '#' || x == '+')
# define IS_FLOAT(x) (x == 'f' || x == 'F')
# define IS_DECIMAL(x) (x == 'd' || x == 'i')

typedef struct	s_flags
{
	short int	l;
	short int	ll;
	short int	z;
	short int	j;
	short int	cap_l;
	short int	h;
	short int	hh;
	short int	nbr_sign;
	short int	right_align;
	short int	plus_sign;
	short int	percent;
	short int	zero;
	short int	value;
	char		non_valid;
	char		conversion;
	long		prec;
	long		width;
	short int	final_sign;
	short int	space;
}				t_flags;

int				g_return_value;

int				cnt_digits(long long i, char *base);
char			*ft_var_base(int i, int base);
void			print_loop(size_t cnt, char c);
int				ft_printf(const char *restrict format, ...);
void			functions(void (*p[127])(va_list ap, t_flags flags));
void			check_type(const char *format, void (**p)(va_list ap,
				t_flags flags), va_list ap);
void			pr_putchar(char c);
void			pr_putstr(char *str);
void			pr_putnbr(long long nb);
int				ft_base_unsigned_all(uintmax_t i, char *base);
int				ft_base_signed_all(intmax_t i, char *base);
void			f_character(va_list ap, t_flags flags);
void			f_pointer(va_list ap, t_flags flags);
void			f_string(va_list ap, t_flags flags);
void			f_signed_dec(va_list ap, t_flags flags);
void			f_unsigned_dec(va_list ap, t_flags flags);
void			f_unsigned_oct(va_list ap, t_flags flags);
void			f_long_oct(va_list ap, t_flags flags);
void			f_hexadec(va_list ap, t_flags flags);
void			ftoa(float flt, int after_point);
void			f_hexadec_cap(va_list ap, t_flags flags);
void			cast_unsigned_value(uintmax_t *i, t_flags flags, va_list ap);
void			cast_signed_value(intmax_t *i, t_flags flag, va_list aps);
void			cast_float_value(long double *i, t_flags flags, va_list ap);
void			pr_putfloat(long double float_t, int prec,
				int overflow_protection);
void			f_float(va_list ap, t_flags flags);
void			width_precision(t_flags flags, int len);
void			width_right_align(t_flags flags, int len);
int				absolute_value(int i);
void			cast_float_value(long double *i, t_flags flags, va_list ap);
void			cast_signed_value(intmax_t *i, t_flags flags, va_list ap);
void			cast_unsigned_value(uintmax_t *i, t_flags flags, va_list ap);
void			set_to_zero(t_flags *flags);
void			print_format(const char *format, unsigned long *i);
void			skip_spaces(const char *format, unsigned long *i,
				t_flags *flags);
int				ft_printf(const char *restrict format, ...);
int				absolute_value(int i);
void			get_nbr_to_print(t_flags *flags, int *len, int *nbr_to_print,
				int *len_tmp);
void			adjust_length(t_flags *flags, int *len, int *len_tmp);

#endif
