/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:51:28 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/25 13:10:31 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** writes the string to the given filedescriptor.
*/

void	ft_putstr_fd(char const *s, int fd)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}
