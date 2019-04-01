/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:07:58 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/25 10:13:11 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** prints the string to the standard outpout.
*/

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}
