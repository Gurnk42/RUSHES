/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:51:09 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/20 21:27:44 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

double	ft_ratio_char_len(char *str, int chr)
{
	int	occur;
	int	len;

	occur = 0;
	len = ft_strlen(str);
	while (*str)
	{
		if (*str == chr)
			occur++;
		str++;
	}
	return ((double)occur / len);
}

int	ft_xor_sum(t_list *lst)
{
	t_list *begin;
	int		xor;
	
	begin = lst->next;
	xor = 0;	
	while (begin)
	{
		xor = xor ^ ((t_board *)begin->content)->matches;
		begin = begin->next;
	}
	return (xor);
}

void	ft_disp_matches(t_list *lst)
{
	int	i;

	while (lst)
	{
		i = 0;
		while (i < ((t_board *)(lst->content))->matches)
		{
			ft_putstr("\033[1;31m.\033[0m");
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		i = 0;
		while (i < ((t_board *)(lst->content))->matches)
		{
			ft_putstr("\033[1;33m|\033[0m");
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		lst = lst->next;
	}
}
