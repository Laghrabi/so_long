/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:01:56 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/02 18:04:19 by claghrab         ###   ########.fr       */
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
