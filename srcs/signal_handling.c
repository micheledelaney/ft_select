#include "../includes/ft_select.h"

t_files	*update_files(t_files *updated_files)
{
	static t_files *files;

	if (updated_files == NULL)
		return (files);
	files = updated_files;
	return (files);
}

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
	signal(SIGTSTP, reset);
//	signal(SIGCONT, restart);
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


