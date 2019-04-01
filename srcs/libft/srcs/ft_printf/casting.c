/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:10:44 by ccodiga           #+#    #+#             */
/*   Updated: 2018/11/29 15:44:21 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	cast_float_value(long double *i, t_flags flags, va_list ap)
{
	(flags.cap_l == 1) ? (*i = va_arg(ap, long double)) : (0);
	(flags.l == 1) ? (*i = va_arg(ap, double)) : (0);
	(flags.l == 0 && flags.cap_l == 0) ? (*i = (float)va_arg(ap, double)) : (0);
}

void	cast_signed_value(intmax_t *i, t_flags flags, va_list ap)
{
	(flags.l == 1) ? (*i = va_arg(ap, signed long)) : (0);
	(flags.ll == 1) ? (*i = va_arg(ap, signed long long)) : (0);
	(flags.j == 0 && flags.z == 0 && flags.ll == 0 && flags.l == 0 &&
		flags.h == 0 && flags.hh == 0) ? (*i = va_arg(ap, signed int)) : (0);
	(flags.j == 1) ? (*i = va_arg(ap, intmax_t)) : (0);
	(flags.z == 1) ? (*i = va_arg(ap, size_t)) : (0);
	(flags.h == 1) ? (*i = (short signed int)va_arg(ap, int)) : (0);
	(flags.hh == 1) ? (*i = (signed char)va_arg(ap, int)) : (0);
}

void	cast_unsigned_value(uintmax_t *i, t_flags flags, va_list ap)
{
	(flags.l == 1) ? (*i = va_arg(ap, unsigned long)) : (0);
	(flags.ll == 1) ? (*i = va_arg(ap, unsigned long long)) : (0);
	(flags.j == 0 && flags.z == 0 && flags.l == 0 && flags.ll == 0 &&
		flags.h == 0 && flags.hh == 0) ? (*i = va_arg(ap, unsigned int)) : (0);
	(flags.j == 1) ? (*i = (uintmax_t)va_arg(ap, uintmax_t)) : (0);
	(flags.z == 1) ? (*i = va_arg(ap, size_t)) : (0);
	(flags.h == 1) ? (*i = (short unsigned int)va_arg(ap, int)) : (0);
	(flags.hh == 1) ? (*i = (unsigned char)va_arg(ap, int)) : (0);
}

void	functions(void (**p)(va_list ap, t_flags flags))
{
	int i;

	i = -1;
	while (++i < 127)
		p[i] = f_character;
	p['c'] = f_character;
	p['d'] = f_signed_dec;
	p['D'] = f_signed_dec;
	p['i'] = f_signed_dec;
	p['o'] = f_unsigned_oct;
	p['O'] = f_unsigned_oct;
	p['p'] = f_pointer;
	p['U'] = f_unsigned_dec;
	p['s'] = f_string;
	p['S'] = f_string;
	p['u'] = f_unsigned_dec;
	p['x'] = f_hexadec;
	p['X'] = f_hexadec_cap;
	p['f'] = f_float;
	p['F'] = f_float;
	p['C'] = f_character;
}

void	get_nbr_to_print(t_flags *flags, int *len, int *nbr_to_print,
		int *len_tmp)
{
	adjust_length(flags, len, len_tmp);
	if (!IS_FLOAT(flags->conversion))
	{
		*nbr_to_print = flags->prec;
		(*len_tmp > flags->prec) ? (*nbr_to_print = *len_tmp) : (0);
	}
	else
	{
		*nbr_to_print = *len;
		(flags->final_sign != 0) ? ((*nbr_to_print)++) : (0);
	}
}
