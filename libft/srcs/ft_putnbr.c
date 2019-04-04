/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:18:03 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/25 10:48:03 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** prints the number given as arguments in decimal.
*/

void	ft_putnbr(int n)
{
	long	number;
	char	c;

	number = n;
	if (number < 0)
	{
		number *= -1;
		write(1, "-", 1);
	}
	if (number < 10)
	{
		c = (char)number + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(number / 10);
		ft_putnbr(number % 10);
	}
}
