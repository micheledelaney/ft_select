/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:07:39 by ccodiga           #+#    #+#             */
/*   Updated: 2018/12/11 15:50:29 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_length(char const *str)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (IS_WHITESPACE(str[i]))
		i++;
	while (!IS_WHITESPACE(str[i]) && str[i])
	{
		i++;
		k++;
	}
	return (k);
}

static	int		count_words(char const *str)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (str[i])
	{
		if ((i == 0 && !IS_WHITESPACE(str[i])) ||
			(!IS_WHITESPACE(str[i]) && IS_WHITESPACE(str[i - 1]) && i > 0))
			ret++;
		i++;
	}
	return (ret);
}

char			**ft_strsplit_whitespace(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	**array;

	if (!s)
		return (NULL);
	if (!(array = (char **)malloc(sizeof(*array) * (count_words(s) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < count_words(s))
	{
		k = 0;
		if (!(array[i] = ft_strnew(count_length(&s[j]) + 1)))
			array[i] = NULL;
		while (IS_WHITESPACE(s[j]))
			j++;
		while (!IS_WHITESPACE(s[j]) && s[j])
			array[i][k++] = s[j++];
		array[i][k] = '\0';
	}
	array[i] = NULL;
	return (array);
}
