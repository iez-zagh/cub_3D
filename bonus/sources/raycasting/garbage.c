/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:59:07 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/03 18:07:58 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	*ft_malloc(size_t size)
{
	static	t_node	*node = NULL;
	t_node		*new;

	void *ptr = malloc(size);
	if (!ptr)
		return NULL;
	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->ptr = ptr;
	// ft_lstadd_back(&node, )
	return ptr;
}
