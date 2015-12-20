/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:27:40 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/20 15:54:04 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

#include "stdlib.h"
#include "libft.h"
//
#include <stdio.h>
//

typedef struct	s_board
{
	int			matches;
}				t_board;

/*
** read.c
*/
int			ft_get_board(const char *file_name, t_list **lst, int mode);
void		ft_disp_lst(t_list *lst);

#endif
