#include "../includes/ft_select.h"

struct winsize	g_window_size;

void	set_window_size(void)
{
	ioctl(STDERR_FILENO, TIOCGWINSZ, &g_window_size);
}

int		get_max_strlen(char **array, int start, int end)
{
	int max;
	int len;

	start--;
	max = 0;
	while (++start < end && array[start])
	{
		len = ft_strlen(array[start]);
		max = (len > max) ? (len) : (max);
	}
	return (max + 1);
}

int		get_nbr_cols(t_files *files)
{
	int max_strlen;
	int nbr_cols;
	int width;

	nbr_cols = 0;
	max_strlen = get_max_strlen(files->files, 0, files->nbr_files);
	width = max_strlen;
	while (width <= g_window_size.ws_col)
	{
		width += max_strlen;
		nbr_cols++;
	}
	return (nbr_cols);
}

bool	ends_with(char *str, char *end)
{
	int i;
	int j;

	i = -1;
	j = -1;
	if (end == NULL || str == NULL)
		return (false);
	while (str[++i])
		;
	while (end[++j])
		;
	while (i >= 0 && j >= 0)
	{
		if (str[i] != end[j])
			return (false);
		i--;
		j--;
	}
	if (j != -1)
		return (false);
	return (true);
}

void	print_color(char *file)
{
	struct stat s;

	int err = stat(file, &s);
	if (err != -1)
	{
		if (S_ISDIR(s.st_mode))
			ft_putstr_fd(BOLD, STDERR_FILENO);
	}
	if (err == -1)
		ft_putstr_fd(INVALID, STDERR_FILENO);
	(ends_with(file, ".c")) ? (ft_putstr_fd(C_COLOR, STDERR_FILENO)) : (0);
	(ends_with(file, ".o")) ? (ft_putstr_fd(O_COLOR, STDERR_FILENO)) : (0);
	(ends_with(file, ".h")) ? (ft_putstr_fd(H_COLOR, STDERR_FILENO)) : (0);
}

void	print_filenames(t_files *files, int index, int nbr_cols)
{
	int	i;
	int	row;
	int	col;
	int	max_strlen;

	i = -1;
	if ((nbr_cols * g_window_size.ws_row) < files->nbr_files)
		return ;
	max_strlen = get_max_strlen(files->files, 0, files->nbr_files);
	ft_putstr_fd(CLEAR_SCREEN, 0);
	while (files->files[++i])
	{
		ft_putstr_fd(RESET, STDERR_FILENO);
		(i == index) ? (ft_putstr_fd(UNDERLINED, STDERR_FILENO)) : (0);
		(files->selected[i] != -1) ? (ft_putstr_fd(INVERSE, STDERR_FILENO)) : (0);
		col = i % nbr_cols;
		row = i / nbr_cols;
		ft_putstr_fd(tgoto(CM, col * max_strlen, row), 0);
		print_color(files->files[i]);
		ft_putstr_fd(files->files[i], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		ft_putstr_fd(RESET, STDERR_FILENO);
	}
	ft_putstr_fd(RESET, STDERR_FILENO);
}
