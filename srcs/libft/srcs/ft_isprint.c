/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:38:33 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/24 10:39:45 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** checks if the given int is pribtable. Returns 1 if it is printable, 0
** otherwise.
*/

int		ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
