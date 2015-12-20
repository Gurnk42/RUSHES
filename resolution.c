/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:34:26 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/20 18:37:30 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"
//
#include <stdio.h>
//

static void	ft_del_first_node(t_list **lst)
{
	t_list tmp;
	if (lst == NULL)
		return ;
	if (*lst)
	{
		tmp = (*lst)->next;
		if (tmp)
		{
			free((void *)(*lst));
			*lst = tmp;
		}
	}
}

static int ft_ia(t_list **lst)
{
	t_list *begin;
	int	xor;

	xor = 0;
	begin = *lst;
	while (*lst)
	{
		printf("matches '%d'\n", ((t_board *)(*lst)->content)->matches);
		xor = xor ^ ((t_board *)(*lst)->content)->matches;
		*lst = (*lst)->next;
	}
	printf("xor : '%d'\n", xor);
	return (0);
}

static int ft_player(t_list **lst)i
{
	char	*str;
	int		nb;

	get_next_line(0, &str);
	nb = ft_atoi(str);
	((t_board *)((*lst)->content))->matches -= nb;
	if (((t_board *)((*lst)->content))->matches < 0)
		ft_player(lst);
	if (((t_board *)((*lst)->content))->matches == 0)
		ft_del_first_node(lst);
	return (0);
}

int	ft_game_loop(t_list **lst)
{
	//t_env	env;
	t_list	*beg;
	int		pos;

	while (1)
	{
		pos = 0;
		beg = *lst;
		ft_player(lst);
		ft_ia(lst);
		while (beg)
		{
			if (beg->next == NULL && (((t_board *)(beg->content))->matches == 0))
				return (0);
			beg = beg->next;
		}
		ft_disp_lst(*lst);
	}
	return (0);
}
