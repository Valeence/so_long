/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 05:33:24 by vandre            #+#    #+#             */
/*   Updated: 2023/12/09 17:35:34 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_right(t_game *game)
{
	if (game->mlx_map[game->pos_y][game->pos_x + 1] == 'C'
		|| game->mlx_map[game->pos_y][game->pos_x + 1] == '0')
	{
		if (game->mlx_map[game->pos_y][game->pos_x + 1] == 'C')
			game->check_coin--;
		game_print_right(game);
	}
	else if (game->mlx_map[game->pos_y][game->pos_x + 1] == 'E'
		&& game->check_coin != 0)
	{
		if (game->mlx_map[game->pos_y][game->pos_x + 2] == 'C')
			game->check_coin--;
		game_print_right_exit(game);
	}
	else if (game->mlx_map[game->pos_y][game->pos_x + 1] == 'E'
		&& game->check_coin == 0)
	{
		game_print_right(game);
		ft_printf("You win in %d moves\n", game->move);
		close_game(game);
	}
}

void	move_left(t_game *game)
{
	if (game->mlx_map[game->pos_y][game->pos_x - 1] == 'C'
		|| game->mlx_map[game->pos_y][game->pos_x - 1] == '0')
	{
		if (game->mlx_map[game->pos_y][game->pos_x - 1] == 'C')
			game->check_coin--;
		game_print_left(game);
	}
	else if (game->mlx_map[game->pos_y][game->pos_x - 1] == 'E'
		&& game->check_coin != 0)
	{
		if (game->mlx_map[game->pos_y][game->pos_x - 2] == 'C')
			game->check_coin--;
		game_print_left_exit(game);
	}
	else if (game->mlx_map[game->pos_y][game->pos_x - 1] == 'E'
		&& game->check_coin == 0)
	{
		game_print_left(game);
		ft_printf("You win in %d moves\n", game->move);
		close_game(game);
	}
}

void	move_up(t_game *game)
{
	if (game->mlx_map[game->pos_y - 1][game->pos_x] == 'C'
		|| game->mlx_map[game->pos_y - 1][game->pos_x] == '0')
	{
		if (game->mlx_map[game->pos_y - 1][game->pos_x] == 'C')
			game->check_coin--;
		game_print_up(game);
	}
	else if (game->mlx_map[game->pos_y - 1][game->pos_x] == 'E'
		&& game->check_coin != 0)
	{
		if (game->mlx_map[game->pos_y - 2][game->pos_x] == 'C')
			game->check_coin--;
		game_print_up_exit(game);
	}
	else if (game->mlx_map[game->pos_y - 1][game->pos_x] == 'E'
		&& game->check_coin == 0)
	{
		game_print_up(game);
		ft_printf("You win in %d moves\n", game->move);
		close_game(game);
	}
}

void	move_down(t_game *game)
{
	if (game->mlx_map[game->pos_y + 1][game->pos_x] == 'C'
		|| game->mlx_map[game->pos_y + 1][game->pos_x] == '0')
	{
		if (game->mlx_map[game->pos_y + 1][game->pos_x] == 'C')
			game->check_coin--;
		game_print_down(game);
	}
	else if (game->mlx_map[game->pos_y + 1][game->pos_x] == 'E'
		&& game->check_coin != 0)
	{
		if (game->mlx_map[game->pos_y + 2][game->pos_x] == 'C')
			game->check_coin--;
		game_print_down_exit(game);
	}
	else if (game->mlx_map[game->pos_y + 1][game->pos_x] == 'E'
		&& game->check_coin == 0)
	{
		game_print_down(game);
		ft_printf("You win in %d moves\n", game->move);
		close_game(game);
	}
}

int	key_hook(int keycode, t_game *game)
{
	mlx_hook(game->win, 17, 0, close_window, game);
	if (keycode == KEY_ESC)
		close_game(game);
	if (keycode == KEY_W)
		move_up(game);
	if (keycode == KEY_A)
		move_left(game);
	if (keycode == KEY_S)
		move_down(game);
	if (keycode == KEY_D)
		move_right(game);
	return (0);
}
