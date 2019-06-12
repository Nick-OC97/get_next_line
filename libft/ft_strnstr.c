/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:19:47 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/06 10:41:06 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			x;
	const char		*p;

	i = 0;
	p = haystack;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		x = 0;
		while (haystack[i] == needle[x] && needle[x] != '\0' && i < len)
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
	return (NULL);
}
