/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michele <cmicheledelaney@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:55:06 by michele           #+#    #+#             */
/*   Updated: 2019/04/09 13:35:43 by michele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

struct winsize	g_window_size;
struct termios	g_term_old;

t_files	*update_files(t_files *updated_files)
{
	static t_files *files;

	if (updated_files == NULL)
		return (files);
	files = updated_files;
	return (files);
}

/*
** resets the terminal to its original configurations.
*/

void	reset_term_configuration(void)
{
	if (tcsetattr(STDERR_FILENO, TCSANOW, &g_term_old))
		exit(0);
	ft_putstr_fd(VE, 2);
	ft_putstr_fd(TE, 2);
}

/*
** sets the terminal to canonical which means each character gets
** read instantly, the buffer doesn't need a newline to get passed.
*/

void	set_term_configuration(void)
{
	struct termios	term;

	if (!getenv("TERM"))
		exit(-1);
	if (tgetent(NULL, getenv("TERM")) <= 0)
		exit(-1);
	tcgetattr(STDERR_FILENO, &g_term_old);
	tcgetattr(STDERR_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDERR_FILENO, TCSANOW, &term);
	ft_putstr_fd(TI, 2);
	ft_putstr_fd(VI, 2);
}
