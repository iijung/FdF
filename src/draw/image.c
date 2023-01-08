/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 07:37:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/01/09 01:08:58 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vertex	*get_vertex(struct s_map *map, int col, int row)
{
	if (map == NULL || map->width <= col || map->height <= row)
		return (NULL);
	return (map->vertices + (map->width * row) + col);
}

static void	transform(struct s_fdf *fdf, t_vertex *v)
{
	double	cos0;
	double	sin0;
	double	prev;

	cos0 = cos(M_PI * fdf->rotate[0] / 180);
	sin0 = sin(M_PI * fdf->rotate[0] / 180);
	prev = v->cur.y;
	v->cur.y = cos0 * prev - sin0 * v->cur.z;
	v->cur.z = sin0 * prev + cos0 * v->cur.z;
	cos0 = cos(M_PI * fdf->rotate[1] / 180);
	sin0 = sin(M_PI * fdf->rotate[1] / 180);
	prev = v->cur.x;
	v->cur.x = cos0 * prev + sin0 * v->cur.z;
	v->cur.z = -sin0 * prev + cos0 * v->cur.z;
	cos0 = cos(M_PI * fdf->rotate[2] / 180);
	sin0 = sin(M_PI * fdf->rotate[2] / 180);
	prev = v->cur.x;
	v->cur.x = cos0 * prev - sin0 * v->cur.y;
	v->cur.y = sin0 * prev + cos0 * v->cur.y;
	v->cur.x *= fdf->scale;
	v->cur.y *= fdf->scale;
	v->cur.x = v->cur.x + WINDOW_X / 2 + fdf->translation[0];
	v->cur.y = v->cur.y + WINDOW_Y / 2 + fdf->translation[1];
}

void	projection(struct s_fdf *fdf)
{
	int			col;
	int			row;
	t_vertex	*v;

	row = -1;
	while (++row < fdf->map->height)
	{
		col = -1;
		while (++col < fdf->map->width)
		{
			v = get_vertex(fdf->map, col, row);
			if (v == NULL)
				continue ;
			v->cur.x = v->org.x;
			v->cur.y = v->org.y;
			v->cur.z = v->org.z;
			transform(fdf, v);
		}
	}
}

void	generate_image(struct s_fdf *fdf)
{
	int				row;
	int				col;
	struct s_vertex	*vertex[2];

	if (fdf == NULL)
		return ;
	draw_rect(fdf, WINDOW_X, WINDOW_Y, 0);
	projection(fdf);
	row = -1;
	while (++row < fdf->map->height)
	{
		col = -1;
		while (++col < fdf->map->width)
		{
			vertex[0] = get_vertex(fdf->map, col, row);
			vertex[1] = get_vertex(fdf->map, col, row + 1);
			if (vertex[0] && vertex[1])
				drawline(fdf, vertex[0], vertex[1]);
			vertex[1] = get_vertex(fdf->map, col + 1, row);
			if (vertex[0] && vertex[1])
				drawline(fdf, vertex[0], vertex[1]);
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
