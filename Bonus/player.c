/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:23:15 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/15 18:24:21 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	kill_player(t_data *data)
{
	ft_printf("LOSER!\n");
	cleanup(data);
	exit(0);
}

void	update_player_position(t_data *data, int n_x, int n_y)
{
	if (data->game.map[n_y][n_x] == 'C')
		data->game.ate_c += 1;
	if (data->game.map[n_y][n_x] == 'X')
		kill_player(data);
	if (data->game.map[n_y][n_x] == 'E' && data->game.c != data->game.ate_c)
		return ;
	if (data->game.map[n_y][n_x] == 'E' && data->game.c == data->game.ate_c)
	{
		render_map(data);
		vectory(data);
	}
	data->game.map[data->game.y_p][data->game.x_p] = '0';
	data->game.map[n_y][n_x] = 'P';
	data->game.y_p = n_y;
	data->game.x_p = n_x;
	data->move_count++;
	mlx_clear_window(data->win.mlx_ptr, data->win.win_ptr);
	render_map(data);
}

void	move_player(t_data *data, int n_col, int n_row)
{
	int	n_x;
	int	n_y;

	n_x = data->game.x_p + n_col;
	n_y = data->game.y_p + n_row;
	if (n_y >= 0 && n_y < data->game.rows && n_x >= 0 && n_x < data->game.cols)
	{
		if (data->game.map[n_y][n_x] != '1')
			update_player_position(data, n_x, n_y);
	}
}
