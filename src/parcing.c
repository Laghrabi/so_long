/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:01:56 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/06 13:25:55 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_file_extension(char *file_name)
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

int	file_exist(char *file_name)
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

int	is_rectangle(char **map)
{
	int	i;
	size_t	len;
	
	if (map == NULL || *map == NULL)
		return (FALSE);
	i = 0;
	len = ft_strlen(map[i++]);
	while (map[i] != NULL)
	{
		if(len != ft_strlen(map[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_first_last_rows(char **map)
{
	int i;

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

int check_midlle_rows(char **map)
{
	int i;
	int len;
	
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
	int j;
	
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

int	does_contain(char **map)
{
	int	(i), (j), (E), (P), (C);
	
	if (map == NULL || *map == NULL)
		return (FALSE);
	i = 1;
	E = P = C = 0;
	while (map[i + 1] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				E++;
			else if (map[i][j] == 'P')
				P++;
			else if (map[i][j] == 'C')
				C++;
			j++;
		}
		i++;
	}
	if (E == 1 && P == 1 && C >= 1)
		return (TRUE);
	return (FALSE);
}

void flood_fill(char **map, int x, int y, int rows, int cols, int *c)
{
	if (map == NULL || *map == NULL)
		return ;
	if (x < 0 || y < 0 || x >= rows || y >= cols)
		return ;
	if (map[x][y] == '1' || map[x][y] == '#')
		return ;
	if (map[x][y] == 'C')
		(*c)++;
	map[x][y] = '#';
	flood_fill(map, x + 1, y, rows, cols, c);
	flood_fill(map, x - 1, y, rows, cols, c);
	flood_fill(map, x, y + 1, rows, cols, c);
	flood_fill(map, x, y - 1, rows, cols, c);
}

int	create_dup(int fd)
{
	char **dup;
	
	dup = NULL;
	if (fd < 0)
		return (FALSE);
	dup = read_file(fd);
	if (dup == NULL || *dup == NULL)
		return (FALSE);
	if (find_start_position(dup) == FALSE)
		return (FALSE);
	return (FALSE);
}

int	if_changed(char **map)
{
	int i;
	int j;
	
	if (map == NULL || *map == NULL)
		return (FALSE);
	i = 0;
	int a = 0;
	while (map[a])
	{
		printf("%s\n", map[a]);
		a++;
	}
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

int	is_valid_path(char **map, int x, int y)
{
	int (i), (j), (C), (c);
	
	if (map == NULL || *map == NULL)
		return (FALSE);
	i = 0;
	C = 0;
	c = 0;
	while (map[i] != NULL)
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
	flood_fill(map, x, y, ++i, ++j, &c);
	if (C != c || if_changed(map) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	find_start_position(char **map)
{
	int i;
	int j;
	t_map cord;
	
	if (map == NULL || *map == NULL)
		return (FALSE);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				cord.x_P = j;
				cord.y_P = i;
				if (is_valid_path(map, i, j) == FALSE)
					return (FALSE);
				return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}
