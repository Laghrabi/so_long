/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:33:31 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/08 14:41:08 by claghrab         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_map game_board;
	t_data data;
	
	if(ac < 2)
		return(FALSE);
	game_board.map = check_input(av[1], &game_board);
	data.game.map = game_board.map;
	data.game.fd = game_board.fd;
	data.game.C = game_board.C;
	data.game.x_E = game_board.x_E;
	data.game.y_E = game_board.y_E;
	data.game.x_P = game_board.x_P;
	data.game.y_P = game_board.y_P;
	//printf("%d, %d\n", data.game.x_P, data.game.y_P);
	data.game.rows = game_board.rows;
	data.game.cols = game_board.cols;
	data.game.aet_C = 0;
	//printf("%s\n", data.game.map[0]);
	printf("Valid Map\n");
	window(&data);
	return (0);
}
