/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 07:37:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/01/08 14:37:38 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "theme.h"

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

	cos0 = cos(M_PI * fdf->env.rotate[0] / 180);
	sin0 = sin(M_PI * fdf->env.rotate[0] / 180);
	prev = v->ty;
	v->ty = cos0 * prev - sin0 * v->tz;
	v->tz = sin0 * prev + cos0 * v->tz;
	cos0 = cos(M_PI * fdf->env.rotate[1] / 180);
	sin0 = sin(M_PI * fdf->env.rotate[1] / 180);
	prev = v->tx;
	v->tx = cos0 * prev + sin0 * v->tz;
	v->tz = -sin0 * prev + cos0 * v->tz;
	cos0 = cos(M_PI * fdf->env.rotate[2] / 180);
	sin0 = sin(M_PI * fdf->env.rotate[2] / 180);
	prev = v->tx;
	v->tx = cos0 * prev - sin0 * v->ty;
	v->ty = sin0 * prev + cos0 * v->ty;
	v->tx *= fdf->env.scale;
	v->ty *= fdf->env.scale;
	v->tx = v->tx + WINDOW_X / 2 + fdf->env.translation[0];
	v->ty = v->ty + WINDOW_Y / 2 + fdf->env.translation[1];
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
			v->tx = v->x;
			v->ty = v->y;
			v->tz = v->z;
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
