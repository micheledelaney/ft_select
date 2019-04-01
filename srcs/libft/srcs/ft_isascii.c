/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:29:25 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/24 10:32:06 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** checks if a given character is an ascii character and returns 0 if it is, 0
** otherwise.
*/

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}
