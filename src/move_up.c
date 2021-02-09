/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:02:17 by aihya             #+#    #+#             */
/*   Updated: 2019/09/24 18:02:45 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	move_up_x_check(t_data *d)
{
	if (d->pos.x + 1 <= d->ldim.c - 1)
		d->pos.x++;
	else
		d->pos.x = 0;
}

void		move_up(t_data *d)
{
	int		mod;

	mod = d->lstsize % d->ldim.c;
	if (d->pos.y - 1 < 0)
	{
		if (d->pos.x + 1 < mod)
		{
			move_up_x_check(d);
			d->pos.y = d->ldim.r - 1;
		}
		else
		{
			move_up_x_check(d);
			if (d->pos.x == 0 || mod == 0)
				d->pos.y = d->ldim.r - 1;
			else
				d->pos.y = d->ldim.r - 2;
		}
	}
	else
		d->pos.y--;
}
