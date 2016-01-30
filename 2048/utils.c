/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 21:15:31 by ebouther          #+#    #+#             */
/*   Updated: 2016/01/30 21:19:46 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		ft_print_map(t_env *e)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < BOARD * BOARD)
	{
		mvprintw(y, x, ft_itoa(e->map[i]));
		x += BOARD;
		if (i % (BOARD) == BOARD - 1)
		{
			y += 2;
			x = 0;
		}
		i++;
	}
	mvprintw(20, 50, "%f", ((double)(e->end - e->start)) / CLOCKS_PER_SEC);
	mvprintw(40, 70, "%d", e->dbg);
	refresh();
}

void		ft_sighandler(int signum)
{
	if (signum == 2)
	{
		clear();
		endwin();
		exit(-1);
	}
}
