/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_art.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:57:31 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/21 16:25:32 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static void	ft_win(void)
{
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putstr(" /$$      /$$ /$$                 /$$");
	ft_putchar('\n');
	ft_putstr("| $$  /$ | $$|__/                | $$");
	ft_putchar('\n');
	ft_putstr("| $$ /$$$| $$ /$$ /$$$$$$$       | $$");
	ft_putchar('\n');
	ft_putstr("| $$/$$ $$ $$| $$| $$__  $$      | $$");
	ft_putchar('\n');
	ft_putstr("| $$$$_  $$$$| $$| $$  \\ $$      |__/");
	ft_putchar('\n');
	ft_putstr("| $$$/ \\  $$$| $$| $$  | $$");
	ft_putchar('\n');
	ft_putstr("| $$/   \\  $$| $$| $$  | $$       /$$");
	ft_putchar('\n');
	ft_putstr("|__/     \\__/|__/|__/  |__/      |__/");
	ft_putchar('\n');
	ft_putstr("\033[0m");
}

void		ft_you_win(void)
{
	ft_putstr((char *)"\033[H\033[J");
	ft_putstr("\033[1;33m");
	ft_putstr(" /$$     /$$");
	ft_putchar('\n');
	ft_putstr("|  $$   /$$/");
	ft_putchar('\n');
	ft_putstr("\\  $$ /$$//$$$$$$  /$$   /$$");
	ft_putchar('\n');
	ft_putstr(" \\  $$$$//$$__  $$| $$  | $$");
	ft_putchar('\n');
	ft_putstr("  \\  $$/| $$  \\ $$| $$  | $$");
	ft_putchar('\n');
	ft_putstr("   | $$ | $$  | $$| $$  | $$");
	ft_putchar('\n');
	ft_putstr("   | $$ |  $$$$$$/|  $$$$$$/");
	ft_putchar('\n');
	ft_putstr("   |__/  \\______/  \\______/");
	ft_win();
}
