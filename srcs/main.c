#include "../includes/ft_select.h"

struct winsize	g_window_size;

int		longest_strlen(char **array, int start, int end)
{
	int max;
	int len;

	start--;
	max = 0;
	while (++start < end && array[start])
	{
		len = strlen(array[start]);
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
	max_strlen = longest_strlen(files->files, 0, files->nbr_files);
	width = max_strlen;
	while (width <= g_window_size.ws_col)
	{
		width += max_strlen;
		nbr_cols++;
	}
	return (nbr_cols);
}

int	check_in_array(int *array, int len, int nbr)
{
	int i;

	i = -1;
	while (++i < len)
	{
		if (array[i] == nbr)
			return (1);
	}
	return (0);
}

void	print_filenames(t_files *files, int index_selected, int nbr_cols)
{
	int	i;
	int	row;
	int	col;
	int	max_strlen;
	int	selected;

	i = -1;
	max_strlen = longest_strlen(files->files, 0, files->nbr_files);
	while (files->files[++i])
	{
		selected = check_in_array(files->selected, files->nbr_files + 1, i);
		if (i == index_selected)
			ft_putstr_fd(US, STDOUT_FILENO);
		else
			ft_putstr_fd(NORM, STDOUT_FILENO);
		if (selected)
			ft_putstr_fd(SO, STDOUT_FILENO);
		col = i % nbr_cols;
		row = i / nbr_cols;
		ft_putstr_fd(tgoto(CM, col * max_strlen, row), 0);
		ft_putstr_fd(files->files[i], STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

void	check_term(void)
{
	if (!getenv("TERM"))
		exit(-1);
	if (tgetent(NULL, getenv("TERM")) <= 0)
		exit(-1);
	//if ((0 = open(ttyname(0), O_RDWR | O_NDELAY)) < 0)
	//	exit(-1);
}

void	exit_program(int signum)
{
	//reset_term_settings();
	printf("%d", signum);
	exit(-1);
}

void	signal_handler(void)
{
	//signal(SIGWINCH, set_window_size);
	//signal(SIGTSTP, suspend);
	//signal(SIGCONT, restart);
	signal(SIGILL, exit_program);
	signal(SIGPIPE, exit_program);
	signal(SIGFPE, exit_program);
	signal(SIGSYS, exit_program);
	signal(SIGTRAP, exit_program);
	signal(SIGHUP, exit_program);
	//signal(SIGINT, exit_program);
	signal(SIGQUIT, exit_program);
	signal(SIGABRT, exit_program);
	signal(SIGKILL, exit_program);
	signal(SIGBUS, exit_program);
	signal(SIGSEGV, exit_program);
	signal(SIGALRM, exit_program);
	signal(SIGTERM, exit_program);
	signal(SIGUSR1, exit_program);
	signal(SIGUSR2, exit_program);
}

void	set_window_size(void)
{
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &g_window_size);
}

void	initialize_values(char **argv, int argc, t_files *files)
{
	int i;

	files->files = &argv[1];
	files->nbr_files = argc - 1;
	files->nbr_selected = 0;
	if (!(files->selected = (int *)malloc(sizeof(int) * argc)))
		exit(-1);
	i = -1;
	while (++i < argc)
		files->selected[i] = -1;
}

int		ft_getchar(void) {

	int				buf;
	struct termios	old;

	buf = 0;
	if (tcgetattr(STDERR_FILENO, &old) < 0)
		perror("tcsetattr()");
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	if (tcsetattr(STDERR_FILENO, TCSANOW, &old) < 0)
		perror("tcsetattr ICANON");
	if (read(STDERR_FILENO, &buf, 8) < 0)
		perror ("read()");
	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;
	if (tcsetattr(STDERR_FILENO, TCSADRAIN, &old) < 0)
		perror ("tcsetattr ~ICANON");
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
		files->selected[files->nbr_selected] = *index;
		(files->nbr_selected)++;
	}
	if (*index >= files->nbr_files)
		*index = 0;
	if (*index < 0)
		*index = files->nbr_files - 1;
}

int		main(int argc, char **argv)
{
	t_files	files;
	int		key;
	int		nbr_cols;
	int		index;

	if (argc < 2)
		return (0);
	check_term();
	signal_handler();
	initialize_values(argv, argc, &files);
	set_window_size();
	key = 0;
	index = 0;
	// the one to the right is also marked for some reason
	while (key != ESC && key != ENR)
	{
		nbr_cols = get_nbr_cols(&files);
		process_key(key, &index, nbr_cols, &files);
		ft_putstr_fd(CLEAR_SCREEN, 0);
		print_filenames(&files, index, nbr_cols);
		key = ft_getchar();
	}
	//ft_putstr_fd(CLEAR_SCREEN, 0);
	//free_everything(files);*/
	return (0);
}
