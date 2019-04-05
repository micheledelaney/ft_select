#include "../includes/ft_select.h"

bool	check_realmode(t_files *files)
{
	if (!(ft_strcmp(files->files[0], "-r")) || !(ft_strcmp(files->files[0], "--real")))
	{
		files->files = &(files->files[1]);
		return true;
	}
	files->nbr_files--;
	return false;
}

void	move_down_in_array(t_files *files, int index)
{
	while (index < files->nbr_files + 1){
		files->files[index] = files->files[index + 1];
		index++;
	}
	files->nbr_files--;
}

int		main(int argc, char **argv)
{
	t_files	files;
	int		key;
	int		nbr_cols;
	bool	real;

	if (argc < 2)
		return (0);
	if (!(files.selected = (int *)malloc(sizeof(int) * (argc - 1))))
		return (-1);
	set_term_configuration();
	signal_handler();
	initialize_files(argv, argc, &files);
	real = check_realmode(&files);
	set_window_size();
	update_files(&files);
	key = 0;
	while (key != ESC && key != ENR)
	{
		if (((key == DEL) || (key == BCKSP)) && real)
		{
			remove(files.files[files.index]);
			move_down_in_array(&files, files.index);
		}
		nbr_cols = get_nbr_cols(&files);
		process_key(key, &files.index, nbr_cols, &files);
		ft_putstr_fd(CLEAR_SCREEN, 0);
		print_filenames(&files, files.index, nbr_cols);
		key = read_key();
	}
	reset_term_configuration();
	(key == ENR) ? (print_selected(&files)) : (0);
	free(files.selected);
	return (0);
}
