/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:16:36 by vandre            #+#    #+#             */
/*   Updated: 2023/11/15 17:49:25 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_square(t_game *game)
{
	int	i;

	i = game->height;
	if (game->height < 3 || game->width < 5)
		return (ft_printf("Size is not correct\n"), exit (1));
	while (game->map[i])
	{

	}
}


void	check_top_bottom(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[0][i] != '\n')
	{
		if (game->map[0][i] != '1')
			return (ft_printf("Error Invalid top map\n"), exit (1));
		i++;
	}
	while (game->map[game->height - 1][j] != '\0')
	{
		if (game->map[game->height - 1][j] != '1')
			return (ft_printf("Error Invalid bottom map\n"), exit (1));
		j++;
	}
	if (i != j)
		return (ft_printf("Error Invalid map\n"), exit (1));
	game->width = i;
	if (game->height < 3 || game->width < 3)
		return (ft_printf("Ergfdgdsfgror Invalid map\n"), exit (1));
}

void	check_map(t_game *game)
{
	game->is_coin = 0;
	game->is_exit = 0;
	game->is_player = 0;
	check_top_bottom(game);
	// check_chars(game);
	check_square(game);
}
