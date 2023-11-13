/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:16:36 by vandre            #+#    #+#             */
/*   Updated: 2023/11/13 20:15:24 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	valide_char(char c)
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
	if (collectible > 1 || exit > 1 || start > 1)
	{
		ft_printf("map need only one start, one exit and one collectible\n");
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
		if (!valide_char(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_bottom(const char *line, size_t *len)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	if (i != *len)
		return (0);
	return (1);
}

int	check_map(char *line, size_t *len, int fd)
{
	int		i;
	size_t	nb_gnl;

	i = 0;
	nb_gnl = count_gnl(line);
	while (line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	*len = i;
	while (nb_gnl > 1)
	{
		line = get_next_line(fd);
		if (!check_wall(line, len))
			return (0);
		nb_gnl--;
	}
	if (!check_bottom(line, len))
		return (0);
	return (1);
}

int	valide_map(int fd)
{
	char	*line;
	size_t	len;

	len = 0;
	line = NULL;
	line = get_next_line(fd);
	if (check_map(line, &len, fd))
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}
