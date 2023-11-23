/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:11:53 by vandre            #+#    #+#             */
/*   Updated: 2023/11/23 18:49:28 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_mlx(t_game *game)
{
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "../Asset/floor.xpm",
			&game->pos_x, &game->pos_y);
	mlx_put_image_to_window(game->mlx, game->win, game->img.floor, 0, 0);
}
