/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:16:36 by vandre            #+#    #+#             */
/*   Updated: 2023/11/12 21:46:17 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_top_bot_map(const char *line, size_t *len)
{
	int	i;
	int	end;

	i = 1;
	if (line[0] != '1')
		return (0);
	end = ft_strlen(line) - 1;
	*len = end;
	if (line[end - 1] != '1')
		return (0);
	while (i < end)
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	count_CEP(char c)
{
	static int	collectible;
	static int	exit;
	static int	start;
	
	if (c == 'C')
		collectible++;
	if (c == 'E')
		exit++;
	if (c == 'P')
		start++;
	if (collectible > 1 || exit > 1 || start > 1)
	{
		ft_printf("map need only one C, E, P\n");
		return (0);
	}
	if (c != 'C' && c != 'E' && c != 'P' && c != '1' && c != '0')
	{
		ft_printf("map need only 0, 1, C, E, P\n");
		return (0);
	}
	return (1);
}

int	check_wall(const char *line, size_t *len)
{
	size_t	i;
	size_t	end;

	i = 1;
	if (line[0] != '1')
		return (0);
	end = ft_strlen(line) - 1;
	if (line[end - 1] != '1')
		return (0);
	if (end != *len)
		return (0);
	while (i < end)
	{
		if (!count_CEP(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parsing_map(const char *map_path)
{
	const char	*line;
	int			fd;
	size_t		len;

	len = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	if (check_top_bot_map(line, &len))
	{
		while (1)
		{
			line = get_next_line(fd);
			if (!check_wall(line, &len))
				return (0);
			if (line == NULL)
				break ;
		}
	}
	return (1);
}
