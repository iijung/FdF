/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:11:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/01/09 02:13:09 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_pixel(struct s_fdf *fdf, int x, int y, int color)
{
	char	*addr;
	int		size_line;
	int		bpp;
	int		endian;

	if (x < 0 || y < 0 || x >= WINDOW_X || y >= WINDOW_Y)
		return ;
	color = mlx_get_color_value(fdf->mlx, color);
	addr = mlx_get_data_addr(fdf->img, &bpp, &size_line, &endian);
	*(unsigned int *)(addr + (y * size_line + x * (bpp / 8))) = color;
}

void	drawline(struct s_fdf *fdf, t_vertex *v0, t_vertex *v1)
{
	int	v[10];

	enum e_type {dx, dy, sx, sy, e, e2, x0, y0, x1, y1};
	v[x0] = round(v0->cur.x);
	v[y0] = round(v0->cur.y);
	v[x1] = round(v1->cur.x);
	v[y1] = round(v1->cur.y);
	v[dx] = abs(v[x1] - v[x0]);
	v[dy] = abs(v[y1] - v[y0]);
	v[sx] = 2 * (v[x0] < v[x1]) - 1;
	v[sy] = 2 * (v[y0] < v[y1]) - 1;
	v[e] = v[dx] - v[dy];
	while (!(v[x0] == v[x1] && v[y0] == v[y1]))
	{
		if (abs(v[x0]) >= WINDOW_X || abs(v[y0]) >= WINDOW_Y)
			break ;
		set_pixel(fdf, v[x0], v[y0], v0->color.c);
		v[e2] = 2 * v[e];
		v[e] -= v[dy] * (v[e2] > -v[dy]);
		v[x0] += v[sx] * (v[e2] > -v[dy]);
		v[e] += v[dx] * (v[e2] < v[dx]);
		v[y0] += v[sy] * (v[e2] < v[dx]);
	}
	set_pixel(fdf, v[x0], v[y0], v0->color.c);
}

void	draw_rect(struct s_fdf *fdf, int width, int height, int color)
{
	int	row;
	int	col;

	if (fdf == NULL)
		return ;
	row = -1;
	while (++row < height)
	{
		col = -1;
		while (++col < width)
			set_pixel(fdf, col, row, color);
	}
}
