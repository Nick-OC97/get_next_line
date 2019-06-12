/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:15:27 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/06 08:59:06 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*astr1;
	const unsigned char	*astr2;

	i = len;
	astr1 = dst;
	astr2 = src;
	if (astr2 < astr1)
	{
		while (i--)
		{
			astr1[i] = astr2[i];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (astr1);
}
