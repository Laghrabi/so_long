/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:55:43 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/11 17:36:00 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "../Libft/gnl/get_next_line.h"
# include "../Libft/printf/ft_printf.h"
# include "../Libft/libft.h"

/*MACROS*/
# define TRUE 1
# define FALSE 0
# define FAILURE_EXIT 1
# define BLACK 0x000000

/*STRUCTURE*/
typedef struct s_map {
    char **map;
    int fd;
    int rows;
    int cols;
    int C;
    int aet_C;
    int x_P;
    int y_P;
    int x_E;
    int y_E;
} t_map;

typedef struct s_win {
    void	*mlx_ptr;
    void	*win_ptr;
} t_win;

typedef struct s_img{
    void    *wall1;
    void    *floor;
    void    *player1;
    void    *player2;
    void    *player3;
    void    *colle;
    void    *door1;
    void    *door2;
    void    *en1;
    void    *en2;
    int     h;
    int     w;
} t_img;

typedef struct s_data {
   t_map game;
   t_win win;
   t_img img; 
   int move_count;
} t_data;

/* FUNCTIONS */
int prepare_game_data(int ac, char **av, t_map *game_board, t_data *data);
void update_player_position(t_data *data, int n_x, int n_y);
int	check_nbr_of_rows_cols(t_map *game_board);
void	setup_hooks(t_data *data);
int	close_game(t_data *data);
void render_tile(t_data *data, int row, int col);
void vectory(t_data *data);
void	move_player(t_data *data, int n_col, int n_row);
int	handle_key(int keycode, void *param);
void cleanup(t_data *data);
int  render_map(t_data *data);
void	load_images(t_data *data);
void window(t_data *data);
void flood_fill(char **map, int x, int y, int rows, int cols, int *c);
int	is_valid_path(char *file_name, t_map *game_board);
int	if_changed(char **map);
int check_midlle_rows(char **map);
int does_contain_c(char **map, t_map *game_board);
int does_contain_p(char **map, t_map *game_board);
void	free_splited(char **splited);
void    exit_error(int flag, char **splited);
char **check_input(char *file_name, t_map *game_board);
int does_contain_e(char **map, t_map *game_board);
int	does_contain(char **map, t_map *game_board);
int	is_valid_line(char **map);
int	is_valid_key(char c, char *set);
int check_midlle_rows(char **map);
int	check_first_last_rows(char **map);
int	is_rectangle(char **map, t_map *game_board);
char	**read_file(int fd);
int	file_exist(char *file_name, t_map *game_board);
int check_file_extension(char *file_name);
void	put_moves(t_data *data);

#endif 

