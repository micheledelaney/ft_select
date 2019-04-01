/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:34:17 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/25 12:47:29 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copies the string passed as argument without the leading and trailing
** whitespaces and returns the new pointer.
*/

char	*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	char	*new;

	i = 0;
	if (s == NULL)
		return (NULL);
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s)
		s++;
	if (!(*s))
	{
		new = ft_strdup("");
		return (new);
	}
	len = ft_strlen(s);
	len--;
	while (s[len] && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len--;
	len++;
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s && len--)
		new[i++] = *s++;
	new[i] = '\0';
	return (new);
}
