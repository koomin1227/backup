/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:16:58 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/05 23:16:59 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*new;
	t_list	*res;

	p = lst;
	res = 0;
	while (p != 0)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (new == 0)
		{
			ft_lstclear(&res, del);
			return (0);
		}
		new->content = f(p->content);
		new->next = NULL;
		ft_lstadd_back(&res, new);
		p = p->next;
	}
	return (res);
}
