#include "../includes/ft_select.h"

void	print_selected(t_files *files)
{
	int		i;
	bool	printed;

	i = -1;
	printed = false;
	while (files->files[++i])
	{
		if (files->selected[i] != -1)
		{
			ft_putstr_fd(files->files[i], STDOUT_FILENO);
			ft_putstr_fd(" ", STDOUT_FILENO);
			printed = true;
		}
	}
	(printed == true) ? (ft_putstr_fd("\n", STDOUT_FILENO)) : (0);
	free(files->selected);
}
