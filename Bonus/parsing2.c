/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:49:16 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/17 14:55:26 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_first_last_rows(char **map)
{
	int	i;

	if (map == NULL || *map == NULL)
		return (0);
	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i + 1] == NULL)
		{
			if (ft_strncmp(map[0], map[i], (ft_strlen(map[0]) + 1)) != 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_midlle_rows(char **map)
{
	int	i;
	int	len;

	if (map == NULL || *map == NULL)
		return (FALSE);
	i = 1;
	while (map[i] != NULL)
	{
		len = ft_strlen(map[i]);
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_valid_key(char c, char *set)
{
	int	i;

	if (set == NULL)
		return (FALSE);
	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	is_valid_line(char **map)
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
			if (is_valid_key(map[i][j], "XEPC01") == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	does_contain(char **map, t_map *game_board)
{
	if (map == NULL || *map == NULL)
		return (FALSE);
	if (does_contain_e(map, game_board) == TRUE && does_contain_p(map,
			game_board) == TRUE && does_contain_c(map, game_board) == TRUE)
		return (TRUE);
	return (FALSE);
}
