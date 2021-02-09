/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:01:00 by aihya             #+#    #+#             */
/*   Updated: 2019/09/24 18:01:41 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_left(t_data *d)
{
	if (d->pos.x - 1 < 0)
	{
		if (d->pos.y - 1 < 0)
		{
			if (d->lstsize > d->ldim.c)
			{
				d->pos.y = d->ldim.r - 1;
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
