/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:22:46 by zmaghdao          #+#    #+#             */
/*   Updated: 2024/11/04 21:41:51 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	angle_init(char c, t_data *data)
{
	if (c == 'S')
		data->player->angle = 90 * (M_PI / 180);
	else if (c == 'N')
		data->player->angle = 270 * (M_PI / 180);
	else if (c == 'W')
		data->player->angle = 180 * (M_PI / 180);
	else if (c == 'E')
		data->player->angle = 0 * (M_PI / 180);
}

int is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int sec_char(char *tab, int i)
{
	if ((tab[i] == 'N' || tab[i] == 'S') && tab[i + 1] != 'O')
		return (-1);
	if ((tab[i] == 'F' || tab[i] == 'C') && !ft_isspace(tab[i + 1]))
		return (-1);
	if (tab[i] == 'E' && tab[i + 1] != 'A')
		return (-1);
	if (tab[i] == 'W' && tab[i + 1] != 'E')
		return (-1);
	return (0);
}
