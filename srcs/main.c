/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michele <cmicheledelaney@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:54:12 by michele           #+#    #+#             */
/*   Updated: 2019/04/09 12:17:29 by ccodiga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

/*
** checks if realmode is on, which gets passed as argv ("-r", "--real")
*/

static bool	check_realmode(t_files *files)
{
	if (!(ft_strcmp(files->files[0], "-r")) ||
			!(ft_strcmp(files->files[0], "--real")))
	{
		files->files = &(files->files[1]);
		files->nbr_files--;
		return (true);
	}
	return (false);
}

int			check_valid_input(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("Usage: ./ft_select [filename/s]\n", STDERR_FILENO);
		return (0);
	}
	if (argc == 2 && (!(ft_strcmp(argv[1], "-r")) ||
					!(ft_strcmp(argv[1], "--real"))))
	{
		ft_putstr_fd("Usage: ./ft_select [filename/s]\n", STDERR_FILENO);
		return (0);
	}
	else
		return (1);
}

int			main(int argc, char **argv)
{
	t_files	files;
	int		key;
	int		nbr_cols;

	if (!(check_valid_input(argc, argv)))
		return (0);
	if (!(files.selected = (int *)malloc(sizeof(int) * (argc - 1))))
		return (-1);
	set_term_configuration();
	signal_handler();
	initialize_files(argv, argc, &files);
	files.real = check_realmode(&files);
	update_files(&files);
	key = 0;
	while (key != ESC && key != ENR)
	{
		nbr_cols = get_nbr_cols(&files);
		process_key(key, &files.index, nbr_cols, &files);
		print_filenames(&files, files.index, nbr_cols);
		if (files.files[0] == NULL)
			break ;
		key = read_key();
	}
	reset_term_configuration();
	(key == ENR) ? (print_selected(&files)) : (0);
	free(files.selected);
	return (0);
}
