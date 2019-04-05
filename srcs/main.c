#include "../includes/ft_select.h"

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
	update_files(&files);
	key = 0;
	while (key != ESC && key != ENR)
	{
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
