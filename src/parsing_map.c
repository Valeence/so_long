/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:16:36 by vandre            #+#    #+#             */
/*   Updated: 2023/11/15 11:19:41 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	valide_char(char c, size_t len_gnl)
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
	if (c != 'C' && c != 'E' && c != 'P' && c != '1' && c != '0')
	{
		ft_printf("map need only 0, 1, C, E, P\n");
		return (0);
	}
	if (len_gnl == 3)
	{
		if (collectible != 1 && exit != 1 && start != 1)
		{
			ft_printf("map need only one start, one exit and one collectible\n");
			return (0);
		}
	}
	return (1);
}

int	check_wall(const char *line, size_t len, size_t len_gnl)
{
	size_t	i;
	size_t	end;

	i = 1;
	if (line[0] != '1')
		return (0);
	end = ft_strlen(line) - 1;
	if (line[end - 1] != '1')
		return (0);
	if (end != len)
		return (0);
	while (i < end)
	{
		if (!valide_char(line[i], len_gnl))
			return (0);
		i++;
	}
	return (1);
}

int	check_bottom(const char *line, size_t len)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1')
			return (ft_printf("bottom need only 1\n"));
		i++;
	}
	if (i != len)
		return (ft_printf("bottom need same len as other"));
	return (1);
}

int	check_map(const char *line, size_t len, int fd, size_t len_gnl)
{
	int		i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '1')
			return (ft_printf("top map need only 1\n"));
		i++;
	}
	len = i;
	while (len_gnl > 2)
	{
		line = get_next_line(fd);
		if (!check_wall(line, len, len_gnl))
			return (0);
		len_gnl--;
	}
	line = get_next_line(fd);
	if (!check_bottom(line, len))
		return (0);
	if (len_gnl > len)
		return (0);
	return (1);
}

int	valide_map(int fd, size_t len_gnl)
{
	const char	*line;
	size_t		len;

	len = 0;
	line = NULL;
	line = get_next_line(fd);
	if (!check_map(line, len, fd, len_gnl))
	{
		free((char *)line);
		return (0);
	}
	free((char *)line);
	return (1);
}
