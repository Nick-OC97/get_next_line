/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:59:38 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/05 12:39:48 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *cpy;
	t_list *start;

	if (!lst || !f)
		return (NULL);
	cpy = f(lst);
	if (!(new = ft_lstnew(cpy->content, cpy->content_size)))
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst)
	{
		cpy = f(lst);
		if (!(new->next = ft_lstnew(cpy->content, cpy->content_size)))
			return (NULL);
		lst = lst->next;
		new = new->next;
	}
	return (start);
}
