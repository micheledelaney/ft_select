/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:50:34 by ccodiga           #+#    #+#             */
/*   Updated: 2019/01/15 13:50:52 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** gets as parameters the address of a char pointer, a subbstring that needs to
** get replaced and the string this substring needs to get replaced with.
** replaces said substring. if the replacement is NULL, the to_replace string
** gets deleted out of the string and it gets not replaced with anything.
** if one of the other arguments are NULL the function returns.
*/

void	replace(char **string, char *to_replace, char *replacement)
{
	size_t	start;
	size_t	end;
	size_t	length;
	char	*hold;
	char	*replaced;

	if (*string == NULL || to_replace == NULL ||
		ft_strstr(*string, to_replace) == NULL)
		return ;
	length = ft_strlen(to_replace);
	start = ft_strstr_index(*string, to_replace);
	end = start + length;
	replaced = ft_strsub(*string, 0, start);
	hold = replaced;
	replaced = ft_strjoin(replaced, replacement);
	free(hold);
	hold = replaced;
	replaced = ft_strjoin(replaced, &(*string)[end]);
	free(hold);
	hold = *string;
	*string = replaced;
	free(hold);
}
