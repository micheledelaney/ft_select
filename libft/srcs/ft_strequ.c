/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:49:49 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/24 16:26:13 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** checks if two strings are identical and returns 1 if they are, 0 otherwise.
*/

int	ft_strequ(char const *s1, char const *s2)
{
	int ret;

	ret = 0;
	(!s1 && !s2) ? (ret = 1) : (0);
	(s1 && s2) ? (ret = ft_strcmp(s1, s2)) : (0);
	if (ret != 0)
		return (0);
	return (1);
}
