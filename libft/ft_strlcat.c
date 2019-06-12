/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:37:08 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/06 09:25:22 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	x;
	size_t	z;

	i = ft_strlen(dst);
	x = 0;
	z = i;
	z += ft_strlen(src);
	if (dstsize > i)
	{
		while (i < (dstsize - 1) && src[x] != '\0')
		{
			dst[i] = src[x];
			i++;
			x++;
		}
		dst[i] = '\0';
	}
	else
	{
		z = ft_strlen(src) + dstsize;
	}
	return (z);
}
