/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 08:34:59 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/25 08:58:28 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int fd;
	char *path;
	char buf[BUFF_SIZE + 1];
	char **line;

	/*write*/
	path = "/goinfre/no-conne/Desktop/get_next_line/prac.txt";
	fd = open(path, O_CREAT | O_WRONLY, 0600);
	write(fd, "Hello World!\n", 13);
	close(fd);
	
	/*read*/
	fd = open(path, O_RDONLY);
	read(fd, buf, 13);
	buf[13] = '\0';
	close(fd);

	ft_putstr(buf);
	return (0);
}
