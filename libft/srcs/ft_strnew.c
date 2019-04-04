/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:59:11 by ccodiga           #+#    #+#             */
/*   Updated: 2019/01/15 13:29:11 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!(ptr = (void *)malloc(size + 1)))
		return (NULL);
	while (i <= size)
		((unsigned char *)ptr)[i++] = '\0';
	return (ptr);
}
