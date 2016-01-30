/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 20:51:45 by ebouther          #+#    #+#             */
/*   Updated: 2016/01/30 20:57:44 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		ft_push_right(int (*p)[BOARD])
{
	int	i;
	int	done;

	done = 0;
	while (done == 0)
	{
		i = BOARD - 1;
		done = 1;
		while (i >= 0)
		{
			if ((i - 1 >= 0) && (*p)[i] == 0 && (*p)[i - 1] != 0)
			{
				(*p)[i] = (*p)[i - 1];
				(*p)[i - 1] = 0;
				done = 0;
			}
			i--;
		}
	}
}

void		ft_push_left(int (*p)[BOARD])
{
	int	i;
	int	done;

	done = 0;
	while (done == 0)
	{
		i = 0;
		done = 1;
		while (i < BOARD - 1)
		{
			if ((i + 1 < BOARD) && (*p)[i] == 0 && (*p)[i + 1] != 0)
			{
				(*p)[i] = (*p)[i + 1];
				(*p)[i + 1] = 0;
				done = 0;
			}
			i++;
		}
	}
}
