/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:06:44 by aihya             #+#    #+#             */
/*   Updated: 2019/09/20 19:29:28 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	signals(void)
{
	signal(SIGWINCH, signalhandler);
	signal(SIGTSTP, signalhandler);
	signal(SIGCONT, signalhandler);
	signal(SIGINT, signalhandler);
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

void	signalhandler(int sig)
{
	if (sig == SIGWINCH)
		on_winch();
	else if (sig == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		enable_cap("te");
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
	else if (sig == SIGINT)
	{
		enable_cap("te");
		modify_main_caps(SET, g_data->tty);
		exit(EXIT_FAILURE);
	}
}

int		open_tty(void)
{
	int	fd;

	fd = open("/dev/tty", O_RDWR);
	return (fd);
}
