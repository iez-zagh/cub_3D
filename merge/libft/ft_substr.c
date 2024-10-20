/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:43:38 by iez-zagh          #+#    #+#             */
/*   Updated: 2023/11/16 22:28:30 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		len_s;
	char		*res;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	len_s = ft_strlen(&s[start]);
	if (len_s < len)
		len = len_s;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	s = s + start;
	while (s[i] != '\0' && len > 0)
	{
		res[i] = s[i];
		i++;
		len--;
	}
	res[i] = '\0';
	return (res);
}
