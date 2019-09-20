/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 22:21:46 by aihya             #+#    #+#             */
/*   Updated: 2019/08/05 15:34:49 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	unset_termios_cap(int cap, int tty)
{
	struct termios	termios_p;

	if (tcgetattr(tty, &termios_p) == 0)
	{
		termios_p.c_lflag = termios_p.c_lflag & ~cap;
		if (tcsetattr(tty, TCSANOW, &termios_p) != 0)
			ft_putendl_fd("Problem: tcsetattr", 2);
	}
	else
		ft_putendl_fd("Problem: tcgetattr", 2);
}

void	set_termios_cap(int cap, int tty)
{
	struct termios	termios_p;

	if (tcgetattr(tty, &termios_p) == 0)
	{
		termios_p.c_lflag = termios_p.c_lflag | cap;
		if (tcsetattr(tty, TCSANOW, &termios_p) != 0)
			ft_putendl_fd("Problem: tcsetattr", 2);
	}
	else
		ft_putendl_fd("Problem: tcgetattr", 2);
}

void	enable_cap(char *cap)
{
	tputs(tgetstr(cap, NULL), 1, putchr);
}

void	modify_main_caps(int action, int tty)
{
	if (action == SET)
	{
		set_termios_cap(ICANON, tty);
		set_termios_cap(ECHO, tty);
		enable_cap("te");
	}
	else if (action == UNSET)
	{
		unset_termios_cap(ICANON, tty);
		unset_termios_cap(ECHO, tty);
	}
}
