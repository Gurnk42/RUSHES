/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:34:26 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/20 20:51:14 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"
//
#include <stdio.h>
//

static void	ft_del_first_node(t_list **lst)
{
	t_list *tmp;
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

static int ft_best_sol(t_list *lst)
{
	int		matches;
	double	xor_sum_zeros[3];
	int		xor;
	int		solution;
   
	xor = ft_xor_sum(lst);
	matches = ((t_board *)(lst)->content)->matches;
	xor_sum_zeros[0] = ft_ratio_char_len(ft_ntoa_base((long long)(xor ^ (matches - 1)), ft_strdup("01")), '1');
	xor_sum_zeros[1] = ft_ratio_char_len(ft_ntoa_base((long long)(xor ^ (matches - 2)), ft_strdup("01")), '1');
	xor_sum_zeros[2] = ft_ratio_char_len(ft_ntoa_base((long long)(xor ^ (matches - 3)), ft_strdup("01")), '1');
//	printf("xor_sum_zeros[0] '%f'\n", xor_sum_zeros[0]);
//	printf("xor_sum_zeros[1] '%f'\n", xor_sum_zeros[1]);
//	printf("xor_sum_zeros[2] '%f'\n", xor_sum_zeros[2]);
	if ((xor_sum_zeros[0] >= xor_sum_zeros[1] && xor_sum_zeros[0] >= xor_sum_zeros[2]) && (matches - 1) >= 0)
		solution = 1;
	if ((xor_sum_zeros[1] >= xor_sum_zeros[0] && xor_sum_zeros[1] >= xor_sum_zeros[2]) && (matches - 2) >= 0)
		solution = 2;
	if ((xor_sum_zeros[2] >= xor_sum_zeros[1] && xor_sum_zeros[2] >= xor_sum_zeros[0]) && (matches - 3) >= 0)
		solution = 3;
	printf("AI removed '%d' matches\n", solution);
	return (solution);
}

static int ft_ia(t_list **lst)
{
	//t_list *begin;
	//begin = *lst;
	ft_putendl("IA's TURN");
	((t_board *)((*lst)->content))->matches -= ft_best_sol(*lst);
	if (((t_board *)((*lst)->content))->matches == 0)
	{
		if ((*lst)->next != NULL)
			ft_del_first_node(lst);
		else
		{
			ft_putendl("YOU WIN !");
			return (0);
		}
	}
	return (0);
}

static int ft_player(t_list **lst)
{
	char	*str;
	int		nb;

	ft_putendl("YOUR TURN");
	get_next_line(0, &str);
	nb = ft_atoi(str);
	if (nb > 3 || nb < 1)	
	{
		ft_putendl("CHOOSE A NUMBER FROM 1 TO 3");
		ft_player(lst);
		return (0);
	}
	if (((t_board *)((*lst)->content))->matches - nb < 0)
	{
		ft_putendl("YOUR NUMBER IS WAY TO BIG !!!");
		ft_player(lst);
		return (0);
	}
	else
		((t_board *)((*lst)->content))->matches -= nb;
	if (((t_board *)((*lst)->content))->matches == 0)
	{
		if ((*lst)->next != NULL)
			ft_del_first_node(lst);
		else
		{
			ft_putendl("YOU LOSE !");
			return (1);
		}
	}
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
		if (ft_player(lst) == 1)
			return (0);
		while (beg)
		{
			if (beg->next == NULL && (((t_board *)(beg->content))->matches == 0))
				return (0);
			beg = beg->next;
		}
		ft_disp_lst(*lst);
		beg = *lst;
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
