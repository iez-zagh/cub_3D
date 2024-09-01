/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:26:16 by iez-zagh          #+#    #+#             */
/*   Updated: 2023/11/17 15:22:18 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*limorah;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		limorah = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = limorah;
	}
}
