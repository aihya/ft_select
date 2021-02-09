/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:36:19 by aihya             #+#    #+#             */
/*   Updated: 2019/09/23 16:30:27 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	put_cursor_at(int x, int y)
{
	tputs(tparm(tgetstr("cm", NULL), y, x), 1, putchr);
}

void	update_cursor(t_data *d, int underline)
{
	int		i;
	t_lst	*curr;

	curr = d->lst;
	i = 0;
	while (i < d->target)
	{
		curr = curr->next;
		i++;
	}
	if (d->interact)
	{
		if (underline)
		{
			enable_cap("us");
			print_on_selection(curr);
			enable_cap("ue");
		}
		else
			print_on_selection(curr);
	}
	put_cursor_at(d->pos.x * (d->max + 1), d->pos.y);
}

void	interact(t_data *d)
{
	put_cursor_at(d->pos.x, d->pos.y);
	update_cursor(d, 1);
	enable_cap("vi");
	while (1)
	{
		read_key(d);
		if (IS_ESC(d->key))
			break ;
		if (d->interact)
		{
			if (arrow_key_test(d))
				put_cursor_at(d->pos.x * (d->max + 1), d->pos.y);
			else if (function_keys_test(d) == -1)
				break ;
			update_cursor(d, 1);
		}
	}
	enable_cap("ve");
}
