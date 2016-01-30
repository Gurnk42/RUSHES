/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 20:49:29 by ebouther          #+#    #+#             */
/*   Updated: 2016/01/30 21:01:26 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		ft_fill_up(int (*p)[BOARD], int *x, t_env *e)
{
	int	y;
	int	j;

	y = 0;	
	j = 0;
	while (y <= (BOARD - 1) * BOARD)
	{
		if (e->map[y + *x] != 0)
			(*p)[j++] = e->map[y + *x];
		y += BOARD;
	}
	y = 0;
	j = 0;
	while (j < BOARD)
	{
		if (j + 1 < BOARD && (*p)[j] == (*p)[j + 1])
		{
			(*p)[j] = (*p)[j + 1] + (*p)[j];
			(*p)[j + 1] = 0;
		}
		j++;
	}
	ft_push_left(p);
}

void		ft_fill_down(int (*p)[BOARD], int *x, t_env *e)
{
	int	y;
	int	j;

	y = (BOARD - 1) * BOARD;
	j = BOARD - 1;
	while (y >= 0)
	{
		if (e->map[y + *x] != 0)
			(*p)[j--] = e->map[y + *x];
		y -= BOARD;
	}
	y = 0;
	j = BOARD - 1;
	while (j >= 0)
	{
		if ((j - 1 >= 0) && (*p)[j] == (*p)[j - 1])
		{
			(*p)[j] = (*p)[j - 1] + (*p)[j];
			(*p)[j - 1] = 0;
		}
		j--;
	}
	ft_push_right(p);
}

void		ft_fill_left(int (*p)[BOARD], int *y, t_env *e)
{
	int	x;
	int	j;

	x = 0;	
	j = 0;	
	while (x < BOARD)
	{
		if (e->map[*y + x] != 0)
			(*p)[j++] = e->map[*y + x];
		x++;
	}
	x = 0;
	while (x < BOARD)
	{
		if ((x + 1 < BOARD) && (*p)[x] == (*p)[x + 1])
		{
			(*p)[x] = (*p)[x + 1] + (*p)[x];
			(*p)[x + 1] = 0;
		}
		x++;
	}
	ft_push_left(p);
}

void		ft_fill_right(int (*p)[BOARD], int *y, t_env *e)
{
	int	x;
	int	j;

	x = BOARD - 1;
	j = BOARD - 1;
	while (x >= 0)
	{
		if (e->map[*y + x] != 0)
			(*p)[j--] = e->map[*y + x];
		x--;
	}
	x = BOARD - 1;
	while (x >= 0)
	{
		if ((x - 1 >= 0) && (*p)[x] == (*p)[x - 1])
		{
			(*p)[x] = (*p)[x - 1] + (*p)[x];
			(*p)[x - 1] = 0;
		}
		x--;
	}
	ft_push_right(p);
}
