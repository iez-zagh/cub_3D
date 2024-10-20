/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:01:20 by iez-zagh          #+#    #+#             */
/*   Updated: 2023/11/10 22:34:14 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (*find == 0)
		return ((char *)str);
	len = ft_strlen(find);
	while (i < n && str[i])
	{
		if (str[i] == *find && len <= n - i
			&& ft_strncmp(&str[i], find, len) == 0)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
