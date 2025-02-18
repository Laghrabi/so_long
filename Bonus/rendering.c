/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:21:30 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/18 14:15:06 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*select_tile_image(t_data *data, int row, int col)
{
	static int	f;

	++f;
	if (data->game.map[row][col] == '1')
		return (data->img.wall1);
	else if (data->game.map[row][col] == 'P')
	{
		if (f % 600 < 300)
			return (data->img.player2);
		return (data->img.player1);
	}
	else if (data->game.map[row][col] == 'C')
		return (data->img.colle);
	else if (data->game.map[row][col] == '0')
		return (data->img.floor);
	else if (data->game.map[row][col] == 'X')
		return (data->img.en1);
	else if (data->game.map[row][col] == 'E')
	{
		if (data->game.c != data->game.ate_c)
			return (data->img.door1);
		return (data->img.door2);
	}
	return (NULL);
}

void	render_tile(t_data *data, int row, int col)
{
	void	*img;

	img = select_tile_image(data, row, col);
	mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, img, col * 64,
		row * 64);
	put_moves(data);
}

int	get_move(void)
{
	return (rand() % 4);
}

int	render_map(t_data *data)
{
	int			row;
	int			col;
	static int	count;

	srand((time(NULL) ^ 12345) * 567890);
	if (count % 30 == 0)
		get_move_(data, get_move());
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
	count++;
	return (0);
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
