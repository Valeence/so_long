/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:31:57 by vandre            #+#    #+#             */
/*   Updated: 2023/12/09 17:33:26 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_print_right_exit(t_game *game)
{
	if (game->mlx_map[game->pos_y][game->pos_x + 2] == 'C'
			|| game->mlx_map[game->pos_y][game->pos_x + 2] == '0')
	{
		game->mlx_map[game->pos_y][game->pos_x] = '0';
		game->mlx_map[game->pos_y][game->pos_x + 2] = 'P';
		print_img(game, '0', game->pos_x, game->pos_y);
		print_img(game, 'P', game->pos_x + 2, game->pos_y);
		game->pos_x += 2;
		game->move++;
		ft_printf("move = %d\n", game->move);
	}
}

void	game_print_left_exit(t_game *game)
{
	if (game->mlx_map[game->pos_y][game->pos_x - 2] == 'C'
			|| game->mlx_map[game->pos_y][game->pos_x - 2] == '0')
	{
		game->mlx_map[game->pos_y][game->pos_x] = '0';
		game->mlx_map[game->pos_y][game->pos_x - 2] = 'P';
		print_img(game, '0', game->pos_x, game->pos_y);
		print_img(game, 'P', game->pos_x - 2, game->pos_y);
		game->pos_x -= 2;
		game->move++;
		ft_printf("move = %d\n", game->move);
	}
}

void	game_print_up_exit(t_game *game)
{
	if (game->mlx_map[game->pos_y - 2][game->pos_x] == 'C'
			|| game->mlx_map[game->pos_y - 2][game->pos_x] == '0')
	{
		game->mlx_map[game->pos_y][game->pos_x] = '0';
		game->mlx_map[game->pos_y - 2][game->pos_x] = 'P';
		print_img(game, '0', game->pos_x, game->pos_y);
		print_img(game, 'P', game->pos_x, game->pos_y - 2);
		game->pos_y -= 2;
		game->move++;
		ft_printf("move = %d\n", game->move);
	}
}

void	game_print_down_exit(t_game *game)
{
	if (game->mlx_map[game->pos_y + 2][game->pos_x] == 'C'
			|| game->mlx_map[game->pos_y + 2][game->pos_x] == '0')
	{
		game->mlx_map[game->pos_y][game->pos_x] = '0';
		game->mlx_map[game->pos_y + 2][game->pos_x] = 'P';
		print_img(game, '0', game->pos_x, game->pos_y);
		print_img(game, 'P', game->pos_x, game->pos_y + 2);
		game->pos_y += 2;
		game->move++;
		ft_printf("move = %d\n", game->move);
	}
}
