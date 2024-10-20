/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:55:02 by iez-zagh          #+#    #+#             */
/*   Updated: 2023/11/09 22:52:48 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ar9am(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_t3mar(char *str, int tol, int i1, int n1)
{
	while (tol-- > i1)
	{
		str[tol] = '0' + n1 % 10;
		n1 /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*res;
	int		old_len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ar9am(n);
	old_len = len;
	res = malloc (sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
		i = 1;
	}
	else
		i = 0;
	res = ft_t3mar(res, len, i, n);
	res[old_len] = '\0';
	return (res); 
}
