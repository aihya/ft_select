/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:47:41 by aihya             #+#    #+#             */
/*   Updated: 2019/09/16 15:54:46 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	free_node(t_lst **a_node)
{
	free((*a_node)->arg);
	free((*a_node));
	*a_node = NULL;
}

void	delete_inner(t_lst **curr)
{
	(*curr)->next->prev = (*curr)->prev;
	(*curr)->prev->next = (*curr)->next;
	free_node(curr);
}

int		delete_first(t_data *d, t_lst **curr)
{
	if (d->lstsize > 1)
	{
		(*curr)->next->prev = NULL;
		d->lst = (*curr)->next;
		free_node(curr);
	}
	else
	{
		free_node(curr);
		d->lstsize--;
		return (1);
	}
	return (0);
}

void	delete_last(t_data *d, t_lst **curr)
{
	d->target--;
	(*curr)->prev->next = NULL;
	free_node(curr);
}

void	delete_arg(t_data *d)
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
	if (i != 0 && i != d->lstsize - 1)
		delete_inner(&curr);
	else if (i == 0)
	{
		if (delete_first(d, &curr))
			return ;
	}
	else if (i == d->lstsize - 1)
		delete_last(d, &curr);
	d->lstsize--;
	update_max(d);
	update_data(d);
	print_args(d);
}
