/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:36:31 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/18 14:15:48 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_enemy_position(t_data *data, int n_x, int n_y, int i)
{
	data->game.map[data->enemies[i].y][data->enemies[i].x] = '0';
	data->game.map[n_y][n_x] = 'X';
	data->enemies[i].y = n_y;
	data->enemies[i].x = n_x;
}

int	validate_move(t_data *data, int n_x, int n_y)
{
	if (data->game.map[n_y][n_x] == 'P')
		kill_player(data);
	if (data->game.map[n_y][n_x] == 'E' || data->game.map[n_y][n_x] == 'C'
		|| data->game.map[n_y][n_x] == '1' || data->game.map[n_y][n_x] == 'X')
		return (0);
	return (1);
}

void	get_move_(t_data *data, int direc)
{
	int (i) = 0;
	while (i < data->enemy_count)
	{
		if (direc == 0 && validate_move(data, data->enemies[i].x,
				data->enemies[i].y + 1))
			update_enemy_position(data, data->enemies[i].x, data->enemies[i].y
				+ 1, i);
		else if (direc == 1 && validate_move(data, data->enemies[i].x + 1,
				data->enemies[i].y))
			update_enemy_position(data, data->enemies[i].x + 1,
				data->enemies[i].y, i);
		else if (direc == 2 && validate_move(data, data->enemies[i].x,
				data->enemies[i].y - 1))
			update_enemy_position(data, data->enemies[i].x, data->enemies[i].y
				- 1, i);
		else if (direc == 3 && validate_move(data, data->enemies[i].x - 1,
				data->enemies[i].y))
			update_enemy_position(data, data->enemies[i].x - 1,
				data->enemies[i].y, i);
		i++;
	}
}

void	count_enemies(t_map *game, int *count)
{
	int (i), (j);
	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->map[i][j] == 'X')
				*count += 1;
			j++;
		}
		i++;
	}
}

void	get_enemies(t_data *data)
{
	int (i), (j), (count);
	i = 0;
	count = 0;
	count_enemies(&data->game, &count);
	data->enemy_count = count;
	data->enemies = malloc(count * sizeof(t_enemy));
	count = 0;
	i = 0;
	while (i < data->game.rows)
	{
		j = 0;
		while (j < data->game.cols)
		{
			if (data->game.map[i][j] == 'X')
			{
				data->enemies[count].x = j;
				data->enemies[count].y = i;
				data->enemies[count].direction = 1;
				count++;
			}
			j++;
		}
		i++;
	}
}
