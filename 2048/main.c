/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 21:14:18 by ebouther          #+#    #+#             */
/*   Updated: 2016/01/30 21:19:46 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static unsigned int	ft_get_random(unsigned int max)
{
	srand(time(NULL));
	return (rand() % (max + 1));
}

static void			ft_new_rand(t_env *e)
{
	unsigned int	r_pos;
	int				i;
	int				max;

	i = 0;
	max = 0;
	while (i < BOARD * BOARD)
	{
		if (e->map[i++] == 0)
			max++;
	}
	r_pos = ft_get_random(max) + 1;
	i = 0;
	while (i < BOARD * BOARD)
	{
		if (e->map[i] == 0)
			r_pos--;
		if (r_pos <= 0)
		{
			e->map[i] = ft_get_random(1) ? 4 : 2;
			break ;
		}
		i++;
	}
}

static void			ft_init(t_env *e)
{
	int				i;
	unsigned int	init_pos[2];

	initscr();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	i = 0;
	if ((e->map = (int *)malloc(sizeof(int) * (BOARD * BOARD))) == NULL)
		return ;
	while (i < (BOARD * BOARD))
		e->map[i++] = 0;
	init_pos[0] = ft_get_random(15);
	while ((init_pos[1] = ft_get_random(15)) == init_pos[0])
		i = 0;
	while (i < 2)
		e->map[init_pos[i++]] = ft_get_random(1) ? 4 : 2;
}

static void			ft_game_loop(t_env *e)
{
	int	c;
	int	diff;

	c = 0;
	while (1)
	{
		diff = 0;
		c = getch();
		if (c == KEY_LEFT)
			diff = ft_move_left(e);
		else if (c == KEY_RIGHT)
			diff = ft_move_right(e);
		else if (c == KEY_UP)
			diff = ft_move_up(e);
		else if (c == KEY_DOWN)
			diff = ft_move_down(e);
		else if (c == 27)
			break ;
		e->dbg = c;
		if (diff > 0)
			ft_new_rand(e);
		if (ft_strchr("ijkl", (char)c) != NULL)
			clear();
		ft_print_map(e);
	}
}

int					main(void)
{
	t_env	env;

	signal(SIGINT, ft_sighandler);
	ft_init(&env);
	ft_print_map(&env);
	ft_game_loop(&env);
	clear();
	endwin();
	return (0);
}
