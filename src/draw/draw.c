/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:11:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/01/08 15:46:47 by minjungk         ###   ########.fr       */
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
	int	val[10];

	enum e_type {dx, dy, sx, sy, e, e2, x0, y0, x1, y1};
	val[x0] = round(v0->cur.x);
	val[y0] = round(v0->cur.y);
	val[x1] = round(v1->cur.x);
	val[y1] = round(v1->cur.y);
	val[dx] = abs(val[x1] - val[x0]);
	val[dy] = abs(val[y1] - val[y0]);
	val[sx] = 2 * (val[x0] < val[x1]) - 1;
	val[sy] = 2 * (val[y0] < val[y1]) - 1;
	val[e] = val[dx] - val[dy];
	while (!(val[x0] == val[x1] && val[y0] == val[y1]))
	{
		set_pixel(fdf, val[x0], val[y0], v0->color.c);
		val[e2] = 2 * val[e];
		val[e] -= val[dy] * (val[e2] > -val[dy]);
		val[x0] += val[sx] * (val[e2] > -val[dy]);
		val[e] += val[dx] * (val[e2] < val[dx]);
		val[y0] += val[sy] * (val[e2] < val[dx]);
	}
	set_pixel(fdf, val[x0], val[y0], v0->color.c);
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
