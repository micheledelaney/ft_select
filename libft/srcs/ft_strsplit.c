/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:07:39 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/25 14:54:56 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_length(char const *str, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i])
	{
		i++;
		k++;
	}
	return (k);
}

static	int		count_words(char const *str, char c)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (str[i])
	{
		if ((i == 0 && str[i] != c) ||
			(str[i] != c && str[i - 1] == c && i > 0))
			ret++;
		i++;
	}
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**array;

	if (!s)
		return (NULL);
	if (!(array = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < count_words(s, c))
	{
		k = 0;
		if (!(array[i] = ft_strnew(count_length(&s[j], c) + 1)))
			array[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			array[i][k++] = s[j++];
		array[i][k] = '\0';
	}
	array[i] = 0;
	return (array);
}
