/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:59:07 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/04 14:45:22 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	*ft_malloc(size_t size)
{
	static	t_list	**node = NULL;
	t_list			*new;

	void *ptr = malloc(size);
	if (!ptr)
		return NULL;
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = ptr;
	new->next = NULL;
	ft_lstadd_back(node, new);
	return ptr;
}
