/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:05:47 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/20 16:49:09 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_correct_file(t_list **file, int fd)
{
	t_list		*tmp;
	tmp = *file;
	while(tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*file;
	int				i;
	int				ret;
	t_list			*cur;
	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	cur = get_correct_file(&file, fd);
	MALLCHECK((*line = ft_strnew(1)));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		MALLCHECK((cur->content = ft_strjoin(cur->content, buf)));
		if (ft_strchr(buf, '\n'))
				break;
	}
	if (ret < BUFF_SIZE && !ft_strlen(cur->content))
		return (0);
	i = ft_copyuntil(line, cur->content, '\n');
	(i < (int)ft_strlen(cur->content))
		? cur->content += (i + 1)
		: ft_strclr(cur->content);
	return (1);
}
