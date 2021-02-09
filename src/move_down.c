/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:02:54 by aihya             #+#    #+#             */
/*   Updated: 2019/09/24 18:03:29 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	move_down_x_check(t_data *d)
{
	if (d->pos.x - 1 >= 0)
		d->pos.x -= 1;
	else
		d->pos.x = d->ldim.c - 1;
}

void		move_down(t_data *d)
{
	int		mod;

	mod = d->lstsize % d->ldim.c;
	if (d->pos.x < mod || mod == 0)
	{
		if (d->pos.y + 1 > d->ldim.r - 1)
		{
			move_down_x_check(d);
			d->pos.y = 0;
		}
		else
			d->pos.y++;
	}
	else
	{
		if (d->pos.y + 1 > d->ldim.r - 2)
		{
			move_down_x_check(d);
			d->pos.y = 0;
		}
		else
			d->pos.y++;
	}
}
