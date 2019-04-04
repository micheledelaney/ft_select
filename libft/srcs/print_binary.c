/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:21:01 by ccodiga           #+#    #+#             */
/*   Updated: 2018/11/21 15:53:11 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** prints the binary representation of a variable in this format: 0001 1001
** as size the bit size of the variable need to get passed, for a character
** for example you need to pass 8.
*/

void	print_binary_variable(uint64_t variable, int size)
{
	int		i;
	char	hold;

	i = size;
	while (--i >= 0)
	{
		hold = 1;
		(variable & (hold << i)) ? (write(1, "1", 1)) : (write(1, "0", 1));
		(i % 4 == 0) ? (write(1, " ", 1)) : (0);
	}
}

/*
** prints the binary representation of a string.
*/

void	print_binary_string(char *message, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		print_binary_variable(message[i], 8);
}
