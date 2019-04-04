/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:45:17 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/25 11:55:53 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = -1;
	while (s[++i])
		new[i] = (*f)((unsigned int)i, s[i]);
	return (new);
}
