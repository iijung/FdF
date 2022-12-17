/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:11:51 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/17 09:10:24 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_pixel(struct s_fdf *fdf, int x, int y, int color)
{
	char	*addr;
	int		size_line;
	int		bpp;
	int		endian;

	if (x < 0 || y < 0 || x > WINDOW_X || y > WINDOW_Y)
		return ;
	color = mlx_get_color_value(fdf->mlx, color);
	addr = mlx_get_data_addr(fdf->img, &bpp, &size_line, &endian);
	*(unsigned int *)(addr + (y * size_line + x * (bpp / 8))) = color;
}

void	drawline(struct s_fdf *fdf, t_vertex *v0, t_vertex *v1)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	int		step;
	int		color;

	dx = v1->tx - v0->tx;
	dy = v1->ty - v0->ty;
	if (abs((int)dx) > abs((int)dy))
		step = abs((int)dx);
	else
		step = abs((int)dy);
	dx /= step;
	dy /= step;
	x = v0->tx;
	y = v0->ty;
	color = v0->color;
	float r = (((v1->color >> 16) & 0xFF) - ((v0->color >> 16) & 0xFF));
	float g = (((v1->color >> 8) & 0xFF) - ((v0->color >> 8) & 0xFF));
	float b = (v1->color & 0xFF) - (v0->color & 0xFF);
	if (step)
	{
		r /= step;
		g /= step;
		b /= step;
	}
	float e[3] = {0, 0, 0};
	set_pixel(fdf, x, y, color);
	while (step--)
	{
		x += dx;
		y += dy;
		{
			color = v0->color;
			e[0] += r;
			e[1] += g;
			e[2] += b;
			color += 0x00010000 * (int)e[0];
			color += 0x00000100 * (int)e[1];
			color += 0x00000001 * (int)e[2];
			color = mlx_get_color_value(fdf->mlx, color);
		}
		set_pixel(fdf, x, y, color);
	}
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
