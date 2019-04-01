/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:00:10 by ccodiga           #+#    #+#             */
/*   Updated: 2018/10/26 10:00:14 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	if (!(res = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(res->content = (t_list*)malloc(sizeof(content) * content_size)))
		return (NULL);
	if (content == NULL)
	{
		res->content = NULL;
		res->content_size = 0;
		res->next = NULL;
	}
	else
	{
		res->content = ft_memcpy(res->content, content, content_size);
		res->content_size = content_size;
		res->next = NULL;
	}
	return (res);
}
