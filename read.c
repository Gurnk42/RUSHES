/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:30:18 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/21 19:32:52 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "alum1.h"

void		ft_disp_lst(t_list *lst)
{
	while (lst)
	{
		ft_putnbr(((t_board *)(lst->content))->matches);
		ft_putchar('\n');
		lst = lst->next;
	}
}

static int	ft_read_board(int fd, t_list **lst)
{
	char	*str;
	t_board	*board;
	t_list	*new;
	int		i;

	while (get_next_line(fd, &str))
	{
		if ((board = (t_board *)malloc(sizeof(t_board))) == NULL)
			return (-1);
		if (str == NULL || ft_strcmp(str, (char *)"") == 0)
			return (-1);
		i = 0;
		while (str[i])
			if (ft_isdigit(str[i++]) == 0)
				return (-1);
		if (ft_atoi(str) < 1 || ft_atoi(str) > 10000)
			return (-1);
		board->matches = ft_atoi(str);
		board->at_start = board->matches;
		if ((new = ft_lstnew((void const *)board,
						(size_t)sizeof(board))) == NULL)
			return (-1);
		ft_lstadd(lst, new);
		ft_memdel((void **)(&board));
	}
	return (0);
}

int			ft_get_board(const char *file_name, t_list **lst, int mode)
{
	int		fd;

	if (mode == 1)
	{
		if ((fd = open(file_name, O_RDONLY)) == -1)
			return (-1);
		if (ft_read_board(fd, lst) == -1)
			return (-1);
		if (close(fd) == -1)
			return (-1);
	}
	else
	{
		fd = 0;
		if (ft_read_board(fd, lst) == -1)
			return (-1);
	}
	return (0);
}
