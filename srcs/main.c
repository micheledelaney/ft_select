#include "../includes/ft_select.h"

void	exit_program(int signum)
{
	(void)signum;
	reset_term_configuration();
	exit(-1);
}

int		main(int argc, char **argv)
{
	t_files	files;
	int		key;
	int		nbr_cols;

	if (argc < 2)
		return (0);
	if (!(files.selected = (int *)malloc(sizeof(int) * (argc - 1))))
		return (-1);
	set_term_configuration();
	signal_handler();
	initialize_files(argv, argc, &files);
	set_window_size();
	key = 0;
	update_files(&files);
	while (key != ESC && key != ENR)
	{
		nbr_cols = get_nbr_cols(&files);
		process_key(key, &files.index, nbr_cols, &files);
		ft_putstr_fd(CLEAR_SCREEN, 0);
		print_filenames(&files, files.index, nbr_cols);
		key = read_key();
	}
	reset_term_configuration();
	//free_everything(files);*/
	return (0);
}
