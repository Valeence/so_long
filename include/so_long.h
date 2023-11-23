/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:37:34 by vandre            #+#    #+#             */
/*   Updated: 2023/11/23 18:35:41 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/include/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*coin;
	void	*exit;
}				t_img;

typedef struct s_game
{
	char	**map;
	char	**flood_map;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		is_coin;
	int		is_exit;
	int		is_player;
	int		pos_x;
	int		pos_y;
	int		check_coin;
	int		check_exit;
	t_img	img;
}				t_game;

int		check_arg(char *str);
void	check_size(t_game *game, char *map_path);
void	fill_map(t_game *game, char *map_path);
int		ft_strlen_sl(char *str);
void	check_map(t_game *game);
void	check_top_bottom(t_game *game);
void	check_chars(t_game *game);
void	check_square(t_game *game);
void	check_boundy(t_game *game);
void	check_player(t_game *game);
void	check_exit(t_game *game);
void	check_coins(t_game *game);
void	check_path(t_game *game);
int		flood_fill(t_game *game, int x, int y);
void	init_mlx(t_game *game);

#endif