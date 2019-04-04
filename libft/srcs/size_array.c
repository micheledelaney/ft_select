/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:03:28 by ccodiga           #+#    #+#             */
/*   Updated: 2019/01/15 14:05:18 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** iterates through the array and returns i when it reaches the last element.
*/

size_t		size_array(char **array)
{
	int i;

	i = -1;
	while (array[++i])
		;
	return (i);
}
