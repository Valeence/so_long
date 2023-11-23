/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:27:32 by vandre            #+#    #+#             */
/*   Updated: 2023/11/23 16:53:22 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_img(t_game *game)
{
	void	*mlx;
	// void	*mlx_win;
	void	*img;

	mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1280, 720, "so_long");
	// mlx_loop(mlx);
	img = mlx_new_image(mlx, 1280, 720);
	(void)game;
}
