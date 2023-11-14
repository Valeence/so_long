/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:41:29 by vandre            #+#    #+#             */
/*   Updated: 2023/11/14 16:53:54 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_arg(char *args)
{
	char	*map_path;

	map_path = malloc(sizeof(char) * (ft_strlen(args) + 1));
	ft_strlcpy(map_path, args, ft_strlen(args) + 1);
	while (*args != '\0')
	{
		if (*args == '.')
		{
			if (*(args + 1) == 'b' && *(args + 2) == 'e'
				&& *(args + 3) == 'r')
			{
				if (parsing_map(map_path))
					return (1);
			}
			else
				return (0);
		}
		args++;
	}
	return (0);
}

int	parsing_map(char *map_path)
{
	int		fd;
	size_t	*len_gnl;

	len_gnl = count_gnl(map_path);
	if (*len_gnl < 3)
		return (0);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	if (valide_map(fd, *len_gnl))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
