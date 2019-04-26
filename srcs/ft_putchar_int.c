/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michele <cmicheledelaney@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 12:40:23 by michele           #+#    #+#             */
/*   Updated: 2019/04/26 15:37:04 by michele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

/*
** version of putchar that is compatible with the fucntion tputs needs.
*/

int	ft_putchar_int(int c)
{
	return (write(STDERR_FILENO, &c, 1));
}
