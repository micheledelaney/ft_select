/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:04:35 by ccodiga           #+#    #+#             */
/*   Updated: 2019/01/14 17:06:42 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** frees each pointer in the array and the pointer to the array itself.
*/

void	free_array(char **array)
{
	int i;

	i = -1;
	while (array[++i] != NULL)
		free(array[i]);
	free(array);
}
