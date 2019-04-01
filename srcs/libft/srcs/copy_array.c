/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:54:47 by ccodiga           #+#    #+#             */
/*   Updated: 2019/01/14 13:01:32 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copies an array and allocates space for one more pointer than in the given
** array.
*/

char	**copy_array(char **old_array)
{
	int		i;
	char	**new_array;

	i = 0;
	while (old_array[i++])
		;
	new_array = (char **)malloc(sizeof(char *) * (i + 2));
	new_array[i] = NULL;
	while (--i >= 0)
		new_array[i] = ft_strjoin(NULL, old_array[i]);
	return (new_array);
}
