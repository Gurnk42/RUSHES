/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 18:06:51 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/21 18:39:01 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) - 1)))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcpy(str + ft_strlen(s1), s2);
	return (str);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2)) - 1))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcpy(str + ft_strlen(s1), s2);
	ft_strclr(s1);
	ft_strclr(s2);
	return (str);
}
