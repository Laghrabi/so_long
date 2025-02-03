/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:55:43 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/03 18:45:50 by claghrab         ###   ########.fr       */
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
# define FAILURE_EXIT -1

/* FUNCTIONS */
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

