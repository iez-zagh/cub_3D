/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_c_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:51:41 by zmaghdao          #+#    #+#             */
/*   Updated: 2024/11/16 17:56:22 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	_counter(char *tab)
{
	int	i;
	int	comas;

	i = 0;
	comas = 0;
	while (tab[i])
	{
		if (tab[i] == ',')
			comas++;
		i++;
	}
	return (comas);
}

int	checker_tab(char *tab)
{
	int	i;

	i = 0;
	while (ft_isspace(tab[i]))
		i++;
	if (tab[i] == '\0')
		return (-1);
	while (tab[i] && !ft_isspace(tab[i]))
	{
		if (!ft_isdigit(tab[i]))
			return (-1);
		i++;
	}
	while (ft_isspace(tab[i]))
		i++;
	if (tab[i] != '\0')
		return (-1);
	return (0);
}

int	fc_checker(char *coor, char *str, int cfrgb[3])
{
	int		i;
	char	**tab;
	int		tmp;

	i = 1;
	if (coor[0] != str[0] || !ft_isspace(coor[1]) || _counter(coor) != 2)
		return (-8);
	while (ft_isspace(coor[i]))
		i++;
	if (ft_isdigit(coor[i]) == 0)
		return (-8);
	tab = ft_split(coor + i, ',');
	if (!tab)
		return (-2);
	i = -1;
	while (tab[++i])
	{
		if (!tab[i][0] || checker_tab(tab[i]) < 0 || i > 2)
			return (ft_free_par(tab), -8);
		tmp = ft_atoi(tab[i]);
		if (tmp < 0 || tmp > 255)
			return (puts("here"), ft_free_par(tab), -9);
		cfrgb[i] = tmp;
	}
	return (ft_free_par(tab), 0);
}

int	f_c_checker(t_map *map)
{
	int	stat;

	stat = fc_checker(map->fcolor, "F", map->frgb);
	if (stat < 0)
		return (stat);
	stat = fc_checker(map->ccolor, "C", map->crgb);
	if (stat < 0)
		return (stat);
	return (0);
}
