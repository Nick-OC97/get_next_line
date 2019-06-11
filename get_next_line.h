/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:36:00 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/11 13:03:28 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 32

int		get_next_line(const int fd, char **line);

#endif
