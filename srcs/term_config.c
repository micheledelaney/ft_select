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
