/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:47:39 by ccodiga           #+#    #+#             */
/*   Updated: 2019/04/09 13:43:17 by michele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** function  copies  no more than n bytes from memory area src to memory area
** dest, stopping when the character c is found. Returns a pointer to that
** address.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*((unsigned char *)dst) = *((unsigned char *)src);
		if (*((unsigned char *)src) == (unsigned char)c)
			return (++dst);
		dst++;
		src++;
	}
	return (NULL);
}
