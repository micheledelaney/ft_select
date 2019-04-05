#include "../includes/ft_select.h"

void	set_values(t_files *files)
{
	int i;

	i = -1;
	while (++i <= files->nbr_files)
		files->selected[i] = -1;
}

void	initialize_files(char **argv, int argc, t_files *files)
{
	files->files = &argv[1];
	files->nbr_files = argc - 1;
	files->index = 0;
	set_values(files);
	set_window_size();
}
