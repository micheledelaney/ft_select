/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michele <cmicheledelaney@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:53:56 by michele           #+#    #+#             */
/*   Updated: 2019/04/09 11:53:58 by michele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

/*
** sets the variable selected of each file to -1 which evaluates to
** not selected.
*/

void	set_values(t_files *files)
{
	int i;

	i = -1;
	while (++i <= files->nbr_files)
		files->selected[i] = -1;
}

/*
** the filenames passed as argv get set to files and the number of files
** get set to argc -1.
*/

void	initialize_files(char **argv, int argc, t_files *files)
{
	files->files = &argv[1];
	files->nbr_files = argc - 1;
	files->index = 0;
	set_values(files);
	set_window_size();
}
