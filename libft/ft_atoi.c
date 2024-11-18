/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:31:28 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/18 15:52:52 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;
	long	tmp;

	res = 0;
	sign = 1;
	i = ft_check(str, &sign);
	while (ft_isdigit(str[i]))
	{
		tmp = res;
		res = (res * 10) + (str[i] - 48);
		if ((tmp != res / 10) && sign == 1)
			return (-1);
		else if ((tmp != res / 10) && sign == -1)
			return (0);
		i++;
	}
	return (res * sign);
}
