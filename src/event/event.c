/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:56:34 by minjungk          #+#    #+#             */
/*   Updated: 2023/01/11 18:07:41 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	loop(struct s_fdf *fdf)
{
	if (fdf == NULL)
		return ;
	generate_image(fdf);
	generate_guide(fdf);
	fdf->status = IDLE;
}

int	loophook(t_list *units)
{
	t_list			*curr;
	t_list			*next;
	struct s_fdf	*fdf;

	curr = units;
	while (curr && curr->next)
	{
		next = curr->next;
		fdf = next->content;
		if (fdf == NULL || fdf->status == STOP)
		{
			next = next->next;
			ft_lstdelone(curr->next, destroy_unit);
			curr->next = next;
			continue ;
		}
		else if (fdf->status != IDLE)
			loop(fdf);
		curr = next;
	}
	if (units->next == NULL)
		exit(EXIT_SUCCESS);
	return (0);
}

int	key_press(int keycode, struct s_fdf *fdf);
int	button_press(int button, int x, int y, struct s_fdf *fdf);
int	button_release(int button, int x, int y, struct s_fdf *fdf);
int	motion_notify(int x, int y, struct s_fdf *fdf);

int	destroyhook(struct s_fdf *fdf)
{
	if (fdf == NULL)
		return (0);
	fdf->status = STOP;
	return (0);
}

void	inithook(struct s_fdf *fdf)
{
	mlx_hook(fdf->win, KeyPress, KeyPressMask, key_press, fdf);
	mlx_hook(fdf->win, ButtonPress, ButtonPressMask, button_press, fdf);
	mlx_hook(fdf->win, ButtonRelease, ButtonReleaseMask, button_release, fdf);
	mlx_hook(fdf->win, MotionNotify, ButtonMotionMask, motion_notify, fdf);
	mlx_hook(fdf->win, DestroyNotify, 0, destroyhook, fdf);
}
