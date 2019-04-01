/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:53:57 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/25 11:01:45 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** prints the number passed as argument in decimal to the given filedescriptor.
*/

void	ft_putnbr_fd(int n, int fd)
{
	long	number;
	char	c;

	number = (long)n;
	if (number < 0)
	{
		number *= -1;
		write(fd, "-", 1);
	}
	if (number < 10)
	{
		c = (char)number + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(number / 10, fd);
		ft_putnbr_fd(number % 10, fd);
	}
}
