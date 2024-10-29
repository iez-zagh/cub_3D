/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:23:43 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/29 12:08:44 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <libc.h>

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
	return (d);
}
int main()
{
	char *str = malloc(5);
	if (!str)
		return 1;
	str[0] = 'h';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = '\0';
	printf("%s]]\n", ft_memset(str, 0, 2));
}