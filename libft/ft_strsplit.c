/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:30:26 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/04 10:38:48 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(const char *s, char c, int n)
{
	while (s[n] != c && s[n] != '\0')
	{
		n++;
	}
	return (n);
}

static int	word_count(const char *s, char c)
{
	int		cnt;
	int		i;

	cnt = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			cnt++;
			i = counter(s, c, i) - 1;
		}
		i++;
	}
	return (cnt);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		n;
	int		x;
	char	**new;

	i = 0;
	x = 0;
	if (!s || !c)
		return (NULL);
	if (!(new = (char **)malloc(sizeof(*new) * (word_count(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			n = counter(s, c, i);
			new[x] = ft_strsub(s, i, n - i);
			x++;
			i = n - 1;
		}
		i++;
	}
	new[x] = (void *)'\0';
	return (new);
}
