/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michele <cmicheledelaney@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:54:24 by michele           #+#    #+#             */
/*   Updated: 2019/04/09 13:34:09 by michele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

struct winsize	g_window_size;

/*
** the ioctl function sets the windowsize in the global struct
** g_window_size.
*/

void	set_window_size(void)
{
	ioctl(STDERR_FILENO, TIOCGWINSZ, &g_window_size);
}

/*
** iterates through the passed char **array and returns the strlen
** of the longest string. the second and third variable define the
** sub array which to iterate through.
*/

int		get_max_strlen(char **array)
{
	int	max;
	int	len;
	int	i;

	max = 0;
	i = -1;
	while (array[++i])
	{
		len = ft_strlen(array[i]);
		max = (len > max) ? (len) : (max);
	}
	return (max + 1);
}

/*
** calculates how many columns fit into the screen based on the
** screensize from g_window_size and the max_strlen. Every column
** is as wide as the max_strlen.
*/

int		get_nbr_cols(t_files *files)
{
	int max_strlen;
	int nbr_cols;
	int width;

	nbr_cols = 0;
	max_strlen = get_max_strlen(files->files);
	width = max_strlen;
	while (width <= g_window_size.ws_col)
	{
		width += max_strlen;
		nbr_cols++;
	}
	return (nbr_cols);
}

/*
** prints the colors for the files. first it checks if the filename passed
** is a directory and if they are valid files. if so, the right color gets
** printed. in the last part the files gets checked for its ending to
** print the right color.
*/

void	print_color(char *file)
{
	struct stat	s;
	int			err;

	err = stat(file, &s);
	if (err != -1)
	{
		if (S_ISDIR(s.st_mode))
			ft_putstr_fd(DIR_COLOR, STDERR_FILENO);
	}
	if (err == -1)
		ft_putstr_fd(INVALID, STDERR_FILENO);
}

/*
** iterates through the array of files and prints them. if the file is either
** selected or the current cursor file the right formatting gets printed.
** goto moves to the right columns to continue printing the files.
*/

void	print_filenames(t_files *files, int index, int nbr_cols)
{
	int	i;
	int	row;
	int	col;
	int	max_strlen;

	i = -1;
	if ((nbr_cols * g_window_size.ws_row) < files->nbr_files)
		return ;
	max_strlen = get_max_strlen(files->files);
	ft_putstr_fd(CLEAR_SCREEN, 0);
	while (files->files[++i])
	{
		ft_putstr_fd(RESET, STDERR_FILENO);
		(i == index) ? (ft_putstr_fd(UNDERLINED, STDERR_FILENO)) : (0);
		if (files->selected[i] != -1)
			ft_putstr_fd(INVERSE, STDERR_FILENO);
		col = i % nbr_cols;
		row = i / nbr_cols;
		ft_putstr_fd(tgoto(CM, col * max_strlen, row), 0);
		print_color(files->files[i]);
		ft_putstr_fd(files->files[i], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	ft_putstr_fd(RESET, STDERR_FILENO);
}
