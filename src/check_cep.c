/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 01:55:08 by vandre            #+#    #+#             */
/*   Updated: 2023/11/21 02:04:01 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_player(t_game *game)
{
	if (game->is_player < 1)
		return (ft_printf("Error\nAt least one player is needed\n"), exit(1));
	if (game->is_player > 1)
		return (ft_printf("Error\nOnly one player is needed\n"), exit(1));
}

void	check_exit(t_game *game)
{
	if (game->is_exit < 1)
		return (ft_printf("Error\nAt least one exit is needed\n"), exit(1));
	if (game->is_exit > 1)
		return (ft_printf("Error\nOnly one exit is needed\n"), exit(1));
}

void	check_coins(t_game *game)
{
	if (game->is_coin < 1)
		return (ft_printf("Error\nAt least one coin needed\n"), exit(1));
}
