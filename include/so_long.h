/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:37:34 by vandre            #+#    #+#             */
/*   Updated: 2023/11/15 16:59:30 by vandre           ###   ########.fr       */
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

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		is_coin;
	int		is_exit;
	int		is_player;
}				t_game;

int		check_arg(char *str);
void	check_size(t_game *game, char *map_path);
void	fill_map(t_game *game, char *map_path);
void	check_map(t_game *game);
void	check_top_bottom(t_game *game);
void	check_chars(t_game *game);
void	check_square(t_game *game);

#endif