/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 16:23:32 by ccodiga           #+#    #+#             */
/*   Updated: 2018/12/07 10:41:56 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	pr_putchar(char c)
{
	write(1, &c, 1);
	g_return_value++;
}

void	print_loop(size_t cnt, char c)
{
	size_t i;

	i = 0;
	while (i++ < cnt)
		pr_putchar(c);
}

void	pr_putstr(char *str)
{
	int				len;

	len = 0;
	(str != NULL) ? (len = ft_strlen(str)) : (0);
	if (str == NULL)
	{
		pr_putstr("(null)");
		return ;
	}
	write(1, str, len);
	g_return_value += len;
}

int		ft_base_unsigned_all(uintmax_t i, char *base)
{
	int		result[64];
	int		cnt;
	int		basenbr;

	basenbr = 0;
	while (base[basenbr])
		basenbr++;
	cnt = 0;
	if (i == 0)
		pr_putchar(i + '0');
	while (i != 0)
	{
		result[cnt++] = absolute_value(i % basenbr);
		i = i / basenbr;
	}
	cnt--;
	while (cnt >= 0)
		pr_putchar(base[result[cnt--]]);
	return (0);
}

int		ft_base_signed_all(intmax_t i, char *base)
{
	int		result[64];
	int		cnt;
	int		basenbr;

	basenbr = 0;
	while (base[basenbr])
		basenbr++;
	cnt = 0;
	if (i == 0)
		pr_putchar(i + '0');
	while (i != 0)
	{
		result[cnt++] = absolute_value(i % basenbr);
		i = i / basenbr;
	}
	cnt--;
	while (cnt >= 0)
		pr_putchar(base[result[cnt--]]);
	return (0);
}
