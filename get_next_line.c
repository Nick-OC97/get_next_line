/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:12:51 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/01 09:42:46 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*add_to_str(char *str, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(str, buff);
	free(str);
	return (tmp);
}

char	*ft_putline(char **line, char *str)
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

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*str[1024];

	ret = 0;
	if (!(line) || read(fd, buff, 0) == -1 || fd < 0)
		return (-1);
	if (!(str[fd]))
		str[fd] = ft_strnew(0);
	if (!(ft_strchr(str[fd], '\n')))
	{
		while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			str[fd] = add_to_str(str[fd], buff);
			if (ft_strchr(str[fd], '\n'))
				break ;
		}
	}
	if (ret == 0 && !(ft_strlen(str[fd])))
		return (0);
	str[fd] = ft_putline(line, str[fd]);
	return (1);
}
