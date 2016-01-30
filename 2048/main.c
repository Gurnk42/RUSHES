#include "2048.h"

//
#include <stdio.h>
//

static void		ft_print_map(t_env *e)
{
	int	i;
	int	x;
	int	y;
	char	*tmp;

	i = 0;
	x = 0;
	y = 0;
	while (i < BOARD * BOARD)
	{
		mvprintw(y, x, ft_itoa(e->map[i]));
		x += 4;
 		refresh();
		//ft_putnbr(e->map[i]);
		//ft_putstr(tmp = ft_strdup(" "));
		//ft_strdel(&tmp);
		
		if (i % (BOARD) == BOARD - 1)
		{
			//ft_putstr(tmp = ft_strdup("\n"));
			//ft_strdel(&tmp);
			y += 2;
			x = 0;
		}
		i++;
	}
}

static unsigned int	ft_get_random(unsigned int max)
{
	srand(time(NULL));
	return (rand() % (max + 1));
}

static void		ft_init(t_env *e)
{
	int	i;
	unsigned int	init_pos[2];
	
	initscr();
	noecho();
	curs_set(FALSE);
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

static void ft_sighandler(int signum)
{
	if (signum == 2)
		endwin();
	printf("Caught signal %d, coming out...\n", signum);
	exit(1);
}
//getmaxyx

static void	ft_move_left(t_env *e)
{
	int	y;
	int	x;
	int	i;
	int	j;
	int	p[BOARD];

	y = 0;
	while (y < BOARD * BOARD)
	{
		x = 0;
		j = 0;
		while (j < BOARD)
			p[j++] = 0;
		j = 0;
		while (x < BOARD)
		{
			if (e->map[y + x] != 0)
				p[j++] = e->map[y + x];
			x++;
		}
		x = 0;
		while (x < BOARD)
		{
			e->map[y + x] = p[x];
			x++;
		}
		#ifdef EBUG
			j = 0;
			x = 10;
			while (j < BOARD)
				mvprintw(y + 10, x += 4, ft_itoa(p[j++]));
			refresh();
		#endif
		y += BOARD;
	}
}

static void	ft_game_loop(t_env *e)
{
	int	c;

	c = getch();
	while (1)
	{
		if (c == 'j')
			ft_move_left(e);
		/*else if (c == 'l')
			ft_move_right(e);
		else if (c == 'i')
			ft_move_up(e);
		else if (c == 'k')
			ft_move_down(e);*/
		//ft_new_rand(e);
		ft_print_map(e);
	}
}

int	main(void)
{
	t_env	env;
	signal(SIGINT, ft_sighandler);
	ft_init(&env);
	
	ft_print_map(&env);
	ft_game_loop(&env);
	//clear();
	sleep(5);
	endwin();
	return (0);
}
