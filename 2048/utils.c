/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 21:15:31 by ebouther          #+#    #+#             */
/*   Updated: 2016/01/30 22:11:58 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		ft_print_map(t_env *e)
{
	int		i;
	int		y;
	int		n;
	int		max_y;
	int		max_x;

	max_x = 0;
	max_y = 0;
	getmaxyx(stdscr, max_y, max_x);
	clear();
	border('|', '|', '-', '_', '*', '*', '*', '*');
	i = 1;
	while (i < BOARD)
	{
		mvhline((max_y / BOARD) * i, 0, '-', max_x);
		mvvline(0, (max_x / BOARD) * i, '|', max_y);
		i++;
	}
	y = 1;
	n = 0;
	while (y < BOARD * 2)
	{
		i = 1;
		while (i < BOARD * 2)
		{
			mvprintw((max_y / (BOARD * 2)) * y, (max_x / (BOARD * 2)) * i, "%d", e->map[n++]);
			i += 2;
		}
		y += 2;
	}
	i = 0;
	refresh();
}

void		ft_print_map_dbg(t_env *e)
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
