/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:40:45 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/15 14:44:33 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_data *data, int row, int col)
{
	void	*img;

	img = NULL;
	if (data->game.map[row][col] == '1')
		img = data->img.wall1;
	else if (data->game.map[row][col] == 'P')
		img = data->img.player1;
	else if (data->game.map[row][col] == 'C')
		img = data->img.colle;
	else if (data->game.map[row][col] == '0')
		img = data->img.floor;
	else if (data->game.map[row][col] == 'E'
			&& data->game.C != data->game.aet_C)
		img = data->img.door1;
	else if (data->game.map[row][col] == 'E'
			&& data->game.C == data->game.aet_C)
		img = data->img.door2;
	mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, img, col * 64,
			row * 64);
}

void	render_map(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->game.rows)
	{
		col = 0;
		while (col < data->game.cols)
		{
			render_tile(data, row, col);
			col++;
		}
		row++;
	}
}

int	handle_key(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 65307)
	{
		cleanup(data);
		exit(1);
	}
	if (keycode == 'w')
		move_player(data, 0, -1);
	else if (keycode == 'a')
		move_player(data, -1, 0);
	else if (keycode == 's')
		move_player(data, 0, 1);
	else if (keycode == 'd')
		move_player(data, 1, 0);
	return (0);
}

void	update_player_position(t_data *data, int n_x, int n_y)
{
	if (data->game.map[n_y][n_x] == 'C')
		data->game.aet_C += 1;
	if (data->game.map[n_y][n_x] == 'E' && data->game.C != data->game.aet_C)
		return ;
	if (data->game.map[n_y][n_x] == 'E' && data->game.C == data->game.aet_C)
	{
		data->move_count++;
		ft_printf("Moves: %d\n", data->move_count);
		render_map(data);
		vectory(data);
	}
	data->game.map[data->game.y_P][data->game.x_P] = '0';
	data->game.map[n_y][n_x] = 'P';
	data->game.y_P = n_y;
	data->game.x_P = n_x;
	data->move_count++;
	ft_printf("Moves: %d\n", data->move_count);
	render_map(data);
}

void	move_player(t_data *data, int n_col, int n_row)
{
	int n_x;
	int n_y;

	n_x = data->game.x_P + n_col;
	n_y = data->game.y_P + n_row;
	if (n_y >= 0 && n_y < data->game.rows && n_x >= 0 && n_x < data->game.cols)
	{
		if (data->game.map[n_y][n_x] != '1')
			update_player_position(data, n_x, n_y);
	}
}