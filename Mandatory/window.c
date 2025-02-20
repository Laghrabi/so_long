/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:50:08 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/20 14:01:37 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_data *data)
{
	cleanup(data);
	exit(0);
	return (0);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win.win_ptr, 17, 0, close_game, data);
}

void	window(t_data *data)
{
	data->move_count = 0;
	data->win.mlx_ptr = mlx_init();
	if (data->win.mlx_ptr == NULL)
	{
		ft_printf("Error\n");
		exit(1);
	}
	data->win.win_ptr = mlx_new_window(data->win.mlx_ptr, data->game.cols * 64,
			data->game.rows * 64, "SO_LONG");
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
}

void	load_images(t_data *data)
{
	data->img.wall1 = mlx_xpm_file_to_image(data->win.mlx_ptr, "imgs/wall1.xpm",
			&data->img.w, &data->img.h);
	data->img.floor = mlx_xpm_file_to_image(data->win.mlx_ptr, "imgs/void.xpm",
			&data->img.w, &data->img.h);
	data->img.player1 = mlx_xpm_file_to_image(data->win.mlx_ptr,
			"imgs/character1.xpm", &data->img.w, &data->img.h);
	data->img.colle = mlx_xpm_file_to_image(data->win.mlx_ptr,
			"imgs/collectible.xpm", &data->img.w, &data->img.h);
	data->img.door1 = mlx_xpm_file_to_image(data->win.mlx_ptr, "imgs/door1.xpm",
			&data->img.w, &data->img.h);
	data->img.door2 = mlx_xpm_file_to_image(data->win.mlx_ptr, "imgs/door2.xpm",
			&data->img.w, &data->img.h);
}
