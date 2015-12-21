/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:34:26 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/21 21:42:39 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	ft_best_sol_for_classic_nim(t_list *lst)
{
	int		matches;
	double	xor_sum_zeros[3];
	int		xor;
	int		solution;

	xor = ft_xor_sum(lst);
	matches = ((t_board *)(lst)->content)->matches;
	xor_sum_zeros[0] = ft_ratio_char_len(ft_ntoa_base(
		(long long)(xor ^ (matches - 1)), ft_strdup("01")), '1');
	xor_sum_zeros[1] = ft_ratio_char_len(ft_ntoa_base(
		(long long)(xor ^ (matches - 2)), ft_strdup("01")), '1');
	xor_sum_zeros[2] = ft_ratio_char_len(ft_ntoa_base(
		(long long)(xor ^ (matches - 3)), ft_strdup("01")), '1');
	if ((xor_sum_zeros[0] >= xor_sum_zeros[1] && xor_sum_zeros[0]
		>= xor_sum_zeros[2]) && (matches - 1) >= 0)
		solution = 1;
	if ((xor_sum_zeros[1] >= xor_sum_zeros[0] && xor_sum_zeros[1]
		>= xor_sum_zeros[2]) && (matches - 2) >= 0)
		solution = 2;
	if ((xor_sum_zeros[2] >= xor_sum_zeros[1] && xor_sum_zeros[2]
		>= xor_sum_zeros[0]) && (matches - 3) >= 0)
		solution = 3;
	return (solution);
}

static int	ft_best_sol(t_list *lst)
{
	int	i;
	int sol;
	int	matches;

	i = 0;
	sol = 0;
	matches = ((t_board *)(lst)->content)->matches;
	while ((((i * 4) + 1)) < matches)
	{
		sol = matches - ((i * 4) + 1);
		i++;
	}
	if (sol == 0)
		sol = 1;
	if (AI == 1)
		return (ft_best_sol_for_classic_nim(lst));
	return (sol);
}

static int	ft_ia(t_list **lst)
{
	int	sol;

	sol = ft_best_sol(*lst);
	((t_board *)((*lst)->content))->matches -= sol;
	ft_putstr((char *)"\n\033[1;31mAI removed ");
	ft_putnbr(sol);
	ft_putstr((char *)" matches.\033[0m\n");
	if (((t_board *)((*lst)->content))->matches == 0)
	{
		if ((*lst)->next != NULL)
			ft_del_first_node(lst);
		else
			ft_you_win();
	}
	return (0);
}

int			ft_player(t_list **lst)
{
	char	*str;
	int		nb;

	ft_putstr((char *)"\n\033[1;32mYour turn: ");
	get_next_line(1, &str);
	nb = ft_atoi(str);
	if (ft_input_error(lst, nb) == -1)
		return (0);
	else
		((t_board *)((*lst)->content))->matches -= nb;
	ft_putstr((char *)"\n\033[1;32mYou removed ");
	ft_putnbr(nb);
	ft_putstr((char *)" matches.\033[0m\n");
	if (((t_board *)((*lst)->content))->matches == 0)
	{
		if ((*lst)->next != NULL)
			ft_del_first_node(lst);
		else
		{
			ft_you_lose();
			return (1);
		}
	}
	return (0);
}

int			ft_game_loop(t_list **lst)
{
	t_list		*beg;
	int			pos;
	static int	round = 0;

	while (1)
	{
		pos = 0;
		beg = *lst;
		if ((round % 2) == 0)
		{
			if (ft_player(lst) == 1)
				return (0);
		}
		else
			ft_ia(lst);
		while (beg)
		{
			if (beg->next == NULL && !(((t_board *)(beg->content))->matches))
				return (0);
			beg = beg->next;
		}
		ft_disp_matches(*lst);
		round++;
	}
	return (0);
}
