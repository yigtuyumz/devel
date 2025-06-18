/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyumaz <yuyumaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 03:49:12 by yuyumaz           #+#    #+#             */
/*   Updated: 2025/06/18 16:17:01 by yuyumaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		temp = *lst;
		if (del)
			del(temp->content);
		*lst = (*lst)->next;
		free(temp);
	}
	lst = NULL;
}
