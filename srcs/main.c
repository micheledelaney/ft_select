/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michele <cmicheledelaney@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:54:12 by michele           #+#    #+#             */
/*   Updated: 2019/04/09 13:32:21 by michele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static bool	check_input(int argc, char **argv)
{
	bool real;

	real = false;
	if (!(ft_strcmp(argv[1], "-r")) ||
			!(ft_strcmp(argv[1], "--real")))
		real = true;
	if (argc < 2 || (argc == 2 && real))
	{
		ft_putstr_fd("Usage: ./ft_select [filename/s]\n", STDERR_FILENO);
		exit(0);
	}
	return (real);
}

int			main(int argc, char **argv)
{
	t_files	files;
	int		key;
	int		nbr_cols;

	files.real = check_input(argc, argv);
	if (!(files.selected = (int *)malloc(sizeof(int) * (argc - 1))))
		return (-1);
	set_term_configuration();
	signal_handler();
	initialize_files(argv, argc, &files);
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
