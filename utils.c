/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:51:09 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/20 20:36:34 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

double	ft_ratio_zeros_len(char *str)
{
	int	occur_one;
	int	occur_zero;
	int	len;

	occur_zero = 0;
	occur_one = 0;
	len = ft_strlen(str);
	while (*str)
	{
		if (*str == '0')
			occur_zero++;
		if (*str == '1')
			occur_one++;
		str++;
	}
	return ((double)occur_one / len);
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
