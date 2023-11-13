/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:56:36 by vandre            #+#    #+#             */
/*   Updated: 2023/11/12 20:51:11 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_printf("Error\nUsage:./so_long [map/map.ber]\n"));
	if (!check_arg(argv[1]))
		return (ft_printf("Error\nInvalid map\n"));
	ft_printf("OK\n");
	return (0);
}	
