/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:57:36 by aihya             #+#    #+#             */
/*   Updated: 2019/09/21 18:43:46 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>

# define KEY_U	4283163
# define KEY_D	4348699
# define KEY_R	4414235
# define KEY_L	4479771
# define DELETE	2117294875
# define ENTER	10
# define ESC	27
# define SPACE	32
# define BSPACE	127
# define A		97
# define F		102

# define KEY_TEST(KEY, KEY_MACRO) KEY == KEY_MACRO ? 1 : 0

# define IS_KEY_U(X)	KEY_TEST(X, KEY_U)
# define IS_KEY_D(X)	KEY_TEST(X, KEY_D)
# define IS_KEY_R(X)	KEY_TEST(X, KEY_R)
# define IS_KEY_L(X)	KEY_TEST(X, KEY_L)
# define IS_DELETE(X)	KEY_TEST(X, DELETE)
# define IS_ENTER(X)	KEY_TEST(X, ENTER)
# define IS_ESC(X)		KEY_TEST(X, ESC)
# define IS_SPACE(X)	KEY_TEST(X, SPACE)
# define IS_BSPACE(X)	KEY_TEST(X, BSPACE)
# define IS_A(X)	KEY_TEST(X, A)
# define IS_F(X)	KEY_TEST(X, F)

# define SET	1
# define UNSET	2

# define NOSPACE_ERR "NO SPACE"

typedef struct	s_lst
{
	char			*arg;
	int				selected:1;
	struct s_lst	*prev;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_tdim
{
	int		c;
	int		l;
}				t_tdim;

typedef struct	s_ldim
{
	int		c;
	int		r;
}				t_ldim;

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct	s_data
{
	t_lst	*lst;
	t_tdim	tdim;
	t_ldim	ldim;
	t_pos	pos;
	int		key;
	int		target;
	int		max;
	int		interact:1;
	int		lstsize;
	int		tty;
}				t_data;

t_data			*g_data;
t_data			*init_data(char **args, int tty);
int				init_term();
t_lst			*init_lst(char **args);
void			set_termios_cap(int cap, int tty);
void			modify_main_caps(int action, int tty);
int				putchr(int c);
void			enable_cap(char *cap);
void			print_args(t_data *d);
void			print_on_selection(t_lst *node);
void			interact(t_data *d);
void			init_pos(t_pos *pos);
void			move_right(t_data *d);
void			move_left(t_data *d);
void			move_up(t_data *d);
void			move_down(t_data *d);
void			signalhandler(int sig);
void			signals();
void			ft_select(char **argv, int tty);
void			update_data(t_data *d);
void			update_pos(t_data *d);
void			update_max(t_data *d);
void			update_cursor(t_data *d, int underline);
void			put_cursor_at(int x, int y);
void			selected(t_data *d);
void			select_all(t_data *d);
void			flip(t_data *d);
void			delete_arg(t_data *d);
int				open_tty();
void			get_selected(t_data *d);
void			read_key(t_data *d);
int				arrow_key_test(t_data *d);
int				function_keys_test(t_data *d);

#endif
