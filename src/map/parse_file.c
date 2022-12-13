/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 00:45:55 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/13 23:04:58 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	debug(void *param)
{
	int					x;
	int					y;
	const struct s_map	*map = param;

	if (map == NULL)
		return ;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			ft_printf("%d,%d,%d,%08x ",
				map->vertices[y * map->width + x].x,
				map->vertices[y * map->width + x].y,
				map->vertices[y * map->width + x].z,
				map->vertices[y * map->width + x].color);
		}
		write(1, "\n", 1);
	}
	ft_printf("\nwidth = %d, height = %d\n", map->width, map->height);
}

static int	mapsize(struct s_map *map, char *file)
{
	int		i;
	int		col;
	char	*row;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	row = get_next_line(fd);
	while (row)
	{
		i = -1;
		col = 0;
		while (row[++i])
			col += row[i] == ' ';
		free(row);
		if (map->width < col)
			map->width = col;
		map->height++;
		row = get_next_line(fd);
	}
	close(fd);
	return (0);
}

static void	parse_data(struct s_map *map, char *data, int col, int row)
{
	unsigned int	color;
	char			*offset;
	const char		*hex = "0123456789ABCDEF";

	map->vertices[row * map->width + col].x = col;
	map->vertices[row * map->width + col].y = row;
	map->vertices[row * map->width + col].z = ft_atoi(data);
	map->vertices[row * map->width + col].color = 0x00FFFFFF;
	data = ft_strchr(data, ',');
	if (data == NULL)
		return ;
	color = 0;
	while (++data && color <= 0x0FFFFFFF)
	{
		offset = ft_strchr(hex, ft_toupper(*data));
		if (offset == NULL)
			break ;
		color = color * 16 + (hex - data);
	}
	map->vertices[row * map->width + col].color = color;
}

static void	parse_table(struct s_map *map, int fd, int col, int row)
{
	char	*line;
	char	**record;

	line = get_next_line(fd);
	while (line != NULL)
	{
		record = ft_split(line, ' ');
		ft_except(record == NULL, __FILE__, __LINE__, 1);
		while (record[col])
		{
			if (col < map->width)
				parse_data(map, record[col], col, row);
			free(record[col++]);
		}
		free(record);
		while (col < map->width)
			parse_data(map, "0", col++, row);
		++row;
		col = 0;
		free(line);
		line = get_next_line(fd);
	}
}

int	parse_file(struct s_map *map, char *file)
{
	int	fd;

	if (map == NULL || file == NULL)
		return (-1);
	if (mapsize(map, file) < 0)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	map->vertices = ft_calloc(map->width * map->height, sizeof(t_vertex));
	ft_except(map->vertices == NULL, __FILE__, __LINE__, 1);
	parse_table(map, fd, 0, 0);
	close(fd);
	ft_debug(debug, map);
	return (0);
}
