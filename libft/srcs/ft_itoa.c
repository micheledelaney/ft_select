/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:26:02 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/25 11:40:29 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** converts a given number into the string representation of it and returns
** the string.
*/

char	*ft_itoa(int n)
{
	int		i;
	long	number;
	char	*result;
	int		z;
	long	tmp;

	i = 0;
	z = 1;
	if (n < 0)
	{
		z = -1;
		i++;
	}
	number = (long)n;
	number *= z;
	tmp = number;
	while (number /= 10)
		i++;
	if (!(result = ft_strnew(i + 1)))
		return (NULL);
	result[i--] = (tmp % 10) + 48;
	while (tmp /= 10)
		result[i--] = (tmp % 10) + 48;
	(z == -1) ? (result[0] = '-') : (0);
	return (result);
}
