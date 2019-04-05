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

void	reset_term_configuration(void)
{
	if (tcsetattr(STDERR_FILENO, TCSANOW, &g_term_old))
		exit(0);
	ft_putstr_fd(VE, 2);
	ft_putstr_fd(TE, 2);
}

void	set_term_configuration(void)
{
	struct termios term;

	if (!getenv("TERM"))
		exit(-1);
	if (tgetent(NULL, getenv("TERM")) <= 0)
		exit(-1);
	//if ((0 = open(ttyname(0), O_RDWR | O_NDELAY)) < 0)
	//	exit(-1);
	tcgetattr(STDERR_FILENO, &g_term_old);
	tcgetattr(STDERR_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDERR_FILENO, TCSANOW, &term);
	ft_putstr_fd(TI, 2);
	ft_putstr_fd(VI, 2);
}
