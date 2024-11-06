/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:52:39 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/06 00:51:52 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_copy(char const *s)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	if (!s2)
		return ((char *)s1);
	if (!s1)
		return (ft_copy(s2));
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
	free((char *)s1);
	return (res);
}
