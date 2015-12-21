/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:26:59 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/21 21:36:45 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	ft_map_input(int argc, char **argv, t_list **lst)
{
	if (argc == 2)
	{
		if (ft_get_board((const char *)argv[1], lst, 1) == -1)
		{
			ft_putstr_fd((char *)"ERROR\n", 2);
			return (-1);
		}
		ft_disp_matches(*lst);
	}
	else if (argc == 1)
	{
		if (ft_get_board((const char *)argv[1], lst, 0) == -1)
		{
			ft_putstr_fd((char *)"ERROR\n", 2);
			return (-1);
		}
		ft_disp_matches(*lst);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_list *lst;

	lst = NULL;

	if (argc != 2 && argc != 1)
	{
		ft_putstr_fd((char *)"ERROR\n", 2);
		return (-1);
	}
	if (ft_map_input(argc, argv, &lst) == -1)
		return (-1);
	ft_game_loop(&lst);
	return (0);
}
