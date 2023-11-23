/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:56:36 by vandre            #+#    #+#             */
/*   Updated: 2023/11/23 19:01:21 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	static t_game	game = {0};

	if (argc != 2)
		return (ft_printf("Usage:./so_long map.ber\n"));
	if (!check_arg(argv[1]))
		return (ft_printf("Error\nInvalid map\n"));
	check_size(&game, argv[1]);
	fill_map(&game, argv[1]);
	check_map(&game);
	ft_printf("Ok\n");
	game.mlx = mlx_init();
	if (!game.mlx)
		return (ft_printf("Error\nMlx init failed\n"));
	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64,
			"So_long");
	if (!game.win)
		return (ft_printf("Error\nMlx window init failed\n"));
	init_mlx(&game);
	game.img.floor = mlx_xpm_file_to_image(game.mlx, "../Asset/floor.xpm",
			);
	mlx_put_image_to_window(game.mlx, game.win, game.img.floor, 0, 0);
	mlx_loop(game.mlx);
	return (0);
}	
