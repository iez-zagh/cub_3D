/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:00:48 by zmaghdao          #+#    #+#             */
/*   Updated: 2024/11/04 23:04:59 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	fill_lines(int *i, char ***new_map, int lenght, int max)
{
	int	strlen;

	while ((*i) < max)
	{
		1 && (strlen = 0, (*new_map)[(*i)] = ft_strdup("22222222"));
		if (!(*new_map)[(*i)])
			return (-2);
		while (strlen < lenght)
		{
			(*new_map)[(*i)] = ft_strjoin((*new_map)[(*i)], "2");
			if (!(*new_map)[(*i)])
				return (-2);
			strlen++;
		}
		(*i)++;
	}
	return (0);
}

int	_xtra_map(char ***map, int lenght, int lines, t_data *data)
{
	int		i;
	int		len;
	int		k;
	char	**new_map;

	1 && (i = 0, new_map = (char **)malloc(sizeof(char *) * (lines + 9)));
	if (!new_map)
		return (-2);
	if (fill_lines(&i, &new_map, lenght, 4) < 0)
		return (ft_free_par(*map), ft_free_par(new_map), -2);
	k = 0;
	while ((*map)[k])
	{
		new_map[i] = ft_strjoin(ft_strdup("22222222"), (*map)[k]);
		if (!new_map[i])
			return (ft_free_par(*map), ft_free_par(new_map), -2);
		1 && (i++, k++);
	}
	if (fill_lines(&i, &new_map, lenght, lines + 8) < 0)
		return (ft_free_par(*map), ft_free_par(new_map), -2);
	new_map[i] = NULL;
	1 && (data->clmn_n += 8, data->rows_n += 5);
	return (ft_free_par(*map), data->map.map = new_map, 0);
}

int	last_check(char **map, t_data *data)
{
	int	idx[2];
	int	count;

	idx[0] = 0;
	count = 0;
	while (map[idx[0]])
	{
		idx[1] = 0;
		while (map[idx[0]][idx[1]])
		{
			if (map[idx[0]][idx[1]] == 'N' || map[idx[0]][idx[1]] == 'S'
				|| map[idx[0]][idx[1]] == 'W' || map[idx[0]][idx[1]] == 'E')
			{
				count++;
				angle_init(map[idx[0]][idx[1]], data);
				data->player->x = idx[1] + 8;
				data->player->y = idx[0] + 4;
			}
			idx[1]++;
		}
		idx[0]++;
	}
	if (count != 1)
		return (-15);
	return (_xtra_map(&map, data->clmn_n + 8, data->rows_n, data));
}

int	char_checker(char **map, int i, int j)
{
	if (is_map_char(map[i][j]) == 1 && map[i][j] != ' ')
		return (-11);
	else if ((map[i][j] == '0' || is_player(map[i][j]))
		&& check_directions(map, i, j, 1) != 0)
		return (-12);
	else if (map[i][j] == 'D' && check_directions(map, i, j, 0) != 0)
		return (-16);
	return (0);
}

int	parse_map(t_data *data, int lines)
{
	int		i;
	int		j;
	char	**map;
	int		stat;

	1 && (map = data->map.map, i = 0);
	while (i < lines)
	{
		j = 0;
		if ((i == 0 || i == lines - 1) && (first_last_line(map[i]) == 0))
			return (-13);
		else if (i > 0 && i < lines - 1)
		{
			while (map[i][j])
			{
				stat = char_checker(map, i, j);
				if (stat < 0)
					return (stat);
				j++;
			}
		}
		i++;
	}
	return (spacetotwo(map), last_check(map, data));
}
