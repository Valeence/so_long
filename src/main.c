/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:56:36 by vandre            #+#    #+#             */
/*   Updated: 2023/12/08 03:09:33 by vandre           ###   ########.fr       */
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
	game.mlx = mlx_init();
	if (!game.mlx)
		return (ft_printf("Error\nMlx init failed\n"),
			mlx_destroy_display(game.mlx), 1);
	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64,
			"so_long");
	if (!game.win)
		return (ft_printf("Error\nMlx window init failed\n"),
			mlx_destroy_window(game.mlx, game.win),
			mlx_destroy_display(game.mlx), 1);
	init_mlx(&game);
	print_mlx(&game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}	
