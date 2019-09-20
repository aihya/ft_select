/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 04:59:31 by aihya             #+#    #+#             */
/*   Updated: 2019/09/20 19:30:34 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		putchr(int c)
{
	write(g_data->tty, &c, 1);
	return (1);
}

void	ft_select(char **argv, int tty)
{
	g_data = init_data(argv, tty);
	modify_main_caps(UNSET, g_data->tty);
	if (g_data->ldim.c == 0)
	{
		modify_main_caps(SET, g_data->tty);
		exit(EXIT_FAILURE);
	}
	else
	{
		enable_cap("ti");
		print_args(g_data);
		interact(g_data);
		modify_main_caps(SET, g_data->tty);
		get_selected(g_data);
		exit(EXIT_SUCCESS);
	}
}

void	get_selected(t_data *d)
{
	t_lst	*curr;

	curr = d->lst;
	while (curr && !curr->selected)
		curr = curr->next;
	if (curr && curr->selected)
	{
		ft_putstr_fd(curr->arg, 1);
		curr = curr->next;
	}
	while (curr)
	{
		if (curr->selected)
		{
			ft_putstr_fd(" ", 1);
			ft_putstr_fd(curr->arg, 1);
		}
		curr = curr->next;
	}
	close(d->tty);
}

int		main(int argc, char **argv)
{
	int		tty;

	(void)argc;
	if ((tty = init_term()) != -1 && ++argv)
	{
		signals();
		ft_select(argv, tty);
	}
	return (0);
}
