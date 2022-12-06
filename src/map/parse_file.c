/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 00:45:55 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/07 05:10:17 by minjungk         ###   ########.fr       */
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
	int				len;
	unsigned int	color;
	char			*tmp;

	map->vertices[row * map->width + col].x = col;
	map->vertices[row * map->width + col].y = row;
	map->vertices[row * map->width + col].z = ft_atoi(data);
	map->vertices[row * map->width + col].color = 0x00FFFFFF;
	tmp = ft_strnstr(data, ",0X", ft_strlen(data));
	if (tmp == NULL)
		return ;
	len = 2;
	color = 0;
	while (tmp[++len] && color <= 0x0FFFFFFF)
	{
		if (ft_isdigit(tmp[len]))
			color = color * 16 + tmp[len] - '0';
		else if (ft_strchr("ABCDEF", tmp[len]))
			color = color * 16 + tmp[len] - 'A' + 10;
		else
			break ;
	}
	map->vertices[row * map->width + col].color = color;
}

static void	parse_table(struct s_map *map, int fd, int col, int row)
{
	int		i;
	char	*line;
	char	**record;

	line = get_next_line(fd);
	while (line != NULL)
	{
		record = ft_split(line, ' ');
		ft_except(record == NULL, __FILE__, __LINE__, 1);
		while (record[col])
		{
			i = -1;
			while (record[col][++i])
				record[col][i] = ft_toupper(record[col][i]);
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
