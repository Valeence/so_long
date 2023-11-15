/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:56:36 by vandre            #+#    #+#             */
/*   Updated: 2023/11/15 14:35:39 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	static t_game	game = {0};

	if (argc != 2)
		return (ft_printf("Usage:./so_long map.ber\n"));
	if (!check_arg(argv[1]))
		return (ft_printf("Error\nInvalid map\n"));
	check_size(&game, argv[1]);
	fill_map(&game, argv[1]);
	check_map(&game);
	ft_printf("OK\n");
	return (0);
}	
