#ifndef GAME_H
# define GAME_H
# include <time.h>
# include <curses.h>
# include <signal.h>
# include "libft.h"

//# define WIN_VALUE 2048 //CHECK if %2 == 0
# define BOARD 4

enum e_const
{
	WIN_VALUE = 2048
};

typedef struct	s_env
{
	int	*map;
	time_t	start;
	time_t	end;
	int		dbg;
}		t_env;

typedef struct	s_move
{
	int	y;
	int	x;
	int	j;
	int	diff;
	int	p[BOARD];
}				t_move;

/*
** move.c
*/
unsigned int	ft_move_left(t_env *e);
unsigned int	ft_move_right(t_env *e);
unsigned int	ft_move_up(t_env *e);
unsigned int	ft_move_down(t_env *e);

/*
** fill.c
*/
void			ft_fill_left(int (*p)[BOARD], int *y, t_env *e);
void			ft_fill_right(int (*p)[BOARD], int *y, t_env *e);
void			ft_fill_up(int (*p)[BOARD], int *y, t_env *e);
void			ft_fill_down(int (*p)[BOARD], int *y, t_env *e);

/*
** push.c
*/
void		ft_push_right(int (*p)[BOARD]);
void		ft_push_left(int (*p)[BOARD]);

/*
** utils.c
*/
void		ft_print_map(t_env *e);
void		ft_sighandler(int signum);

#endif
