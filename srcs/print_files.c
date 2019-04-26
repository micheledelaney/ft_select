/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michele <cmicheledelaney@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:54:24 by michele           #+#    #+#             */
/*   Updated: 2019/04/26 15:35:52 by michele          ###   ########.fr       */
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
			tputs(DIR_COLOR, 1, &ft_putchar_int);
	}
	if (err == -1)
		tputs(INVALID, 1, &ft_putchar_int);
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
	tputs(CLEAR_SCREEN, 1, &ft_putchar_int);
	while (files->files[++i])
	{
		tputs(RESET, 1, &ft_putchar_int);
		(i == index) ? (tputs(UNDERLINED, 1, &ft_putchar_int)) : (0);
		if (files->selected[i] != -1)
			tputs(INVERSE, 1, &ft_putchar_int);
		col = i % nbr_cols;
		row = i / nbr_cols;
		tputs(tgoto(CM, col * max_strlen, row), 1, &ft_putchar_int);
		print_color(files->files[i]);
		tputs(files->files[i], 1, &ft_putchar_int);
		tputs("\n", 1, &ft_putchar_int);
	}
	tputs(RESET, 1, &ft_putchar_int);
}
