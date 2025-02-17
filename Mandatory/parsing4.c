/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:34:04 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/15 17:34:20 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_path(char *file_name, t_map *game_board)
{
	int		c;
	int		fd;
	char	**map_copy;

	close((*game_board).fd);
	fd = open(file_name, O_RDONLY);
	(*game_board).fd = fd;
	map_copy = read_file((*game_board).fd);
	if (map_copy == NULL || *map_copy == NULL)
		return (FALSE);
	c = 0;
	flood_fill(map_copy, (*game_board).x_p, (*game_board).y_p,
		game_board);
	if ((*game_board).c != (*game_board).ff_c || if_changed(map_copy) == FALSE)
	{
		free_splited(map_copy);
		return (FALSE);
	}
	free_splited(map_copy);
	return (TRUE);
}
