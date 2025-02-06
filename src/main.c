/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:33:31 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/04 20:05:32 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_splited(char **splited)
{
	unsigned int	i;

	i = 0;
	if (!splited)
		return ;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

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
	char **str = check_input(av[1]);
	printf("Valid Map\n");
	// if (check_file_extension(av[1]) == FALSE)
	// {
	// 	ft_printf("Wrong extension");
	// 	exit(-1);
	// }
	// int fd = file_exist(av[1]);
	// printf ("%d\n", fd);
	// char **str = read_file(fd);
	// if (str == NULL)
	// {
	// 	ft_printf("Invalid map\n");
	// 	exit(FAILURE_EXIT);
	// }
	// int i = 0;
	// while (str[i])
	// {
	// 	printf("%s\n", str[i]);
	// 	i++;
	// }
	// if(is_rectangle(str) == FALSE)
	// {
	// 	ft_printf("Invalid map\n");
	// 	exit(FAILURE_EXIT);
	// }
	// if (check_first_last_rows(str) == FALSE || check_midlle_rows(str) == FALSE)
	// {
	// 	ft_printf("Map Not Closed\n");
	// 	exit(FAILURE_EXIT);
	// }
	// if (is_valid_line(str) == FALSE)
	// {
	// 	ft_printf("Invalid key\n");
	// 	exit(FAILURE_EXIT);
	// }
	// if (does_contain(str) == FALSE)
	// {
	// 	ft_printf("Invalid keys\n");
	// 	exit(FAILURE_EXIT);
	// }
	 free_splited(str);
	return (0);
}
