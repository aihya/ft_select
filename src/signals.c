/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:06:44 by aihya             #+#    #+#             */
/*   Updated: 2019/10/03 17:35:39 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	signals(void)
{
	int		sig;

	sig = 1;
	while (sig <= 31)
	{
		signal(sig, signalhandler);
		sig++;
	}
}

void	on_winch(void)
{
	struct winsize	ws;

	ioctl(g_data->tty, TIOCGWINSZ, &ws);
	if ((ws.ws_col - (g_data->ldim.c * (g_data->max + 1)) > g_data->max + 1
		|| ws.ws_col - (g_data->ldim.c * (g_data->max + 1)) < 0))
	{
		update_data(g_data);
		print_args(g_data);
		update_cursor(g_data, 1);
	}
	if (ws.ws_row - g_data->ldim.r >= 0)
	{
		update_data(g_data);
		print_args(g_data);
		update_cursor(g_data, 1);
	}
	else
	{
		g_data->interact = 0;
		print_args(g_data);
	}
}

void	enable_caps(void)
{
	enable_cap("ve");
	enable_cap("te");
}

void	signalhandler(int sig)
{
	if (sig != 16 && sig != 18 && sig != 19
	&& (sig != 23 && sig != 28 && sig != 29))
	{
		enable_caps();
		modify_main_caps(SET, g_data->tty);
		exit(EXIT_FAILURE);
	}
	else if (sig == SIGWINCH)
		on_winch();
	else if (sig == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		enable_caps();
		modify_main_caps(SET, g_data->tty);
		ioctl(g_data->tty, TIOCSTI, "\032");
	}
	else if (sig == SIGCONT)
	{
		signal(SIGTSTP, signalhandler);
		modify_main_caps(UNSET, g_data->tty);
		update_data(g_data);
		print_args(g_data);
		update_cursor(g_data, 1);
	}
}

int		open_tty(void)
{
	int	fd;

	fd = open("/dev/tty", O_RDWR);
	return (fd);
}
