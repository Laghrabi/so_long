/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:14:17 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/20 14:54:10 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_error(int flag, char **splited)
{
	if (flag == 0)
		ft_printf("Error\nWrong Extension\n");
	else if (flag == 1 || flag == 2)
	{
		free_splited(splited);
		ft_printf("Error\nInvalid Map\n");
	}
	else if (flag == 3)
		free_splited(splited);
	else if (flag == 4)
	{
		free_splited(splited);
		ft_printf("Error\nMap Not Closed\n");
	}
	else if (flag == 5 || flag == 6)
	{
		free_splited(splited);
		ft_printf("Error\nInvalid keys\n");
	}
	else if (flag == 7)
	{
		free_splited(splited);
		ft_printf("Error\nInvalid Path\n");
	}
	exit(FAILURE_EXIT);
}

void	validate_map(char **splited, char *file_name, t_map *game_board)
{
	if (splited == NULL || *splited == NULL)
		exit_error(1, splited);
	if (is_rectangle(splited, game_board) == FALSE)
		exit_error(2, splited);
	if (check_nbr_of_rows_cols(game_board) == FALSE)
		exit_error(3, splited);
	if (check_first_last_rows(splited) == FALSE
		|| check_midlle_rows(splited) == FALSE)
		exit_error(4, splited);
	if (is_valid_line(splited) == FALSE)
		exit_error(5, splited);
	if (does_contain(splited, game_board) == FALSE)
		exit_error(6, splited);
	if (is_valid_path(file_name, game_board) == FALSE)
		exit_error(7, splited);
}

char	**check_input(char *file_name, t_map *game_board)
{
	int		fd;
	char	**splited;

	splited = NULL;
	if (file_name == NULL)
		return (NULL);
	if (check_file_extension(file_name) == FALSE)
		exit_error(0, splited);
	fd = file_exist(file_name, game_board);
	splited = read_file(fd);
	validate_map(splited, file_name, game_board);
	return (splited);
}
