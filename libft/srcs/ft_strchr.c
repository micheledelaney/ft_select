/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:54:39 by ccodiga           #+#    #+#             */
/*   Updated: 2018/09/17 11:21:21 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (s[i])
	{
		if (s[i] == c)
		{
			str = (char *)&s[i];
			return (str);
		}
		i++;
	}
	if (s[i] == c)
	{
		str = (char *)&s[i];
		return (str);
	}
	return (NULL);
}
