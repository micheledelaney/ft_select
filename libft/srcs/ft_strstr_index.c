/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:25:30 by ccodiga           #+#    #+#             */
/*   Updated: 2019/01/11 09:58:33 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstr_index(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (*needle == '\0')
		return (ft_strlen(haystack));
	while (*haystack)
	{
		i = 0;
		while (haystack[i] == needle[i] && haystack[i] && needle[i])
			i++;
		if (i == ft_strlen(needle))
			return (j);
		haystack++;
		j++;
	}
	return (-1);
}
