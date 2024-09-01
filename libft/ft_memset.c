/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:23:43 by iez-zagh          #+#    #+#             */
/*   Updated: 2023/11/18 09:18:39 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	s;

	d = str;
	s = (unsigned char)value;
	i = 0;
	while (i < len)
	{
		d[i] = s;
		i++;
	}
	return (str);
}
