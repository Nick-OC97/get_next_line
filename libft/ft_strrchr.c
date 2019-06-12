/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 10:52:03 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/06 09:26:38 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (s[i] != '\0')
	{
		i++;
		p++;
	}
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
		p--;
	}
	if (*s == '\0' && c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
