/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:59:34 by aihya             #+#    #+#             */
/*   Updated: 2019/09/19 15:29:52 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	selected(t_data *d)
{
	int		i;
	t_lst	*curr;

	i = 0;
	curr = d->lst;
	while (i < d->target)
	{
		curr = curr->next;
		i++;
	}
	if (curr->selected == 0)
	{
		curr->selected = 1;
		enable_cap("mr");
		ft_putstr_fd(curr->arg, d->tty);
		enable_cap("me");
	}
	else
	{
		curr->selected = 0;
		ft_putstr_fd(curr->arg, d->tty);
	}
	d->target = d->target + 1 == d->lstsize ? 0 : d->target + 1;
	update_pos(d);
	put_cursor_at(d->pos.x * (d->max + 1), d->pos.y);
}

void	select_all(t_data *d)
{
	t_lst		*curr;

	curr = d->lst;
	while (curr != NULL)
	{
		curr->selected = 1;
		curr = curr->next;
	}
	print_args(d);
}

void	flip(t_data *d)
{
	t_lst	*curr;

	curr = d->lst;
	while (curr != NULL)
	{
		curr->selected = curr->selected ? 0 : 1;
		curr = curr->next;
	}
	print_args(d);
}
