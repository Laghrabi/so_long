/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:02:41 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/15 17:55:10 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
