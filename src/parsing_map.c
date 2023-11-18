/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:16:36 by vandre            #+#    #+#             */
/*   Updated: 2023/11/18 02:35:25 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_chars(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (game->map[j])
	{
		while (game->map[i])
		{
			if (game->map[j][i] != '1' && game->map[j][i] != '0'
				&& game->map[j][i] != 'C' && game->map[j][i] != 'E'
				&& game->map[j][i] != 'P')
				return (ft_printf("Map need to be composed with only 1, 0, C, E, P character\n"), exit (1));
		i++;
		}
	j++;
	i = 0;
	}
}

void	check_square(t_game *game)
{
	int j;

	j = game->height - 2;
	if (game->height < 3 || game->width < 4 || game->height > 15 || game->width > 30)
		return (ft_printf("Size is not correct\n"), exit (1));
	printf("height = %d\n", game->height);
	printf("width = %d\n", game->width);
	printf("map[0] = %s\n", game->map[0]);
	printf("map[1] = %s\n", game->map[1]);
	printf("map[1] = %d\n", (int)ft_strlen(game->map[1]));
	printf("map[2] = %s\n", game->map[2]);
	printf("map[2] = %d\n", (int)ft_strlen(game->map[2]));
	if (game->width != (int)ft_strlen(game->map[game->height] - 1))
		return (ft_printf("Map need to be a squarex\n"), exit (1));
	while (j <= 0)
	{
		if (game->width != (int)ft_strlen(game->map[j]))
			return (ft_printf("Map need to be a square\n"), exit (1));
		j--;
	}
}

void	check_map(t_game *game)
{
	game->is_coin = 0;
	game->is_exit = 0;
	game->is_player = 0;
	check_chars(game);
	check_square(game);
}
