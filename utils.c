/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:51:09 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/21 16:45:10 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void		ft_del_first_node(t_list **lst)
{
	t_list *tmp;

	if (lst == NULL)
		return ;
	if (*lst)
	{
		tmp = (*lst)->next;
		if (tmp)
		{
			free((void *)((t_board *)(*lst)->content));
			free((void *)(*lst));
			*lst = tmp;
		}
	}
}

double		ft_ratio_char_len(char *str, int chr)
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

int			ft_xor_sum(t_list *lst)
{
	t_list	*begin;
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

void		ft_disp_matches(t_list *lst)
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

int	ft_input_error(t_list **lst, int nb)
{
	if (nb > 3 || nb < 1)	
	{
		ft_putendl("CHOOSE A NUMBER FROM 1 TO 3");
		ft_player(lst);
		return (-1);
	}
	if (((t_board *)((*lst)->content))->matches - nb < 0)
	{
		ft_putendl("YOUR NUMBER IS WAY TO BIG !!!");
		ft_player(lst);
		return (-1);
	}
	return (0);
}
