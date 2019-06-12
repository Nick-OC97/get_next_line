/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 08:19:12 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/04 12:10:06 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	checker(const char *str, int i)
{
	if (str[i] == '-' && (str[i + 1] == '+' || str[i + 1] == '-'))
		return (0);
	if (str[i] == '+' && (str[i + 1] == '-' || str[i + 1] == '+'))
		return (0);
	return (1);
}

int			ft_atoi(const char *str)
{
	int i;
	int num;
	int sign;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (checker(str, i) == 0)
		return (0);
	while (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (sign * num);
}
