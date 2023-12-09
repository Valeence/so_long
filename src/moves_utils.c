/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:11:06 by vandre            #+#    #+#             */
/*   Updated: 2023/12/09 17:32:45 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_print_right(t_game *game)
{
	game->mlx_map[game->pos_y][game->pos_x] = '0';
	game->mlx_map[game->pos_y][game->pos_x + 1] = 'P';
	print_img(game, '0', game->pos_x, game->pos_y);
	print_img(game, 'P', game->pos_x + 1, game->pos_y);
	game->pos_x++;
	game->move++;
	ft_printf("move = %d\n", game->move);
}

void	game_print_left(t_game *game)
{
	game->mlx_map[game->pos_y][game->pos_x] = '0';
	game->mlx_map[game->pos_y][game->pos_x - 1] = 'P';
	print_img(game, '0', game->pos_x, game->pos_y);
	print_img(game, 'P', game->pos_x - 1, game->pos_y);
	game->pos_x--;
	game->move++;
	ft_printf("move = %d\n", game->move);
}

void	game_print_up(t_game *game)
{
	game->mlx_map[game->pos_y][game->pos_x] = '0';
	game->mlx_map[game->pos_y - 1][game->pos_x] = 'P';
	print_img(game, '0', game->pos_x, game->pos_y);
	print_img(game, 'P', game->pos_x, game->pos_y - 1);
	game->pos_y--;
	game->move++;
	ft_printf("move = %d\n", game->move);
}

void	game_print_down(t_game *game)
{
	game->mlx_map[game->pos_y][game->pos_x] = '0';
	game->mlx_map[game->pos_y + 1][game->pos_x] = 'P';
	print_img(game, '0', game->pos_x, game->pos_y);
	print_img(game, 'P', game->pos_x, game->pos_y + 1);
	game->pos_y++;
	game->move++;
	ft_printf("move = %d\n", game->move);
}
