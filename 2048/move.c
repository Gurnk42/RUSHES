/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 20:47:57 by ebouther          #+#    #+#             */
/*   Updated: 2016/01/30 21:13:46 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

unsigned int	ft_move_left(t_env *e)
{
	t_move	m;

	m.y = 0;
	m.diff = 0;
	while (m.y < BOARD * BOARD)
	{
		m.x = 0;
		while (m.x < BOARD)
			m.p[m.x++] = 0;
		ft_fill_left(&m.p, &m.y, e);
		m.x = 0;
		while (m.x < BOARD)
		{
			if (e->map[m.y + m.x] != m.p[m.x])
			{
				e->map[m.y + m.x] = m.p[m.x];
				m.diff++;
			}
			m.x++;
		}
		m.y += BOARD;
	}
	return (m.diff);
}

unsigned int	ft_move_right(t_env *e)
{
	t_move	m;

	m.y = 0;
	m.diff = 0;
	while (m.y < BOARD * BOARD)
	{
		m.x = 0;
		while (m.x < BOARD)
			m.p[m.x++] = 0;
		ft_fill_right(&m.p, &m.y, e);
		m.x = 0;
		while (m.x < BOARD)
		{
			if (e->map[m.y + m.x] != m.p[m.x])
			{
				e->map[m.y + m.x] = m.p[m.x];
				m.diff++;
			}
			m.x++;
		}
		m.y += BOARD;
	}
	return (m.diff);
}

unsigned int	ft_move_up(t_env *e)
{
	t_move	m;

	m.diff = 0;
	m.x = 0;
	while (m.x < BOARD)
	{
		m.j = 0;
		while (m.j < BOARD)
			m.p[m.j++] = 0;
		ft_fill_up(&m.p, &m.x, e);
		m.y = 0;
		m.j = 0;
		while (m.y <= ((BOARD - 1) * BOARD))
		{
			if (e->map[m.x + m.y] != m.p[m.j])
			{
				e->map[m.x + m.y] = m.p[m.j];
				m.diff++;
			}
			m.y += BOARD;
			m.j++;
		}
		m.x++;
	}
	return (m.diff);
}

unsigned int	ft_move_down(t_env *e)
{
	t_move	m;

	m.diff = 0;
	m.x = 0;
	while (m.x < BOARD)
	{
		m.j = 0;
		while (m.j < BOARD)
			m.p[m.j++] = 0;
		ft_fill_down(&m.p, &m.x, e);
		m.y = 0;
		m.j = 0;
		while (m.y <= ((BOARD - 1) * BOARD))
		{
			if (e->map[m.x + m.y] != m.p[m.j])
			{
				e->map[m.x + m.y] = m.p[m.j];
				m.diff++;
			}
			m.y += BOARD;
			m.j++;
		}
		m.x++;
	}
	return (m.diff);
}
