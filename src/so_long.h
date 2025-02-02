/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:55:43 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/02 18:44:34 by claghrab         ###   ########.fr       */
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

/*FUNCTIONS*/
int	check_file_extension(char *file_name);

#endif 

