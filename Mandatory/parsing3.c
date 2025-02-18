/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:54:05 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/18 14:51:38 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	does_contain_e(char **map, t_map *game_board)
{
	int (i), (j), (E);
	if (map == NULL || *map == NULL)
		return (FALSE);
	i = 1;
	E = 0;
	while (map[i + 1] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
			{
				(*game_board).x_e = j;
				(*game_board).y_e = i;
				E++;
			}
			j++;
		}
		i++;
	}
	if (E == 1)
		return (TRUE);
	return (FALSE);
}

int	does_contain_p(char **map, t_map *game_board)
{
	int (i), (j), (P);
	if (map == NULL || *map == NULL)
		return (FALSE);
	i = 1;
	P = 0;
	while (map[i + 1] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				(*game_board).x_p = j;
				(*game_board).y_p = i;
				P++;
			}
			j++;
		}
		i++;
	}
	if (P == 1)
		return (TRUE);
	return (FALSE);
}

int	does_contain_c(char **map, t_map *game_board)
{
	int (i), (j), (C);
	if (map == NULL || *map == NULL)
		return (FALSE);
	i = 1;
	C = 0;
	while (map[i + 1] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				C++;
			j++;
		}
		i++;
	}
	(*game_board).c = C;
	if (C >= 1)
		return (TRUE);
	return (FALSE);
}

void	flood_fill(char **map, int x, int y, t_map *game_board)
{
	if (map == NULL || *map == NULL)
		return ;
	if (x < 0 || y < 0 || y >= (*game_board).rows || x >= (*game_board).cols)
		return ;
	if (map[y][x] == '1' || map[y][x] == '#')
		return ;
	if (map[y][x] == 'C')
		(*game_board).ff_c += 1;
	map[y][x] = '#';
	flood_fill(map, x + 1, y, game_board);
	flood_fill(map, x - 1, y, game_board);
	flood_fill(map, x, y + 1, game_board);
	flood_fill(map, x, y - 1, game_board);
}

int	if_changed(char **map)
{
	int	i;
	int	j;

	if (map == NULL || *map == NULL)
		return (FALSE);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '#' && map[i][j] != '0')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
