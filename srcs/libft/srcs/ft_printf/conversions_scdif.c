/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_scdi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:10:57 by ccodiga           #+#    #+#             */
/*   Updated: 2018/12/07 10:42:11 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	f_float(va_list ap, t_flags flags)
{
	long double	float_i;
	long		len;

	float_i = 0;
	float_i = va_arg(ap, double);
	len = cnt_digits((long)float_i, "0123456789");
	(len == 0) ? (len = 1) : (0);
	len += ((flags.prec != 0) ? (1) : (0)) + ((flags.prec == -1) ? (6) :
			(flags.prec));
	(flags.plus_sign == 1) ? (flags.final_sign = 1) : (0);
	(float_i < 0) ? (flags.final_sign = -1) : (0);
	if (!flags.nbr_sign && !flags.plus_sign && !flags.right_align && flags.space
		== 1 && float_i >= 0)
	{
		pr_putchar(' ');
		flags.width--;
	}
	width_precision(flags, len);
	if (flags.prec == -1)
		flags.prec = 6;
	(float_i < 0) ? (float_i *= -1) : (0);
	pr_putfloat(float_i, flags.prec, 0);
	(flags.final_sign != 0) ? (len++) : (0);
	width_right_align(flags, len);
}

void	f_character(va_list ap, t_flags flags)
{
	unsigned int c;

	c = '%';
	(flags.non_valid != 0) ? (c = flags.non_valid) : (0);
	if (flags.percent == 0 && flags.non_valid == 0)
		c = va_arg(ap, unsigned int);
	if (flags.width > 1 && flags.right_align == 0)
		(flags.zero == 0) ? (print_loop((flags.width - 1), ' ')) :
							(print_loop((flags.width - 1), '0'));
	pr_putchar(c);
	width_right_align(flags, 1);
}

void	f_string(va_list ap, t_flags flags)
{
	char	*str;
	int		strlen;

	strlen = 0;
	str = ft_strdup(va_arg(ap, char *));
	(str != NULL) ? (strlen = ft_strlen(str)) : (0);
	if (flags.prec >= 0 && (flags.prec < strlen))
		str[flags.prec] = '\0';
	(str != NULL) ? (strlen = ft_strlen(str)) : (0);
	if (flags.width > strlen && flags.right_align == 0)
	{
		if (flags.zero == 0 && str != NULL)
			print_loop((flags.width - strlen), ' ');
		(flags.zero == 1) ? (print_loop((flags.width - strlen), '0')) : (0);
	}
	(flags.zero == 1 && str == NULL) ? (0) : (pr_putstr(str));
	width_right_align(flags, strlen);
	free(str);
}

void	f_long_signed_dec(va_list ap, t_flags flags)
{
	intmax_t	dec;
	int			len;

	dec = 0;
	dec = va_arg(ap, signed long);
	if (flags.space == 1 && flags.plus_sign == 0 && dec >= 0 && flags.prec < 0)
	{
		pr_putchar(' ');
		flags.width--;
	}
	(flags.prec == -1) ? (flags.prec = 1) : (0);
	len = cnt_digits(dec, "0123456789");
	(flags.plus_sign == 1 && dec >= 0) ? (flags.final_sign = 1) : (0);
	(dec < 0) ? (flags.final_sign = -1) : (0);
	len = (len <= 0) ? (1) : (len);
	width_precision(flags, len);
	if (!(flags.prec == 0 && dec == 0))
		(ft_base_signed_all(dec, "0123456789"));
	width_right_align(flags, len);
}

void	f_signed_dec(va_list ap, t_flags flags)
{
	intmax_t	dec;
	int			len;

	dec = 0;
	(flags.conversion == 'd' || flags.conversion == 'i') ?
		(cast_signed_value(&dec, flags, ap)) : (dec = va_arg(ap, signed long));
	(dec > 0) ? (flags.value = 1) : (0);
	(dec < 0) ? (flags.value = 1) : (0);
	if (!flags.nbr_sign && !flags.plus_sign && !flags.right_align && flags.space
		== 1 && dec >= 0 && (flags.prec < 0 || flags.prec > flags.width))
	{
		pr_putchar(' ');
		flags.width--;
	}
	(flags.prec == -1) ? (flags.prec = 1) : (0);
	len = cnt_digits(dec, "0123456789");
	(flags.plus_sign == 1 && dec >= 0) ? (flags.final_sign = 1) : (0);
	(dec < 0) ? (flags.final_sign = -1) : (0);
	len = (len <= 0) ? (1) : (len);
	width_precision(flags, len);
	if (!(flags.prec == 0 && dec == 0))
		ft_base_signed_all(dec, "0123456789");
	width_right_align(flags, len);
}
