/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:56:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/09 18:10:21 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	loophook(t_list **units)
{
	int				i;
	struct s_fdf	*fdf;

	i = -1;
	while (units && units[++i])
	{
		fdf = units[i]->content;
		if (fdf == NULL || fdf->status == EXIT)
			continue ;
		if (fdf->status == STOP)
		{
			destroy_unit(units[i]->content);
			continue ;
		}

	}
	if (fdf == NULL || fdf->status == IDLE)
		return (0);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return (0);
}

int	exposehook(struct s_fdf *fdf)
{
	(void)fdf;
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
		fdf->status = STOP;
#if 0
	else if (keycode == VK_Left)
		draw_rect(fdf, 0x00FF0000);
	else if (keycode == VK_Down)
		draw_map(fdf);
	else if (keycode == VK_Right)
		draw_rect(fdf, 0x000000FF);
	else if (keycode == VK_Up)
		mlx_clear_window(fdf->mlx, fdf->win);
	else if (keycode == VK_Return)
		draw_rect(fdf, 0);
	else
		return (0);
#endif 
	printf("keyhook [%d]\n", keycode);
	return (0);
}
