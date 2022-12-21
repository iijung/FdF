/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:39:10 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/17 10:43:51 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	motion_notify(int x, int y, struct s_fdf *fdf)
{
	if (fdf->env.mouse[0] == 0)
		return (0);
	if (fdf->env.mouse[0] == 1)
	{
		fdf->env.translation[0] += x - fdf->env.mouse[1];
		fdf->env.translation[1] += y - fdf->env.mouse[2];
	}
	if (fdf->env.mouse[0] == 2)
	{
		fdf->env.rotate[2] += fdf->env.mouse[2] - y;
		fdf->env.rotate[2] %= 360;
	}
	if (fdf->env.mouse[0] == 3)
	{
		fdf->env.rotate[0] += fdf->env.mouse[2] - y;
		fdf->env.rotate[0] %= 360;
		fdf->env.rotate[1] += fdf->env.mouse[1] - x;
		fdf->env.rotate[1] %= 360;
	}
	fdf->env.mouse[1] = x;
	fdf->env.mouse[2] = y;
	fdf->status = DRAW;
	return (0);
}

int	button_release(int button, int x, int y, struct s_fdf *fdf)
{
	(void)button;
	fdf->env.mouse[0] = 0;
	fdf->env.mouse[1] = x;
	fdf->env.mouse[2] = y;
	return (0);
}

int	button_press(int button, int x, int y, struct s_fdf *fdf)
{
	if (button == 1 || button == 2 || button == 3)
	{
		fdf->env.mouse[0] = button;
		fdf->env.mouse[1] = x;
		fdf->env.mouse[2] = y;
	}
	if (button == 4)
		fdf->env.scale += 1;
	else if (button == 5)
	{
		fdf->env.scale -= 1;
		if (fdf->env.scale < 1)
			fdf->env.scale = 1;
	}
	else
		return (0);
	fdf->status = DRAW;
	return (0);
}
