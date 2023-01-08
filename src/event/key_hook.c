/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:39:10 by minjungk          #+#    #+#             */
/*   Updated: 2023/01/08 18:40:24 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int keycode, struct s_fdf *fdf)
{
	if (keycode == VK_Escape)
		exit(EXIT_SUCCESS);
	else if (keycode == VK_Up)
		fdf->env.rotate[0] += 15;
	else if (keycode == VK_Down)
		fdf->env.rotate[0] -= 15;
	else if (keycode == VK_Left)
		fdf->env.rotate[1] += 15;
	else if (keycode == VK_Right)
		fdf->env.rotate[1] -= 15;
	else if (keycode == VK_Return)
		ft_memset(fdf->env.rotate, 0, sizeof(fdf->env.rotate));
	else
		return (0);
	fdf->env.rotate[0] %= 360;
	fdf->env.rotate[1] %= 360;
	fdf->status = DRAW;
	return (0);
}
