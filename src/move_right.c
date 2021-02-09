/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:01:54 by aihya             #+#    #+#             */
/*   Updated: 2019/09/24 18:02:09 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_right(t_data *d)
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
