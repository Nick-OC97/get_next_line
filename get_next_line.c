/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:30:06 by no-conne          #+#    #+#             */
/*   Updated: 2019/10/08 17:30:50 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static char		*add(char *str, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(str, buff);
	free(str);
	return (tmp);
}

static char		*setline(char **line, char *str)
{
	int		len;
	char	*tmp;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	*line = ft_strsub(str, 0, len);
	if (ft_strcmp(*line, str) == 0)
		return (NULL);
	else
	{
		tmp = ft_strsub(str, len + 1, ft_strlen(str + len + 1));
		free(str);
	}
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str[1024];
	char		buff[BUFF_SIZE + 1];
	int			size;

	size = 0;
	if (!(line) || (read(fd, buff, 0) < 0) || (fd < 0))
		return (-1);
	if ((str[fd]) == NULL)
		str[fd] = ft_strnew(0);
	if (!(ft_strchr(str[fd], '\n')))
	{
		while ((size = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[size] = '\0';
			str[fd] = add(str[fd], buff);
			if (ft_strchr(str[fd], '\n'))
				break ;
		}
	}
	if (size == 0 && !(ft_strlen(str[fd])))
		return (0);
	str[fd] = setline(line, str[fd]);
	return (1);
}
