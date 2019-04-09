/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michele <cmicheledelaney@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:54:44 by michele           #+#    #+#             */
/*   Updated: 2019/04/09 11:54:46 by michele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

/*
** when the user hits ctrl+z the application suspends. to do so
** the terminal settings need to get reset.
*/

static void	suspend(int signum)
{
	(void)signum;
	reset_term_configuration();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

/*
** when the user enters 'fg' the application gets restarted. the terminal
** settings get set to canocinal again.
*/

static void	restart(int s)
{
	char		buf[2];

	(void)s;
	set_term_configuration();
	buf[0] = -62;
	buf[1] = 0;
	ioctl(0, TIOCSTI, buf);
}

/*
** when the program exists the malloced array gets freed and the terminal
** settings get set to normal again.
*/

static void	exit_program(int signum)
{
	t_files *tmp;

	tmp = NULL;
	tmp = update_files(tmp);
	free(tmp->selected);
	reset_term_configuration();
	exit(signum);
}

/*
** when the user changes the window size a signal (SIGWINCH) gets sent.
** when this occurs the screen needs to get cleared, the nbr of columns
** recalculated and all the files printed again.
*/

static void	update_window_size(int signum)
{
	int		nbr_cols;
	t_files	*t;

	(void)signum;
	t = NULL;
	t = update_files(t);
	set_window_size();
	nbr_cols = get_nbr_cols(t);
	ft_putstr_fd(CLEAR_SCREEN, 0);
	print_filenames(t, t->index, nbr_cols);
}

void		signal_handler(void)
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
