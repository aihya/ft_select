/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_keys_tests.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:44:37 by aihya             #+#    #+#             */
/*   Updated: 2019/09/20 19:33:13 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	update_target(t_data *d)
{
	d->target = (d->ldim.c * d->pos.y + d->pos.x);
}

int		is_arrow_key(int key)
{
	if (IS_KEY_U(key) || IS_KEY_D(key)
	|| IS_KEY_L(key) || IS_KEY_R(key))
		return (1);
	return (0);
}

void	read_key(t_data *d, int tty)
{
	d->key = 0;
	read(tty, &(d->key), sizeof(int));
}

int		arrow_key_test(t_data *d)
{
	if (is_arrow_key(d->key))
	{
		update_cursor(d, 0);
		if (IS_KEY_U(d->key))
			move_up(d);
		else if (IS_KEY_D(d->key))
			move_down(d);
		else if (IS_KEY_L(d->key))
			move_left(d);
		else if (IS_KEY_R(d->key))
			move_right(d);
		update_target(d);
		return (1);
	}
	return (0);
}

int		function_keys_test(int key, t_data *d)
{
	if (IS_DELETE(key) || IS_BSPACE(key))
	{
		delete_arg(d);
		if (d->lstsize == 0)
			return (-1);
	}
	else if (IS_SPACE(key))
		selected(d);
	else if (IS_ENTER(key))
		return (-1);
	else if (IS_A(key))
		select_all(d);
	else if (IS_F(key))
		flip(d);
	return (1);
}
