/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:56:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/11 03:30:41 by minjungk         ###   ########.fr       */
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
			mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
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

int	mousehook(int button, int x, int y, struct s_fdf *fdf)
{
	(void)fdf;
	ft_printf("mousehook [%d](%d, %d)\n", button, x, y);
	return (0);
}

int	keyhook(int keycode, struct s_fdf *fdf)
{
	(void)fdf;
	if (keycode == VK_Escape)
		exit(EXIT_SUCCESS);
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
