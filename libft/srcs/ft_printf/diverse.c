/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:11:34 by ccodiga           #+#    #+#             */
/*   Updated: 2018/11/29 15:50:21 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_signs_zero_on(t_flags flags)
{
	(flags.zero == 1 && flags.final_sign == 1) ? (pr_putchar('+')) : (0);
	(flags.zero == 1 && flags.final_sign == -1) ? (pr_putchar('-')) : (0);
	(flags.zero == 1 && flags.conversion == 'p') ? (pr_putstr("0x")) : (0);
	(flags.zero == 1 && flags.conversion == 'x' && flags.nbr_sign == 1 &&
		flags.value == 1) ? (pr_putstr("0x")) : (0);
	(flags.zero == 1 && flags.conversion == 'X' && flags.nbr_sign == 1 &&
		flags.value == 1) ? (pr_putstr("0X")) : (0);
	(flags.zero == 1 && flags.conversion == 'o' && flags.nbr_sign == 1 &&
		(flags.value == 1 || flags.prec == 0)) ? (pr_putstr("0")) : (0);
	(flags.zero == 1 && flags.conversion == 'O' && flags.nbr_sign == 1 &&
		(flags.value == 1 || flags.prec == 0)) ? (pr_putstr("0")) : (0);
}

void	print_signs_zero_off(t_flags flags)
{
	(flags.zero == 0 && flags.final_sign == 1) ? (pr_putchar('+')) : (0);
	(flags.zero == 0 && flags.final_sign == -1) ? (pr_putchar('-')) : (0);
	(flags.zero == 0 && flags.conversion == 'p') ? (pr_putstr("0x")) : (0);
	(flags.zero == 0 && flags.conversion == 'x' && flags.nbr_sign == 1 &&
		flags.value == 1) ? (pr_putstr("0x")) : (0);
	(flags.zero == 0 && flags.conversion == 'X' && flags.nbr_sign == 1 &&
		flags.value == 1) ? (pr_putstr("0X")) : (0);
	(flags.zero == 0 && flags.conversion == 'o' && flags.nbr_sign == 1 &&
		(flags.value == 1 || flags.prec == 0)) ? (pr_putstr("0")) : (0);
	(flags.zero == 0 && flags.conversion == 'O' && flags.nbr_sign == 1 &&
		(flags.value == 1 || flags.prec == 0)) ? (pr_putstr("0")) : (0);
}

void	adjust_length(t_flags *flags, int *len, int *len_tmp)
{
	*len_tmp = *len;
	if (flags->conversion == 'p' || ((flags->conversion == 'x' ||
		flags->conversion == 'X') && flags->nbr_sign == 1 && flags->value == 1))
		*len_tmp = (*len == 0) ? (3) : ((*len) + 2);
	if ((flags->conversion == 'o' || flags->conversion == 'O') &&
		flags->nbr_sign == 1 && flags->value == 1)
	{
		*len_tmp = (*len == 0) ? (1) : ((*len) + 1);
		*len += 1;
	}
	if ((flags->final_sign == 1 || flags->final_sign == -1) &&
		(flags->conversion == 'd' || flags->conversion == 'i'))
	{
		*len_tmp = (*len == 0) ? (1) : ((*len) + 1);
		(flags->prec > *len) ? (flags->width--) : (0);
	}
	if ((flags->final_sign == 0 && flags->value == 0 && flags->prec <= 1 &&
		(flags->conversion == 'd' || flags->conversion == 'i')))
		(*len_tmp) -= 1;
}

void	width_precision(t_flags flags, int len)
{
	int	nbr_to_print;
	int	len_tmp;

	get_nbr_to_print(&flags, &len, &nbr_to_print, &len_tmp);
	(flags.prec == -1) ? (flags.prec = 1) : (0);
	print_signs_zero_on(flags);
	if (((nbr_to_print) <= flags.width) && flags.right_align == 0)
	{
		if (((flags.zero == 0 || flags.prec > 1) && !IS_FLOAT(flags.
			conversion)) || (IS_FLOAT(flags.conversion) && flags.zero == 0))
			print_loop(flags.width - (nbr_to_print), ' ');
		if (flags.zero == 1 && (IS_FLOAT(flags.conversion) || flags.prec <= 1))
			print_loop(flags.width - (nbr_to_print), '0');
	}
	print_signs_zero_off(flags);
	(len == 0) ? (len = 1) : (0);
	if (len < flags.prec)
		print_loop((flags.prec - len), '0');
}

void	width_right_align(t_flags flags, int len)
{
	int nbr_to_print;

	if (flags.conversion == 'p' || (flags.conversion == 'x' &&
		flags.nbr_sign == 1))
		len = (len == 0) ? (3) : (len + 2);
	if ((flags.conversion == 'o' || flags.conversion == 'O') &&
		flags.nbr_sign == 1 && flags.value == 1)
		len = (len == 0) ? (1) : (len + 1);
	if (flags.final_sign != 0 && flags.conversion == 'd')
		len = (len == 0) ? (1) : (len + 1);
	if (flags.final_sign != 0 && flags.conversion == 'd' && flags.prec > 1)
		nbr_to_print = flags.prec + 1;
	else
		nbr_to_print = flags.prec;
	(flags.prec == -1) ? (flags.prec = 0) : (0);
	(len > flags.prec) ? (nbr_to_print = len) : (0);
	(len == 0) ? (nbr_to_print = 0) : (0);
	(flags.conversion == 'p' && len == 0) ? (nbr_to_print = 3) : (0);
	if (((nbr_to_print) <= flags.width) && flags.right_align == 1)
	{
		if (flags.zero == 0 || flags.right_align == 1)
			print_loop(flags.width - (nbr_to_print), ' ');
		if (flags.zero == 1 && flags.right_align == 0)
			print_loop(flags.width - (nbr_to_print), '0');
	}
}
