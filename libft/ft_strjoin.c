/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:52:39 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/01 17:38:42 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	if (!s2)
		return ((char *)s1); // remember to copy the s1
	puts("hello mwore");
	// if (!s1)
	// {
	// 	ft_strlcpy(res, s2, ft_strlen(s2));
	// 	return ()
	// }
	res = NULL;
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	len = ft_strlen(s1);
	i = 0;
	while (s2[i])
	{
		res[len++] = s2[i++];
	}
	res[len] = '\0';
	return (res);
}
