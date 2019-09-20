/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:55:01 by aihya             #+#    #+#             */
/*   Updated: 2019/09/20 19:28:06 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_pos(t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
}

int		check_space(t_pos *pos, t_data *data)
{
	if (data->max + pos->x + 1 > data->tdim.c)
	{
		if (pos->y + 1 > data->tdim.l)
		{
			enable_cap("ti");
			put_cursor_at(0, 0);
			ft_putstr_fd(NOSPACE_ERR, data->tty);
			return (-1);
		}
		pos->x = 0;
		pos->y = pos->y + 1;
	}
	return (1);
}

void	print_on_selection(t_lst *node)
{
	if (node->selected)
	{
		enable_cap("mr");
		ft_putstr_fd(node->arg, g_data->tty);
		enable_cap("me");
	}
	else
		ft_putstr_fd(node->arg, g_data->tty);
}

void	print_args(t_data *d)
{
	t_lst	*curr;
	t_pos	pos;

	enable_cap("ti");
	init_pos(&pos);
	if ((curr = d->lst) && d->interact)
	{
		while (curr)
		{
			if (check_space(&pos, d) == -1)
				break ;
			put_cursor_at(pos.x, pos.y);
			print_on_selection(curr);
			pos.x = pos.x + d->max + 1;
			curr = curr->next;
		}
		pos.x = d->pos.x * (d->max + 1);
		put_cursor_at(pos.x, d->pos.y);
	}
	else
	{
		put_cursor_at(pos.x, pos.y);
		ft_putstr_fd(NOSPACE_ERR, d->tty);
	}
}
