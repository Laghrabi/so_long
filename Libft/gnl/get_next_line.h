/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:33:43 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/02 18:50:17 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*append_line(char *last);
char	*append_last(char *last);
char	*mini_read(int fd, char *last);
char	*handle_read(char *buffer, char *last, ssize_t read_bytes);
char	*join(char *s1, char *s2);
char	*dupl(char *str);
//int		ft_strlen(char *str);
int		tonl(char *s, char c);

#endif
