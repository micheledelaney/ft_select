/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_process_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michele <cmicheledelaney@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:53:27 by michele           #+#    #+#             */
/*   Updated: 2019/04/09 11:54:53 by michele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

/*
** reads the key hit by the user into an 32 bit int and returns that int.
*/

int		read_key(void)
{
	int	buf;

	buf = 0;
	if (read(STDERR_FILENO, &buf, 8) < 0)
		perror("read()");
	return (buf);
}

/*
** moves the elements in the array one down starting at index.
** does not free!
*/

void	move_down_in_array(t_files *files, int index)
{
	while (index < files->nbr_files + 1)
	{
		files->files[index] = files->files[index + 1];
		index++;
	}
	files->nbr_files--;
}

/*
** removes the passed file from disk if it is an existent file. if it
** is a directory it removes its content recursively and removes the
** directory itself.
*/

void	remove_it(const char *path)
{
	struct stat		s;
	DIR				*dir;
	struct dirent	*de;
	char			real_path[PATH_MAX + 1];

	if ((dir = opendir(path)) != NULL)
	{
		while ((de = readdir(dir)) != NULL)
		{
			ft_strcpy(real_path, path);
			ft_strcat(real_path, "/");
			ft_strcat(real_path, de->d_name);
			if (!ft_strcmp(de->d_name, ".") || !ft_strcmp(de->d_name, ".."))
				continue;
			if (!stat(real_path, &s))
			{
				if (S_ISDIR(s.st_mode))
					remove_it(real_path);
				else
					remove(real_path);
			}
		}
		closedir(dir);
	}
	remove(path);
}

/*
** processes the key entered by the user. Depending on which key got hit
** the index (for keeping track of which file needs to get printed underlined)
** changes its value. if in real mode and the key is DEL the remove_it function
** gets called.
*/

void	process_key(int key, int *index, int nbr_cols, t_files *files)
{
	(key == UP) ? (*index -= nbr_cols) : (0);
	(key == DOWN) ? (*index += nbr_cols) : (0);
	(key == RIGHT) ? ((*index)++) : (0);
	(key == LEFT) ? ((*index)--) : (0);
	(key == 'r') ? (set_values(files)) : (0);
	if (key == SPC)
	{
		if (files->selected[*index] == -1)
		{
			files->selected[*index] = *index;
			(*index)++;
		}
		else
			files->selected[*index] = -1;
	}
	if ((key == DEL) || (key == BCKSP))
	{
		(files->real) ? (remove_it(files->files[files->index])) : (0);
		move_down_in_array(files, files->index);
	}
	(*index >= files->nbr_files) ? (*index = 0) : (0);
	(*index < 0) ? (*index = files->nbr_files - 1) : (0);
}
