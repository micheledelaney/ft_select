/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:50:08 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/25 13:11:54 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && j <= len)
	{
		i = 0;
		while (haystack[i] == needle[i] && haystack[i] && needle[i] && (i + j)
			< len)
			i++;
		if (i == ft_strlen(needle))
			return ((char *)haystack);
		haystack++;
		j++;
	}
	return (NULL);
}
