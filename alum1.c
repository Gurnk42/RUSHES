/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:26:59 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/20 18:02:40 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int	main(int argc, char **argv)
{
	t_list *lst;

	lst = NULL;
	if (argc == 2)
	{
		if (ft_get_board((const char *)argv[1], &lst, 1) == -1)
		{
			ft_putstr_fd(ft_strdup("ERROR\n"), 2);
			return (-1);
		}
		ft_disp_lst(lst);
	}
	else if (argc == 1)
	{
		if (ft_get_board((const char *)argv[1], &lst, 0) == -1)
			return (-1);
		ft_disp_lst(lst);
	}
	else
	{
		ft_putstr_fd(ft_strdup("ERROR\n"), 2);
		return (-1);
	}
	ft_game_loop(&lst);
	return (0);
}
