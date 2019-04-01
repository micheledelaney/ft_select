/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 17:02:26 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/25 13:07:16 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** appends dstsize bytes of src to dst. be sure to allocate enough memory for
** dst.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		ret;

	((int)dstsize < 0) ? (dstsize = ft_strlen(dst) + ft_strlen(src) + 1) : (0);
	((ft_strlen(src) + dstsize) < (ft_strlen(dst) + ft_strlen(src))) ? (ret =
		ft_strlen(src) + dstsize) : (ret = ft_strlen(dst) + ft_strlen(src));
	if (((int)dstsize - (int)ft_strlen(dst) - 1) > 0)
		ft_strncat(dst, src, dstsize - ft_strlen(dst) - 1);
	return (ret);
}
