/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michele <cmicheledelaney@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 09:25:00 by michele           #+#    #+#             */
/*   Updated: 2019/04/11 09:25:26 by michele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <fcntl.h>
# include <time.h>
# include <termcap.h>
# include <limits.h>
# include <dirent.h>

# define RESET		"\033[0m"
# define UNDERLINED	"\033[4m"
# define INVERSE	"\033[7m"
# define INVALID	"\033[31m"
# define BOLD		"\033[1m"
# define WHITE		"\033[37m"
# define DIR_COLOR	BOLD

/*
** values of the different keys
*/

# define ESC 0x1B
# define SPC 0x20
# define ENR 0xA
# define DEL 0x7E335B1B
# define BCKSP 0x7F
# define UP 0x415B1B
# define DOWN 0x425B1B
# define RIGHT 0x435B1B
# define LEFT 0x445B1B

# define CLEAR_SCREEN (tgetstr("cl", NULL))
# define CM (tgetstr("cm", NULL))
# define VE (tgetstr("ve", NULL))
# define VI (tgetstr("vi", NULL))
# define US (tgetstr("us", NULL))
# define TE (tgetstr("te", NULL))
# define TI (tgetstr("ti", NULL))

typedef struct	s_files
{
	char		**files;
	int			nbr_files;
	int			*selected;
	int			index;
	bool		real;
}				t_files;

/*
** term_config.c
*/
void			set_term_configuration(void);
void			reset_term_configuration(void);

/*
** signal_handling.c
*/
void			signal_handler(void);
t_files			*update_files(t_files *updated_files);

/*
** print_files.c
*/
int				get_max_strlen(char **array);
int				get_nbr_cols(t_files *files);
void			print_filenames(t_files *files, int index, int nbr_cols);
void			set_window_size(void);

/*
** print_selected_finish.c
*/
void			print_selected(t_files *files);

/*
** read_process_key.c
*/
int				read_key(void);
void			process_key(int key, int *index, int nbr_cols, t_files *files);

/*
**  initialize.c
*/
void			initialize_files(char **argv, int argc, t_files *files);
void			set_values(t_files *files);

#endif
