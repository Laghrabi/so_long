/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:02:41 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/11 18:05:53 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_extension(char *file_name)
{
	if (file_name == NULL)
		return (FALSE);
	if (ft_strlen(file_name) < 5)
		return (FALSE);
	while (ft_strlen(file_name) > 4)
		file_name++;
	if (ft_strncmp(file_name, ".ber", 5) != 0)
		return (FALSE);
	return (TRUE);
}

int	file_exist(char *file_name, t_map *game_board)
{
	int	fd;

	if (file_name == NULL)
		return (FALSE);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: %s: No such file or directory\n", file_name);
		exit(FAILURE_EXIT);
	}
	(*game_board).fd = fd;
	return (fd);
}

char	**read_file(int fd)
{
	char	*line;
	char	*buffer;
	char	**splited;

	buffer = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] == '\n')
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		buffer = join(buffer, line);
		free(line);
		line = get_next_line(fd);
	}
	splited = ft_split(buffer, '\n');
	free(buffer);
	if (splited == NULL || *splited == NULL)
		return (NULL);
	return (splited);
}

int	is_rectangle(char **map, t_map *game_board)
{
	int		i;
	size_t	len;

	if (map == NULL || *map == NULL)
		return (FALSE);
	i = 0;
	len = ft_strlen(map[i++]);
	(*game_board).cols = len;
	while (map[i] != NULL)
	{
		if (len != ft_strlen(map[i]))
			return (FALSE);
		i++;
	}
	(*game_board).rows = i;
	return (TRUE);
}

int	check_nbr_of_rows_cols(t_map *game_board)
{
	if ((*game_board).rows > 32)
	{
		ft_printf("Error: You exceeded the exact number of rows\n");
		return (FALSE);
	}
	if ((*game_board).cols > 61)
	{
		ft_printf("Error: You exceeded the exact number of cols\n");
		return (FALSE);
	}
	return (TRUE);
}

int	check_first_last_rows(char **map)
{
	int	i;

	if (map == NULL || *map == NULL)
		return (FALSE);
	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1')
			return (FALSE);
		i++;
	}
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i + 1] == NULL)
		{
			if (ft_strncmp(map[0], map[i], (ft_strlen(map[0]) + 1)) != 0)
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
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
			if (is_valid_key(map[i][j], "EPC01") == FALSE)
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

int	does_contain_e(char **map, t_map *game_board)
{
	int(i), (j), (E);
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
				(*game_board).x_E = j;
				(*game_board).y_E = i;
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
	int(i), (j), (P);
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
				(*game_board).x_P = j;
				(*game_board).y_P = i;
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
	int(i), (j), (C);
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
	(*game_board).C = C;
	if (C >= 1)
		return (TRUE);
	return (FALSE);
}

void	flood_fill(char **map, int x, int y, int rows, int cols, int *c)
{
	if (map == NULL || *map == NULL)
		return ;
	if (x < 0 || y < 0 || y >= rows || x >= cols)
		return ;
	if (map[y][x] == '1' || map[y][x] == '#')
		return ;
	if (map[y][x] == 'C')
		(*c)++;
	map[y][x] = '#';
	flood_fill(map, x + 1, y, rows, cols, c);
	flood_fill(map, x - 1, y, rows, cols, c);
	flood_fill(map, x, y + 1, rows, cols, c);
	flood_fill(map, x, y - 1, rows, cols, c);
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
			if (map[i][j] != '1' && map[i][j] != '#')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

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
	flood_fill(map_copy, (*game_board).x_P, (*game_board).y_P,
			(*game_board).rows, (*game_board).cols, &c);
	// int a = 0;
	// while (map_copy[a])
	// {
	// 	printf("%s\n", map_copy[a]);
	// 	a++;
	// }
	// printf("\n");
	if ((*game_board).C != c || if_changed(map_copy) == FALSE)
	{
		free_splited(map_copy);
		return (FALSE);
	}
	free_splited(map_copy);
	return (TRUE);
}
