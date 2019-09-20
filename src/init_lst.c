/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:32:12 by aihya             #+#    #+#             */
/*   Updated: 2019/07/29 16:38:55 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_lst	*node(char *arg)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->arg = ft_strdup(arg);
	new->selected = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_lst	*init_lst(char **args)
{
	t_lst	*head;
	t_lst	*curr;
	int		i;

	head = node(args[0]);
	curr = head;
	i = 1;
	while (args[i])
	{
		curr->next = node(args[i++]);
		curr->next->prev = curr;
		curr = curr->next;
	}
	return (head);
}
