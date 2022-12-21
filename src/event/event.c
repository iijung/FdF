/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:56:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/17 10:41:54 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	loophook(t_list *units)
{
	int				cnt;
	struct s_fdf	*fdf;

	cnt = ft_lstsize(units);
	while (units)
	{
		fdf = units->content;
		if (fdf == NULL || fdf->status == STOP)
		{
			destroy_unit(units->content);
			units->content = NULL;
			--cnt;
		}
		else if (fdf->status != IDLE)
		{
			mlx_clear_window(fdf->mlx, fdf->win);
			generate_image(fdf);
			generate_guide(fdf);
			fdf->status = IDLE;
		}
		units = units->next;
	}
	if (cnt == 0)
		exit(EXIT_SUCCESS);
	return (0);
}

int	destroyhook(struct s_fdf *fdf)
{
	if (fdf == NULL)
		return (0);
	fdf->status = STOP;
	return (0);
}

int	keyhook(int keycode, struct s_fdf *fdf)
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
