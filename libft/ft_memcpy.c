/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:46:20 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/06 08:53:09 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*astr1;
	unsigned const char	*astr2;

	i = 0;
	if (!dst && !src)
		return (NULL);
	astr1 = dst;
	astr2 = src;
	while (i < n)
	{
		astr1[i] = astr2[i];
		i++;
	}
	return (dst);
}
