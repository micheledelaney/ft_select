/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:12:33 by ccodiga           #+#    #+#             */
/*   Updated: 2018/11/29 14:33:36 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		absolute_value(int i)
{
	if (i < 0)
		return (i * -1);
	else
		return (i);
}

void	skip_spaces(const char *format, unsigned long *i, t_flags *flags)
{
	if (format[(*i) - 1] == '%' && format[*i] == ' ')
		flags->space = 1;
	while (format[*i] == ' ')
		(*i)++;
}

void	print_format(const char *format, unsigned long *i)
{
	while (format[*i] != '%' && format[*i])
		pr_putchar(format[(*i)++]);
}

void	set_to_zero(t_flags *flags)
{
	flags->l = 0;
	flags->ll = 0;
	flags->cap_l = 0;
	flags->h = 0;
	flags->z = 0;
	flags->j = 0;
	flags->hh = 0;
	flags->prec = -1;
	flags->width = 0;
	flags->nbr_sign = 0;
	flags->right_align = 0;
	flags->percent = 0;
	flags->zero = 0;
	flags->final_sign = 0;
	flags->plus_sign = 0;
	flags->space = 0;
	flags->non_valid = 0;
	flags->value = 0;
	flags->conversion = 0;
}
