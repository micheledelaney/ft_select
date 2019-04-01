/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:44:34 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/25 13:56:34 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *ptr;

	ptr = dst;
	if (dst == src)
		return (dst);
	else if (dst > src)
	{
		src += len - 1;
		dst += len - 1;
		while (len--)
			*((unsigned char *)dst--) = *((unsigned char *)src--);
	}
	else
	{
		while (len--)
			*((unsigned char *)dst++) = *((unsigned char *)src++);
	}
	return (ptr);
}
