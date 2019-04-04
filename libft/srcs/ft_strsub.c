/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:14:12 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/24 16:24:19 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(new = (char *)malloc(len + 1)))
		return (NULL);
	while (start--)
		s++;
	while (len--)
		new[i++] = *s++;
	new[i] = '\0';
	return (new);
}
