#include "../includes/ft_select.h"

int		read_key(void)
{
	int	buf;

	buf = 0;
	if (read(STDERR_FILENO, &buf, 8) < 0)
		perror ("read()");
	return (buf);
}

void	process_key(int key, int *index, int nbr_cols, t_files *files)
{
	if (key == UP)
		*index -= nbr_cols;
	if (key == DOWN)
		*index += nbr_cols;
	if (key == RIGHT)
		(*index)++;
	if (key == LEFT)
		(*index)--;
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
	if (*index >= files->nbr_files)
		*index = 0;
	if (*index < 0)
		*index = files->nbr_files - 1;
}
