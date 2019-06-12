/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:14:54 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/06 11:43:39 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	x;

	i = 0;
	if (s && f)
	{
		x = ft_strlen(s);
		while (i < x)
		{
			(*f)(i, s);
			i++;
			s++;
		}
	}
}
