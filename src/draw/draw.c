/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:11:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/01/08 14:27:39 by minjungk         ###   ########.fr       */
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
	int	val[8];

	enum e_type {dx, dy, sx, sy, e, e2, x, y};
	val[dx] = abs(v1->tx - v0->tx);
	val[dy] = abs(v1->ty - v0->ty);
	val[sx] = 2 * (v0->tx < v1->tx) - 1;
	val[sy] = 2 * (v0->ty < v1->ty) - 1;
	val[e] = val[dx] - val[dy];
	val[x] = v0->tx;
	val[y] = v0->ty;
	while (!(val[x] == v1->tx && val[y] == v1->ty))
	{
		set_pixel(fdf, val[x], val[y], v0->color);
		val[e2] = 2 * val[e];
		val[e] -= val[dy] * (val[e2] > -val[dy]);
		val[x] += val[sx] * (val[e2] > -val[dy]);
		val[e] += val[dx] * (val[e2] < val[dx]);
		val[y] += val[sy] * (val[e2] < val[dx]);
	}
	set_pixel(fdf, val[x], val[y], v0->color);
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
