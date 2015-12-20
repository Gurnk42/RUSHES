/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:30:18 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/20 12:48:39 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
# include "get_next_line.h"
#include "alum1.h"

void		ft_disp_lst(t_list *lst)
{
	while (lst)
	{
		ft_putstr("new\n");
		/*if (lst)
		{
			ft_putnbr(((t_board *)(lst->content))->matches);
			ft_putchar('\n');
		}
		if (lst->next == NULL)
		{
			ft_putstr("end");
			break;
		}*/
		lst = lst->next;
	}
}

static void	ft_read_board(int fd, t_list **lst)
{
	char	*str;
	t_board	*board;
	t_list	*new;

	while (get_next_line(fd, &str))
	{
		board = (t_board *)malloc(sizeof(t_board));
		board->matches = ft_atoi(str);
		if (ft_strcmp(str, ft_strdup("")) != 0)
		{
			ft_putstr("NEW\n");
			new = ft_lstnew((void const *)board, (size_t)sizeof(board));
			new->next = NULL;
			ft_lstadd(lst, new);
			//ft_memdel((void **)(&new));
		}
		if (str[ft_strlen(str)] != '\n')
		{
			printf("CHAR : '%c'\n", str[ft_strlen(str)]);
			ft_putstr_fd(ft_strdup("ERROR\n"), 2);
		}

		ft_memdel((void **)(&board));
	}
}

void		ft_get_board(const char *file_name, t_list **lst)
{
	int		fd;
	
	*lst = (t_list *)malloc(sizeof(t_list));
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_putstr_fd(ft_strdup("ERROR\n"), 2);
	ft_read_board(fd, lst);
	if (close(fd) == -1)
		ft_putstr_fd(ft_strdup("ERROR\n"), 2);
}
