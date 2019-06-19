/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 10:43:53 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/19 15:36:41 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include "./libft/includes/libft.h"
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 32
#define MALLCHECK(x) if (!x) return (-1);

int		get_next_line(int fd, char **line);

#endif
