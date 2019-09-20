/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:48:19 by aihya             #+#    #+#             */
/*   Updated: 2019/09/18 19:54:03 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		move_right(t_data *d)
{
	if ((d->pos.y * d->ldim.c) + (d->pos.x + 1) >= d->lstsize)
	{
		d->pos.x = 0;
		d->pos.y = 0;
	}
	else if (d->pos.x + 1 > d->ldim.c - 1)
	{
		d->pos.x = 0;
		d->pos.y += 1;
	}
	else
		d->pos.x = d->pos.x + 1;
}

void		move_left(t_data *d)
{
	if (d->pos.x - 1 < 0)
	{
		if (d->pos.y - 1 < 0)
		{
			if (d->lstsize > d->ldim.c)
			{
				d->pos.y = d->lstsize % d->ldim.c ? d->ldim.r : d->ldim.r - 1;
				d->pos.x = d->lstsize % d->ldim.c;
				if (d->pos.x == 0 && d->ldim.c != 1)
					d->pos.x = d->ldim.c - 1;
				else if (d->pos.x != 0)
					d->pos.x--;
			}
			else
				d->pos.x = d->ldim.c - 1;
		}
		else
		{
			d->pos.y -= 1;
			d->pos.x = d->ldim.c - 1;
		}
	}
	else
		d->pos.x -= 1;
}

void		move_up(t_data *d)
{
	if (d->pos.y - 1 < 0)
	{
		if (d->lstsize > d->ldim.c)
		{
			d->pos.y = d->ldim.r;
			d->pos.x += 1;
			if (d->pos.x > (d->lstsize % d->ldim.c) - 1)
				d->pos.y -= 1;
		}
		else
			d->pos.x += 1;
		if (d->pos.x > d->ldim.c - 1)
		{
			d->pos.x = 0;
			d->pos.y = d->lstsize % d->ldim.c ? d->ldim.r : d->ldim.r - 1;
		}
	}
	else
		d->pos.y -= 1;
}

static void	move_down_x_check(t_data *d)
{
	if (d->pos.x - 1 >= 0)
		d->pos.x -= 1;
	else
		d->pos.x = d->ldim.c - 1;
}

void		move_down(t_data *d)
{
	if (d->pos.x < d->lstsize % d->ldim.c)
	{
		if (d->pos.y + 1 > d->ldim.r)
		{
			move_down_x_check(d);
			d->pos.y = 0;
		}
		else
			d->pos.y += 1;
	}
	else
	{
		if (d->pos.y + 1 > d->ldim.r - 1)
		{
			move_down_x_check(d);
			d->pos.y = 0;
		}
		else
			d->pos.y += 1;
	}
}
