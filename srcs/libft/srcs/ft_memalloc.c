/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:33:38 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/25 13:02:50 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** allocates memoryspace of the given size and sets it to zero.
*/

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	if (!(ptr = (void *)malloc(size)))
		return (NULL);
	while (i <= size)
		((unsigned char *)ptr)[i++] = '\0';
	return (ptr);
}
