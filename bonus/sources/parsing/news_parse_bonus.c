/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   news_parse_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:15:06 by zmaghdao          #+#    #+#             */
/*   Updated: 2024/11/01 10:59:23 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	png_or_xpm(char *coor)
{
	char	*png;
	char	*xpm;
	char	*tmp;

	1 && (png = NULL, xpm = NULL);
	png = ft_strnstr(coor, ".png", ft_strlen(coor));
	xpm = ft_strnstr(coor, ".xpm", ft_strlen(coor));
	if (!xpm && !png)  
		return (-1);
	else if (xpm && !png)
		return (1);
	else if (!xpm && png)
		return (2);
	else
	{
		tmp = ft_strnstr(xpm, ".png", ft_strlen(xpm));
		if (!tmp)
			return (1);
		else
			return (2);
	}
	return (0);
}

int	fill_texture(t_map *map, char **c_s, int start, int end)
{
	char	*new_coor;
	char	*tmp;

	new_coor = NULL;
	tmp = ft_substr(c_s[0], start, end - start + 4);
	if (!tmp)
		return (-2);
	new_coor = ft_strjoin(new_coor, tmp);
	free(tmp);
	if (!new_coor)
		return (-2);
	if (ft_strncmp(c_s[1], "NO", 3) == 0)
		map->north = new_coor;
	else if (ft_strncmp(c_s[1], "WE", 3) == 0)
		map->west = new_coor;
	else if (ft_strncmp(c_s[1], "EA", 3) == 0)
		map->east = new_coor;
	else if (ft_strncmp(c_s[1], "SO", 3) == 0)
		map->south = new_coor;
	return (0);
}

int	xp_checker(char **c_s, int x, int *i, t_map *map)
{
	char	*str;
	int		j;
	int		idx;
	int		start;

	1 && (start = *i, str = ".png");
	if (x == 1)
		str = ".xpm";
	while (c_s[0][*i])
	{
		if (c_s[0][*i] == str[0])
		{
			1 && (j = 0, idx = *i);
			while (str[j] && c_s[0][idx])
			{
				if (str[j] != c_s[0][idx])
					break ;
				1 && (j++, idx++);
			}
			if (j == 4 && (!c_s[0][idx]))
				return (fill_texture(map, c_s, start, *i));
		}
		*i += 1;
	}
	return (-7);
}

int	check_news_ptrs(char *coor, char *str, t_map *map)
{
	int		i;
	int		x;
	int 	stat;

	i = 0;
	if (ft_isspace(coor[i]))
		return (-6);
	if ((coor[i] != str[0] || coor[i + 1] != str[1]) ||\
		(coor[i] == str[0] && coor[i + 1] == str[1] &&\
		(!ft_isspace(coor[i + 2]) || ((i > 0 && !ft_isspace(coor[i - 1]))))))
		return (-6);
	i += 2;
	while (ft_isspace(coor[i]))
		i++;
	if (coor[i] != '.' && coor[i] != '/')
		return (-6);
	x = png_or_xpm(coor);
	if (x == -1)
		return (-7);
	stat = xp_checker((char *[]){coor, str}, x, &i, map);
	if (stat < 0)
		return (stat);
	return (0);
}
