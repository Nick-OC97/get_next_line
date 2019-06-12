/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 07:35:28 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/06 09:07:26 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*c;
	unsigned const char	*d;

	i = 0;
	c = s1;
	d = s2;
	while (i < n)
	{
		if (c[i] != d[i])
			return (c[i] - d[i]);
		if (c[i] == d[i])
			i++;
	}
	return (0);
}
