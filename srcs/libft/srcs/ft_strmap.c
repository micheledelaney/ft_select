/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:31:51 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/25 13:08:20 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	while (*s)
		new[i++] = (*f)(*s++);
	new[i] = '\0';
	return (new);
}
