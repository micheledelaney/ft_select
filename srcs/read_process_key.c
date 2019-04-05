#include "../includes/ft_select.h"

int		read_key(void)
{
	int	buf;

	buf = 0;
	if (read(STDERR_FILENO, &buf, 8) < 0)
		perror ("read()");
	return (buf);
}

void	move_down_in_array(t_files *files, int index)
{
	while (index < files->nbr_files + 1){
		files->files[index] = files->files[index + 1];
		index++;
	}
	files->nbr_files--;
}

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
		(files->real) ? (remove(files->files[files->index])) : (0);
		move_down_in_array(files, files->index);
	}
	(*index >= files->nbr_files) ? (*index = 0) : (0);
	(*index < 0) ? (*index = files->nbr_files - 1) : (0);
}
