/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:27:40 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/20 21:18:33 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# include "stdlib.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_board
{
	int			matches;
	int			at_start;
}				t_board;

typedef struct	s_env
{
	int			end;
}				t_env;

/*
** read.c
*/
int			ft_get_board(const char *file_name, t_list **lst, int mode);
void		ft_disp_lst(t_list *lst);

/*
** resolution.c
*/
int			ft_game_loop(t_list **lst);

/*
** utils.c
*/
double		ft_ratio_char_len(char *str, int chr);
int			ft_xor_sum(t_list *lst);
void		ft_disp_matches(t_list *);

#endif
