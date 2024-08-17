/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 00:45:55 by minjungk          #+#    #+#             */
/*   Updated: 2024/08/18 06:53:03 by minjungk         ###   ########.fr       */
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
				map->vertices[y * map->width + x].org.x,
				map->vertices[y * map->width + x].org.y,
				map->vertices[y * map->width + x].org.z,
				map->vertices[y * map->width + x].color);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	ft_printf("\nwidth = %d, height = %d\n", map->width, map->height);
}

static int	mapsize(struct s_map *map, char *file)
{
	int		fd;
	int		col;
	char	*line;
	char	**record;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		record = ft_split(line, ' ');
		free(line);
		ft_except(record == NULL, __FILE__, __LINE__, 1);
		col = -1;
		while (record[++col])
			free(record[col]);
		free(record);
		if (map->width < col)
			map->width = col;
		map->height++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

static void	parse_data(struct s_map *map, char *data, int col, int row)
{
	unsigned int	color;
	char			*offset;
	const char		*hex = "0123456789ABCDEF";

	map->vertices[row * map->width + col].org.x = col - map->width / 2;
	map->vertices[row * map->width + col].org.y = row - map->height / 2;
	map->vertices[row * map->width + col].org.z = ft_atoi(data);
	map->vertices[row * map->width + col].color.c = 0x00FFFFFF;
	data = ft_strchr(data, ',');
	if (data == NULL)
		return ;
	if (ft_strncmp(data + 1, "0x", 2) == 0)
		data += 2;
	color = 0;
	while (*++data && color <= 0x0FFFFFFF)
	{
		offset = ft_strchr(hex, ft_toupper(*data));
		if (offset == NULL)
			break ;
		color = color * 16 + (offset - hex);
	}
	map->vertices[row * map->width + col].color.c = color;
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
