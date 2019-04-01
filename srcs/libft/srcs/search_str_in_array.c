/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_str_in_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:05:35 by ccodiga           #+#    #+#             */
/*   Updated: 2019/01/10 10:36:27 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** searches through each element of the array of strings and checks, if one
** one those strings contains the string given as argument. The strings doesn't
** need to be exactly the same in order to return a positive value. The string
** passed needs to be at least a substrinng of one of the strings in the array.
** returns the index of the string, otherwise -1.
*/

int	search_str_in_array(char **array, char *string)
{
	int	i;

	i = -1;
	while (array[++i] != NULL)
	{
		if (ft_strstr_index(array[i], string) == 0)
			return (i);
	}
	return (-1);
}
