/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:41:29 by vandre            #+#    #+#             */
/*   Updated: 2023/11/15 17:12:58 by vandre           ###   ########.fr       */
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
				return (1);
			else
				return (0);
		}
		args++;
	}
	return (0);
}

void	check_size(t_game *game, char *map_path)
{
	char	*line;
	int		fd;

	game->height = 0;
	game->width = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0 || read(fd, &line, 0) < 0)
		return (ft_printf("Map not open\n"), exit (1));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->height++;
		free(line);
	}
	close(fd);
}

void	fill_map(t_game *game, char *map_path)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map_path, O_RDONLY);
	game->map = ft_calloc((game->height + 1), sizeof(char *));
	if (!game->map)
		return (ft_printf("Malloc error\n"), exit (1));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map[i] = ft_strdup(line);
		if (!game->map[i])
			return (ft_printf("Malloc error\n"), exit (1));
		free(line);
		i++;
	}
	game->map[i] = NULL;
}