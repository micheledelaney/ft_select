/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:50:44 by ccodiga           #+#    #+#             */
/*   Updated: 2018/09/17 11:20:48 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** checks if a given character is a digit and returns 1 if it is, 0 otherwise.
*/

int	ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}
