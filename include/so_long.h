/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:37:34 by vandre            #+#    #+#             */
/*   Updated: 2023/11/12 17:17:36 by vandre           ###   ########.fr       */
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

int	check_arg(const char *str);
int	parsing_map(const char *map_path);

#endif