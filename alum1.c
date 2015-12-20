/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:26:59 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/20 12:35:19 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int	main(int argc, char **argv)
{
	t_list *lst;

	if (argc != 2)
	{
		ft_putstr_fd(ft_strdup("ERROR\n"), 2);
		return (-1);
	}
	ft_get_board((const char *)argv[1], &lst);
	ft_disp_lst(lst);
	return (0);
}
