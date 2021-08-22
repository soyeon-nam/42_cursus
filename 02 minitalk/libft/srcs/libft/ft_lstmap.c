/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:32:35 by snam              #+#    #+#             */
/*   Updated: 2021/05/20 21:26:46 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), \
void (*del)(void *))
{
	t_list		*new_lst;
	t_list		*new_lst_ret;

	if (!lst || !f)
		return (0);
	new_lst_ret = 0;
	while (lst)
	{
		new_lst = ft_lstnew(f(lst->content));
		if (!new_lst)
		{
			ft_lstclear(&new_lst_ret, del);
			return (0);
		}
		ft_lstadd_back(&new_lst_ret, new_lst);
		lst = lst->next;
	}
	return (new_lst_ret);
}
