/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:50:08 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/09 15:48:17 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void cleanup(t_data *data)
{
	if (data->img.wall1)
		mlx_destroy_image(data->win.mlx_ptr, data->img.wall1);
	if (data->img.player1)
		mlx_destroy_image(data->win.mlx_ptr, data->img.player1);
	if (data->img.colle)
		mlx_destroy_image(data->win.mlx_ptr, data->img.colle);
	if (data->img.door1)
		mlx_destroy_image(data->win.mlx_ptr, data->img.door1);
	if (data->img.door2)
		mlx_destroy_image(data->win.mlx_ptr, data->img.door2);
	if (data->img.floor)
		mlx_destroy_image(data->win.mlx_ptr, data->img.floor);
	if (data->win.win_ptr)
		mlx_destroy_window(data->win.mlx_ptr, data->win.win_ptr);
	mlx_destroy_display(data->win.mlx_ptr);
	free(data->win.mlx_ptr);
	free_splited(data->game.map);
	// exit(1);
}

int close_game(t_data *data)
{
	cleanup(data);
	exit(0);
	return (0);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win.win_ptr, 17, 0, close_game, data);
}

void window(t_data *data)
{
	data->move_count = 0;
	data->win.mlx_ptr = mlx_init();
	if (data->win.mlx_ptr == NULL)
	{
		ft_printf("Error\n");
		exit(1);
	}
	data->win.win_ptr = mlx_new_window(data->win.mlx_ptr, data->game.cols * 64, data->game.rows * 64, "SO_LONG");
	if (!data->win.win_ptr)
	{
		ft_printf("Error: Failed to create a window.\n");
		exit(1);
	}
	load_images(data);
	render_map(data);
	mlx_key_hook(data->win.win_ptr, handle_key, data);
	setup_hooks(data);
	mlx_loop(data->win.mlx_ptr);
	cleanup(data);
}

void	load_images(t_data *data)
{
	data->img.wall1 = mlx_xpm_file_to_image(data->win.mlx_ptr, "imgs/wall1.xpm", &data->img.w, &data->img.h);
	data->img.floor = mlx_xpm_file_to_image(data->win.mlx_ptr, "imgs/void.xpm", &data->img.w, &data->img.h);
	data->img.player1 = mlx_xpm_file_to_image(data->win.mlx_ptr, "imgs/character1.xpm", &data->img.w, &data->img.h);
	//data->img.player2 = mlx_xpm_file_to_image(data->win.mlx_ptr, "imgs/character2.xpm", &data->img.w, &data->img.h);
	//data->img.player3 = mlx_xpm_file_to_image(data->win.mlx_ptr, "imgs/character3.xpm", &data->img.w, &data->img.h);
	data->img.colle = mlx_xpm_file_to_image(data->win.mlx_ptr, "imgs/collectible.xpm", &data->img.w, &data->img.h);
	data->img.door1 = mlx_xpm_file_to_image(data->win.mlx_ptr, "imgs/door1.xpm", &data->img.w, &data->img.h);
	data->img.door2 = mlx_xpm_file_to_image(data->win.mlx_ptr, "imgs/door2.xpm", &data->img.w, &data->img.h);
	if (!data->img.wall1 || !data->img.player1 || !data->img.colle || !data->img.door1 || !data->img.door2)
    {
        ft_printf("Error: Failed to load images\n");
        exit(1);
    }
}

// void render_map(t_data *data)
// {
// 	int (row), (col);
// 	void *img;

// 	row = 0;
// 	img = NULL;
// 	while (row < data->game.rows)
// 	{
// 		col = 0;
// 		while (col < data->game.cols)
// 		{
// 			if (data->game.map[row][col] == '1')
// 				img = data->img.wall1;
// 			if (data->game.map[row][col] == 'P')
// 				img = data->img.player1;
// 			else if(data->game.map[row][col] == 'C')
// 				img = data->img.colle;
// 			else if (data->game.map[row][col] == '0')
// 					img = data->img.floor;
// 			else if(data->game.map[row][col] == 'E' && data->game.C != data->game.aet_C)
// 				img = data->img.door1;
// 			else if(data->game.map[row][col] == 'E' && data->game.C == data->game.aet_C)
// 				img = data->img.door2;
// 			mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, img, col * 64, row * 64);
// 			col++;
// 		}
// 		row++;
// 	}
// }

void render_tile(t_data *data, int row, int col)
{
	void *img = NULL;

	if (data->game.map[row][col] == '1')
		img = data->img.wall1;
	else if (data->game.map[row][col] == 'P')
		img = data->img.player1;
	else if (data->game.map[row][col] == 'C')
		img = data->img.colle;
	else if (data->game.map[row][col] == '0')
		img = data->img.floor;
	else if (data->game.map[row][col] == 'E' && data->game.C != data->game.aet_C)
		img = data->img.door1;
	else if (data->game.map[row][col] == 'E' && data->game.C == data->game.aet_C)
		img = data->img.door2;

	mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, img, col * 64, row * 64);
}

void render_map(t_data *data)
{
	int row;
	int col;

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
	t_data *data;
	
	data = (t_data *)param;
	if (keycode == 65307)
	{
		cleanup(data);	
		exit(1);
	}
	if(keycode == 'w')
		move_player(data, 0, -1);	
	else if(keycode == 'a')
		move_player(data, -1, 0);
	else if(keycode == 's')
		move_player(data, 0, 1);
	else if(keycode == 'd')
		move_player(data, 1, 0);
	return (0);
}


void vectory(t_data *data)
{
	ft_printf("🎉 You won!\n");
	cleanup(data);
	exit(0);
}
// void	move_player(t_data *data, int n_col, int n_row)
// {
// 	int n_x;
// 	int n_y;
	
// 	n_x = data->game.x_P + n_col;
// 	n_y = data->game.y_P + n_row;
// 	if (n_y >= 0 && n_y < data->game.rows && n_x >= 0 && n_x < data->game.cols)
// 	{
// 		if (data->game.map[n_y][n_x] != '1')
// 		{
// 			if (data->game.map[n_y][n_x] == 'C')
// 				data->game.aet_C += 1;
// 			if (data->game.map[n_y][n_x] == 'E' && data->game.C != data->game.aet_C)
// 				return ;
// 			if (data->game.map[n_y][n_x] == 'E' && data->game.C == data->game.aet_C)
// 			{
// 				render_map(data);
// 				vectory(data);
// 			}
// 			data->game.map[data->game.y_P][data->game.x_P] = '0';
// 			data->game.map[n_y][n_x] = 'P';
// 			data->game.y_P = n_y;
// 			data->game.x_P = n_x;
// 			data->move_count++;
// 			ft_printf("Moves: %d\n", data->move_count);
// 			render_map(data);
// 		}
// 	}
// }

void update_player_position(t_data *data, int n_x, int n_y)
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

void move_player(t_data *data, int n_col, int n_row)
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
