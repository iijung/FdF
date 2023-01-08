/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:39:10 by minjungk          #+#    #+#             */
/*   Updated: 2023/01/08 20:16:09 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	motion_notify(int x, int y, struct s_fdf *fdf)
{
	if (fdf->mouse[0] == 0)
		return (0);
	if (fdf->mouse[0] == 1)
	{
		fdf->translation[0] += x - fdf->mouse[1];
		fdf->translation[1] += y - fdf->mouse[2];
	}
	if (fdf->mouse[0] == 2)
	{
		fdf->rotate[2] += fdf->mouse[2] - y;
		fdf->rotate[2] %= 360;
	}
	if (fdf->mouse[0] == 3)
	{
		fdf->rotate[0] += fdf->mouse[2] - y;
		fdf->rotate[0] %= 360;
		fdf->rotate[1] += fdf->mouse[1] - x;
		fdf->rotate[1] %= 360;
	}
	fdf->mouse[1] = x;
	fdf->mouse[2] = y;
	fdf->status = DRAW;
	return (0);
}

int	button_release(int button, int x, int y, struct s_fdf *fdf)
{
	(void)button;
	fdf->mouse[0] = 0;
	fdf->mouse[1] = x;
	fdf->mouse[2] = y;
	return (0);
}

int	button_press(int button, int x, int y, struct s_fdf *fdf)
{
	if (button == 1 || button == 2 || button == 3)
	{
		fdf->mouse[0] = button;
		fdf->mouse[1] = x;
		fdf->mouse[2] = y;
	}
	if (button == 4)
		fdf->scale += 1;
	else if (button == 5)
	{
		fdf->scale -= 1;
		if (fdf->scale < 1)
			fdf->scale = 1;
	}
	else
		return (0);
	fdf->status = DRAW;
	return (0);
}
