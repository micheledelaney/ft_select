/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:52:25 by ccodiga           #+#    #+#             */
/*   Updated: 2018/11/29 16:51:53 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned long long	power_base_ten(int nbr)
{
	unsigned long long ten;

	ten = 10;
	while (nbr--)
		ten *= 10;
	return (ten);
}

int					prec_zero(unsigned long long hold, long double float_i,
					int prec)
{
	if (prec == 0)
	{
		hold = float_i * 10;
		if (hold % 10 >= 5 && (hold / 10) % 2 == 0 && (int)float_i != 0)
		{
			ft_base_unsigned_all(((hold / 10)), "0123456789");
			return (-1);
		}
		else if (hold % 10 >= 5 && (((hold / 10) % 2 != 0 ||
			(int)float_i == 0)))
		{
			ft_base_unsigned_all(((hold / 10) + 1), "0123456789");
			return (-1);
		}
		else
		{
			ft_base_unsigned_all(((hold / 10)), "0123456789");
			return (-1);
		}
	}
	return (0);
}

void				pr_putfloat(long double float_i, int prec,
					int overflow_protection)
{
	int					cnt;
	unsigned long long	hold;

	overflow_protection = (prec > 18) ? (prec - 18) : (0);
	(prec > 18) ? (prec = 18) : (0);
	cnt = 0;
	if (prec_zero(hold = 0, float_i, prec) == -1)
		return ;
	float_i = float_i * power_base_ten(prec);
	hold = float_i;
	float_i /= 10;
	(hold % 10 >= 5) ? (float_i += 1) : (0);
	float_i /= power_base_ten(prec - 1);
	ft_base_unsigned_all((uintmax_t)float_i, "0123456789");
	pr_putchar('.');
	float_i = float_i - (uintmax_t)float_i;
	hold = float_i * power_base_ten(prec - 1);
	while ((float_i < 1 || (uintmax_t)float_i % 10 != 0) && ++cnt < prec)
	{
		float_i *= 10;
		if ((int)float_i == 0)
			pr_putchar('0');
	}
	ft_base_unsigned_all(hold, "0123456789");
	(overflow_protection != 0) ? (print_loop(overflow_protection, '0')) : (0);
}
