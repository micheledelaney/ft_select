/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 09:59:13 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/26 09:59:14 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while ((*alst)->next)
	{
		del((*alst)->content, (*alst)->content_size);
		(*alst)->content_size = 0;
		*alst = (*alst)->next;
	}
	del((*alst)->content, (*alst)->content_size);
	(*alst)->content_size = 0;
	ft_memdel((void**)alst);
}
