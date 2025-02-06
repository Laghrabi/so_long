/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:55:43 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/06 12:41:00 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../Libft/gnl/get_next_line.h"
# include "../Libft/printf/ft_printf.h"
# include "../Libft/libft.h"

/*MACROS*/
# define TRUE 1
# define FALSE 0
# define FAILURE_EXIT 1

/*STRUCTURE*/
// typedef struct s_map {
//     char
// }

/* FUNCTIONS */
int	if_changed(char **map);
void flood_fill(char **map_copy, int x, int y, int rows, int cols, int *c);
int	find_start_position(char **map);
int create_dup(int fd);
char **check_input(char *file_name);
void    exit_error(int flag, char **splited);
int	does_contain(char **map);
int	is_valid_line(char **map);
int	is_valid_key(char c, char *set);
int check_midlle_rows(char **map);
int	check_first_last_rows(char **map);
int	is_rectangle(char **map);
void	free_splited(char **splited);
int     check_file_extension(char *file_name);
int     file_exist(char *file_name);
char	**read_file(int fd);

#endif 

