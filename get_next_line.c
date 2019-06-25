/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:35:38 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/25 11:39:15 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				i;
	int				retv;
	char			*str;

	ft_putnbr(fd);
	ft_putchar('\n');
	i = 0;
	if (!(line = (char **)malloc(sizeof(char **))))
		return (-1);
	if (fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	read(fd, buf, BUFF_SIZE);
	while (buf[i] != '\n')
	{
		ft_putchar(buf[i]);
		i++;
	}
	*line = ft_strsub(buf, 0, i);
	ft_putchar('\n');
	ft_putstr(*line);
	ft_putchar('\n');
	return (0);
}

int main()
{
	int fd;
	char *path;
	static char **line;
	
	ft_putchar('\n');
	path = "/goinfre/no-conne/Desktop/get_next_line/prac.txt";
	fd = open(path, O_RDONLY);
	ft_putnbr(get_next_line(fd, line));
	return (0);
}
