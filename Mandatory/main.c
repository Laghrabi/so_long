/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:33:31 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/15 17:25:33 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_splited(char **splited)
{
	unsigned int	i;

	i = 0;
	if (!splited)
		return ;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

void	vectory(t_data *data)
{
	ft_printf("🎉 You won!\n");
	cleanup(data);
	exit(0);
}

void	cleanup(t_data *data)
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
}

int	prepare_game_data(int ac, char **av, t_map *game_board, t_data *data)
{
	if (ac < 2)
		return (FALSE);
	game_board->map = check_input(av[1], game_board);
	data->game.map = game_board->map;
	data->game.fd = game_board->fd;
	data->game.c = game_board->c;
	data->game.x_e = game_board->x_e;
	data->game.y_e = game_board->y_e;
	data->game.x_p = game_board->x_p;
	data->game.y_p = game_board->y_p;
	data->game.rows = game_board->rows;
	data->game.cols = game_board->cols;
	data->game.ate_c = 0;
	data->game.ff_c = 0;
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_map	game_board;
	t_data	data;

	if (!prepare_game_data(ac, av, &game_board, &data))
		return (FALSE);
	window(&data);
	return (0);
}
