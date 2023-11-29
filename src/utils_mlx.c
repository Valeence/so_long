/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:11:53 by vandre            #+#    #+#             */
/*   Updated: 2023/11/29 19:43:00 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_mlx(t_game *game)
{
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "./Asset/grass1.xpm",
			&game->width, &game->height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "./Asset/treegrass.xpm",
			&game->width, &game->height);
	game->img.coin = mlx_xpm_file_to_image(game->mlx, "./Asset/coin.xpm",
			&game->width, &game->height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "./Asset/exit.xpm",
			&game->width, &game->height);
	game->img.player = mlx_xpm_file_to_image(game->mlx, "./Asset/player.xpm",
			&game->width, &game->height);
	if (!game->img.floor || !game->img.wall || !game->img.coin)
	{
		ft_printf("Error\nMlx image init failed\n");
		exit(EXIT_FAILURE);
	}
}

void	print_map(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, x * 16,
			y * 16);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img.floor, x * 16,
			y * 16);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.coin, x * 16,
			y * 16);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, x * 16,
			y * 16);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img.player, x * 16,
			y * 16);
}

void	print_mlx(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->mlx_map[y])
	{
		printf("%s\n", game->mlx_map[y]);
		while (game->mlx_map[y][x])
		{
			if (game->mlx_map[y][x] == '1')
				print_map(game, '1', x, y);
			else if (game->mlx_map[y][x] == '0')
				print_map(game, '0', x, y);
			else if (game->mlx_map[y][x] == 'C')
				print_map(game, 'C', x, y);
			else if (game->mlx_map[y][x] == 'E')
				print_map(game, 'E', x, y);
			else if (game->mlx_map[y][x] == 'P')
				print_map(game, 'P', x, y);
		x++;
		}
		x = 0;
		y++;
	}
}
