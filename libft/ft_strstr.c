/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:46:06 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/06 10:29:48 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	int			x;
	const char	*p;

	i = 0;
	x = 0;
	if (ft_strlen(haystack) == 0 && ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		x = 0;
		while (haystack[i] == needle[x] && needle[x] != '\0')
		{
			i++;
			x++;
		}
		if (needle[x] == '\0')
		{
			p = &haystack[i - x];
			return ((char *)p);
		}
		i = i - x;
		i++;
	}
	return (0);
}
