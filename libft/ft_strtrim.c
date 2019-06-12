/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:24:56 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/06 12:38:52 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (s)
	{
		n = ft_strlen(s);
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && (s[i]))
			i++;
		if (i == n)
			return (ft_strsub(s, i, n - i + 1));
		n--;
		while ((s[n] == ' ' || s[n] == '\n' || s[n] == '\t') && (s[n]))
			n--;
		return (ft_strsub(s, i, n - i + 1));
	}
	return (NULL);
}
