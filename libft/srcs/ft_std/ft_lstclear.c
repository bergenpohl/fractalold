/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:18:16 by bpohl             #+#    #+#             */
/*   Updated: 2020/04/16 17:52:18 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *p;
	t_list *n;

	if (!lst || !*lst || !del)
		return ;
	p = *lst;
	while (p)
	{
		n = p->next;
		ft_lstdelone(p, del);
		p = n;
	}
	*lst = NULL;
}
