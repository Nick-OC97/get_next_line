/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:35:38 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/27 14:19:27 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join(char *s1, char *s2)
{
	size_t	size;
	char	*newstring;

	size = ft_strlen(s1) + ft_strlen(s2);
	newstring = (char *)malloc(sizeof(char) * size + 1);
	ft_strcpy(newstring, s1);
	ft_strcat(newstring, s2);
	newstring[size] = '\0';
	return (newstring);
}

int		read_chunk(int fd, char **buffer)
{
	char	*placeholder;
	char	temporary[BUFF_SIZE + 1];
	ssize_t	size;

	size = read(fd, temporary, BUFF_SIZE);
	if (size < 1)
		return (size);
	temporary[size] = '\0';
	placeholder = join(*buffer, temporary);
	free(*buffer);
	*buffer = ft_strdup(placeholder);
	return (1);
}

int		from_where(char *string, char c)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*static_buffer;
	int			error_code;

	static_buffer = NULL;
	if (static_buffer == NULL)
		static_buffer = (char *)malloc(sizeof(char));
	while (ft_strchr(static_buffer, '\n') == NULL)
	{
		error_code = read_chunk(fd, &static_buffer);
		if (error_code < 1)
			return (error_code);
	}
	*line = ft_strsub(static_buffer, 0, from_where(static_buffer, '\n'));
	static_buffer = ft_strchr(static_buffer, '\n');
	static_buffer++;
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
