/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:35:38 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/13 10:56:56 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*int		get_next_line(const int fd, char **line)
{
	char	*dump;
	int 	i;

	i = 1;
	read(fd, dump, (BUFF_SIZE));
	while (i != -1)
	{
		read(fd, dump, (BUFF_SIZE) * i);	
		if (ft_strchr(dump, '\n') == NULL)
			i++;
		else
			i = -1;
		ft_putstr(dump);
		ft_strclr(dump);
	}
	i = 0;
	while (dump[i] != '\n')
		i++;
	dump = ft_strsub(dump, 0, i);
	ft_putstr(dump);
	return (0);
}*/

int main()
{
	int fd;
	char *path;
	char **line;

	path = "/goinfre/no-conne/Desktop/get_next_line/prac.txt";
	fd = open(path, O_WRONLY, 0600);
	get_next_line(fd, line);
	return (0);
}
