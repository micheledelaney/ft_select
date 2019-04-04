#include "../includes/ft_select.h"

void	print_selected(t_files *files)
{
	int i;

	i = -1;
	while (files->files[++i])
	{
		if (files->selected[i] != -1)
		{
			ft_putstr_fd(files->files[i], STDOUT_FILENO);
			ft_putstr_fd(" ", STDOUT_FILENO);
		}
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
	free(files->selected);
}
