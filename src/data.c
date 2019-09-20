/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:15:35 by aihya             #+#    #+#             */
/*   Updated: 2019/09/20 19:29:22 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	update_pos(t_data *d)
{
	if (d->ldim.c != 0)
	{
		d->pos.x = d->target % d->ldim.c;
		d->pos.y = d->target / d->ldim.c;
	}
	else
	{
		d->pos.x = 0;
		d->pos.y = 0;
	}
}

t_data	*init_data(char **args, int tty)
{
	static t_data	*d;
	struct winsize	ws;

	ioctl(tty, TIOCGWINSZ, &ws);
	d = (t_data *)malloc(sizeof(t_data));
	d->tty = tty;
	d->max = (int)ft_strmax(args);
	d->lstsize = (int)ft_chain_size(args);
	d->lst = init_lst(args);
	d->tdim.c = ws.ws_col;
	d->tdim.l = ws.ws_row;
	d->target = 0;
	if (d->tdim.c / (d->max + 1) > d->lstsize)
		d->ldim.c = d->lstsize;
	else
		d->ldim.c = d->tdim.c / (d->max + 1);
	d->ldim.r = d->ldim.c == 0 ? 0 : d->lstsize / d->ldim.c;
	if (d->ldim.r != 0 && d->lstsize % d->ldim.c)
		d->ldim.r++;
	d->interact = 0;
	if (d->ldim.r <= d->tdim.l)
		d->interact = 1;
	update_pos(d);
	return (d);
}

void	update_max(t_data *d)
{
	t_lst	*curr;
	int		max;
	int		n;

	curr = d->lst;
	max = 0;
	while (curr)
	{
		n = (int)ft_strlen(curr->arg);
		max = n > max ? n : max;
		curr = curr->next;
	}
	d->max = max;
}

void	update_data(t_data *d)
{
	struct winsize	ws;

	ioctl(d->tty, TIOCGWINSZ, &ws);
	d->tdim.c = ws.ws_col;
	d->tdim.l = ws.ws_row;
	if (d->tdim.c / (d->max + 1) > d->lstsize)
		d->ldim.c = d->lstsize;
	else
		d->ldim.c = d->tdim.c / (d->max + 1);
	d->ldim.r = d->ldim.c == 0 ? 0 : d->lstsize / d->ldim.c;
	if (d->ldim.r != 0 && d->lstsize % d->ldim.c)
		d->ldim.r++;
	d->interact = 0;
	if (d->ldim.r <= d->tdim.l && d->ldim.c != 0)
		d->interact = 1;
	update_pos(d);
}
