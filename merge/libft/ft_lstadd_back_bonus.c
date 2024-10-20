/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:35:04 by iez-zagh          #+#    #+#             */
/*   Updated: 2023/11/17 18:20:10 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*n_adrs;

	if (!new || !lst)
		return ;
	if (*lst)
	{
		n_adrs = ft_lstlast(*lst);
		n_adrs->next = new;
		return ;
	}
	*lst = new;
}
