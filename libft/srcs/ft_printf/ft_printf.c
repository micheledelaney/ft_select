/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 16:28:54 by ccodiga           #+#    #+#             */
/*   Updated: 2018/12/07 10:42:24 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	void	(*p[127])(va_list ap, t_flags flags);

	g_return_value = 0;
	va_start(ap, format);
	functions(p);
	if (*format)
		check_type(format, p, ap);
	va_end(ap);
	return (g_return_value);
}

void	check_flags(const char *format, unsigned long *i, t_flags *flags)
{
	(format[*i] == 'l' && format[(*i) + 1] == 'l') ? (flags->ll = 1) : (0);
	(format[*i] == 'l' && format[(*i) + 1] != 'l') ? (flags->l = 1) : (0);
	(format[*i] == 'h' && format[(*i) + 1] == 'h') ? (flags->hh = 1) : (0);
	(format[*i] == 'h' && format[(*i) + 1] != 'h') ? (flags->h = 1) : (0);
	(format[*i] == 'L') ? (flags->cap_l = 1) : (0);
	(format[*i] == 'j') ? (flags->j = 1) : (0);
	(format[*i] == 'z') ? (flags->z = 1) : (0);
	while (IS_FLAG(format[*i]))
		(*i)++;
}

int		check_width_prec(unsigned long *i, va_list ap, const char *format)
{
	long long nbr;

	nbr = 0;
	if (format[*i] == '*')
	{
		(*i)++;
		nbr = va_arg(ap, long long);
	}
	if (ft_isdigit(format[*i]))
		nbr = ft_atoi(&format[*i]);
	while (ft_isdigit(format[*i]))
		(*i)++;
	return (nbr);
}

void	check_conditions(const char *format, unsigned long *i, t_flags *flags,
		va_list ap)
{
	while (format[*i] && !IS_CONVERSION(format[*i]) && OPT(format[*i]))
	{
		if (format[*i] == '#' || format[*i] == '-' || format[*i] == '+')
		{
			(format[*i] == '#') ? (flags->nbr_sign = 1) : (0);
			(format[*i] == '+') ? (flags->plus_sign = 1) : (0);
			(format[*i] == '-') ? (flags->right_align = 1) : (0);
			(*i)++;
		}
		(format[*i] == '0') ? (flags->zero = 1) : (0);
		flags->width = check_width_prec(i, ap, format);
		if (flags->width < 0)
		{
			flags->width *= -1;
			flags->right_align = 1;
		}
		if (format[*i] == '.')
			(*i)++;
		if (format[(*i) - 1] == '.')
			flags->prec = check_width_prec(i, ap, format);
		while (ft_isdigit(format[*i]))
			(*i)++;
		if (format[*i] && IS_FLAG(format[*i]))
			check_flags(format, i, flags);
	}
}

void	check_type(const char *format, void (**p)(va_list ap, t_flags flags),
		va_list ap)
{
	unsigned long	i;
	t_flags			flags;

	i = 0;
	while (format[i])
	{
		print_format(format, &i);
		if (format[i] == '%')
		{
			i++;
			set_to_zero(&flags);
			skip_spaces(format, &i, &flags);
			check_conditions(format, &i, &flags, ap);
			skip_spaces(format, &i, &flags);
			if (IS_CONVERSION(format[i]) && format[i])
				flags.conversion = format[i];
			if (!IS_CONVERSION(format[i]) && format[i])
				flags.non_valid = format[i];
			(format[i]) ? (p[(int)(format[i])](ap, flags)) : (0);
			(format[i]) ? (i++) : (0);
		}
	}
}
