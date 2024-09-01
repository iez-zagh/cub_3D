/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:33:23 by iez-zagh          #+#    #+#             */
/*   Updated: 2023/11/18 09:19:40 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (len >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
		len--;
	}
	return (NULL); 
}
