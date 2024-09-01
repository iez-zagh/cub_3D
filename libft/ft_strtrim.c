/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:49:15 by iez-zagh          #+#    #+#             */
/*   Updated: 2023/11/16 22:22:27 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	t9lab(const char *s1, char c)
{
	while (*s1)
	{
		if (*s1 == c)
			return (1);
		s1++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*res;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && t9lab(set, s1[start]) == 1)
		start++;
	while (end > start && t9lab(set, s1[end]) == 1)
		end--;
	len = end - start + 1;
	if (len == 0)
	{
		res = ft_strdup("");
	}
	else
	{
		res = ft_substr(s1, start, len);
	}
	return (res);
}
