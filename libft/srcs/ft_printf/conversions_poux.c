/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_poux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 16:38:06 by ccodiga           #+#    #+#             */
/*   Updated: 2018/11/29 14:03:06 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	f_pointer(va_list ap, t_flags flags)
{
	unsigned long	address;
	int				len;

	len = 0;
	address = va_arg(ap, unsigned long);
	len = cnt_digits(address, "0123456789abcdef");
	width_precision(flags, len);
	if (flags.prec != 0)
		ft_base_unsigned_all(address, "0123456789abcdef");
	width_right_align(flags, len);
}

void	f_unsigned_oct(va_list ap, t_flags flags)
{
	uintmax_t	i;
	int			len;

	i = 0;
	(flags.conversion == 'o') ?
		(cast_unsigned_value(&i, flags, ap)) : (i = va_arg(ap, unsigned long));
	len = cnt_digits(i, "01234567");
	(i > 0) ? (flags.value = 1) : (0);
	width_precision(flags, len);
	if (!(flags.prec == 0 && i == 0))
		ft_base_unsigned_all(i, "01234567");
	width_right_align(flags, len);
}

void	f_hexadec_cap(va_list ap, t_flags flags)
{
	uintmax_t	i;
	int			len;

	i = 0;
	cast_unsigned_value(&i, flags, ap);
	len = cnt_digits(i, "0123456789ABCDEF");
	(i > 0) ? (flags.value = 1) : (0);
	width_precision(flags, len);
	if (!(flags.prec == 0 && i == 0))
		ft_base_unsigned_all(i, "0123456789ABCDEF");
	width_right_align(flags, len);
}

void	f_hexadec(va_list ap, t_flags flags)
{
	uintmax_t	i;
	int			len;

	i = 0;
	cast_unsigned_value(&i, flags, ap);
	len = cnt_digits(i, "0123456789abcdef");
	(i > 0) ? (flags.value = 1) : (0);
	width_precision(flags, len);
	if (!(flags.prec == 0 && i == 0))
		ft_base_unsigned_all(i, "0123456789abcdef");
	width_right_align(flags, len);
}

void	f_unsigned_dec(va_list ap, t_flags flags)
{
	uintmax_t	i;
	int			len;

	i = 0;
	(flags.conversion == 'u') ?
		(cast_unsigned_value(&i, flags, ap)) : (i = va_arg(ap, unsigned long));
	len = cnt_digits(i, "0123456789");
	width_precision(flags, len);
	if (!(flags.prec == 0 && i == 0))
		ft_base_unsigned_all(i, "0123456789");
	width_right_align(flags, len);
}
