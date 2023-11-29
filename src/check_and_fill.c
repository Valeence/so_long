/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:41:29 by vandre            #+#    #+#             */
/*   Updated: 2023/11/29 18:59:04 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strlen_sl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
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
		if (game->height == 0)
			game->width = ft_strlen(line) - 1;
		game->height++;
		free(line);
	}
	close(fd);
}

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

void	fill_map(t_game *game, char *map_path)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map_path, O_RDONLY);
	game->map = ft_calloc(sizeof(char *), game->height + 1);
	game->mlx_map = ft_calloc(sizeof(char *), game->height + 1);
	if (!game->map || !game->mlx_map)
		return (ft_printf("Malloc error\n"), exit (1));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map[i] = ft_substr(line, 0, ft_strlen_sl(line));
		game->mlx_map[i] = ft_strdup(game->map[i]);
		if (!game->mlx_map[i] || !game->map[i])
			return (ft_printf("Malloc error\n"), exit (1));
		free(line);
		i++;
	}
	game->map[i] = NULL;
	game->mlx_map[i] = NULL;
	close(fd);
}
