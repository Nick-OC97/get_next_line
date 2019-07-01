/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:35:38 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/01 15:07:37 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		add_to_str(int fd, char *str)
{
	char	*placeholder;
	char	temporary[BUFF_SIZE + 1];
	ssize_t	size;

	size = read(fd, temporary, BUFF_SIZE);
	if (size < 1)
		return (size);
	temporary[size] = '\0';
	ft_strjoin(str[fd], temporary);
	return (1);
}

int		end(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[1024];
	int			error_code;

	if (!(str[fd]))
		str[fd] = ft_strnew(0);
	while(ft_strchr(str[fd], '\n') == NULL)
	{
		error_code = add_to_str(fd, str[fd]);
		if (error_code < 1)
			return (error_code);
	}
	*line = ft_strsub(str[fd], 0, end(str[fd], '\n'));
	return (1);
}

int		main(int argc, char **argv)
{
	int	fd;
	char *buffer;

	buffer = (char *)malloc(sizeof(char) * 1024);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &buffer);
	ft_putstr(buffer);
	ft_putchar('\n');
	get_next_line(fd, &buffer);
	ft_putstr(buffer);
	while (get_next_line(fd, &buffer) > 0)
	{
		ft_putchar('\n');
		ft_putstr(buffer);
	}
}
