#include "../includes/ft_select.h"

struct winsize	g_window_size;
struct termios old;
struct termios new;

int		ft_printnbr(int nbr)
{
	return (write(STDERR_FILENO, &nbr, 1));
}

void	reset_term_configuration(void)
{
	tcsetattr(STDERR_FILENO, TCSANOW, &old);
	tputs(tgetstr("ve", NULL), 1, ft_printnbr);
	tputs(tgetstr("te", NULL), 1, ft_printnbr);
}

void	set_term_configuration(void)
{
	if (!getenv("TERM"))
		exit(-1);
	if (tgetent(NULL, getenv("TERM")) <= 0)
		exit(-1);
	//if ((0 = open(ttyname(0), O_RDWR | O_NDELAY)) < 0)
	//	exit(-1);
	tcgetattr(STDERR_FILENO, &old);
	tcgetattr(STDERR_FILENO, &new);
	new.c_lflag &= ~(ICANON | ECHO);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	tcsetattr(STDERR_FILENO, TCSANOW, &new);
	tputs(tgetstr("ti", NULL), 1, ft_printnbr);
	tputs(tgetstr("vi", NULL), 1, ft_printnbr);
}

static void	suspend(int s)
{
	struct termios	t_attr;
	char			susp[2];

	(void)s;
	if (tcgetattr(0, &t_attr) == -1)
		exit(0);
	susp[0] = t_attr.c_cc[VSUSP];
	susp[1] = 0;
	t_attr.c_lflag |= ICANON;
	t_attr.c_lflag |= ECHO;
	t_attr.c_oflag |= OPOST;
	if (tcsetattr(0, TCSADRAIN, &t_attr) == -1)
		exit(0);
	ft_putstr_fd(VE, 2);
	ft_putstr_fd(TE, 2);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, susp);
}

static void	restart(int s)
{
	char		buf[2];

	(void)s;
	tcgetattr(STDERR_FILENO, &new);
	new.c_lflag &= ~(ICANON | ECHO);
	new.c_oflag &= ~(OPOST);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	tcsetattr(STDERR_FILENO, TCSANOW, &new);
	if (tgetent(NULL, getenv("TERM")) <= 0)
		exit(0);
	ft_putstr_fd(VI, 0);
	ft_putstr_fd(TI, 0);
	buf[0] = -62;
	buf[1] = 0;
	ioctl(0, TIOCSTI, buf);
}

t_files	*update_files(t_files *updated_files)
{
	static t_files *files;

	if (updated_files == NULL)
		return (files);
	files = updated_files;
	return (files);
}

static void	exit_program(int signum)
{
	t_files *tmp;

	(void)signum;
	tmp = NULL;
	tmp = update_files(tmp);
	free(tmp->selected);
	reset_term_configuration();
	exit(0);
}
/*
static void	reset(int signum)
{
	t_files *t;

	(void)signum;
	t = NULL;
	t = update_files(t);
	set_values(t);
	ft_putstr_fd(CLEAR_SCREEN, 0);
	int nbr_cols = get_nbr_cols(t);
	print_filenames(t, t->index, nbr_cols);
}*/

static void	update_window_size(int signum)
{
	t_files *t;

	(void)signum;
	t = NULL;
	t = update_files(t);
	set_window_size();
	int nbr_cols = get_nbr_cols(t);
	ft_putstr_fd(CLEAR_SCREEN, 0);
	print_filenames(t, t->index, nbr_cols);
}

void	signal_handler(void)
{
	signal(SIGWINCH, update_window_size);
	signal(SIGTSTP, suspend);
	signal(SIGCONT, restart);
	signal(SIGILL, exit_program);
	signal(SIGPIPE, exit_program);
	signal(SIGFPE, exit_program);
	signal(SIGSYS, exit_program);
	signal(SIGTRAP, exit_program);
	signal(SIGHUP, exit_program);
	signal(SIGINT, exit_program);
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


