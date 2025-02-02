/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:33:31 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/02 18:37:28 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	/*void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		printf("Error\n");
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "SO_LONG");
	mlx_pixel_put(mlx_ptr, win_ptr, 400, 500, 0x00FF0000);
	mlx_loop(mlx_ptr);	 
	return (0);*/
	if(ac < 2)
		return(FALSE);
	if (check_file_extension(av[1]) == FALSE)
	{
		ft_printf("Wrong extension");
		exit(-1);
	}
	return (0);
}
