#include "../includes/ft_select.h"

static void	suspend(int signum)
{
	(void)signum;
	reset_term_configuration();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

static void	restart(int s)
{
	char		buf[2];

	(void)s;
	set_term_configuration();
	buf[0] = -62;
	buf[1] = 0;
	ioctl(0, TIOCSTI, buf);
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
