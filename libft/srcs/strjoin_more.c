/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:03:19 by ccodiga           #+#    #+#             */
/*   Updated: 2019/01/16 11:21:35 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** takes a number of arguments (nbr_param), allocates the needed memoryspace
** and joins the strings passed as arguments. returns a pointer to that
** new memory address.
*/

char	*copying_str(char **strings, int length)
{
	int		i;
	int		j;
	int		k;
	char	*result_str;

	i = -1;
	k = -1;
	result_str = (char *)ft_strnew(sizeof(char) * (length + 1));
	while (strings[++i] != NULL)
	{
		j = -1;
		while (strings[i][++j] != '\0')
			result_str[++k] = strings[i][j];
	}
	result_str[++k] = '\0';
	return (result_str);
}

char	*strjoin_more(int nbr_param, ...)
{
	va_list	ap;
	char	**strings;
	int		i;
	int		length;
	char	*result_str;

	strings = (char **)malloc(sizeof(char *) * (nbr_param + 1));
	strings[nbr_param] = NULL;
	va_start(ap, nbr_param);
	i = -1;
	length = 0;
	while (++i < nbr_param)
	{
		strings[i] = ft_strdup(va_arg(ap, char *));
		length += ft_strlen(strings[i]);
	}
	result_str = copying_str(strings, length);
	free_array(strings);
	va_end(ap);
	return (result_str);
}
