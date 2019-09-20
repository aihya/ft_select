/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:19:17 by aihya             #+#    #+#             */
/*   Updated: 2019/09/17 21:33:23 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_free(void *arg)
{
	free(arg);
	return (1);
}

int		init_term(void)
{
	int		ret;
	char	*term_type;
	int		tty;

	term_type = getenv("TERM");
	if (term_type == NULL && ft_free(term_type))
	{
		ft_putendl_fd("TERM environment variable was not found.", 2);
		return (-1);
	}
	ret = tgetent(NULL, term_type);
	if (ret == -1)
	{
		ft_putendl_fd("Unable to access termcap database.", 2);
		return (-1);
	}
	if (ret == 0)
	{
		ft_putstr_fd("Unable to recognize \"", 2);
		ft_putstr_fd(term_type, 2);
		ft_putendl_fd("\" as valid terminal type", 2);
		return (-1);
	}
	tty = open_tty();
	return (tty);
}
