/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:13:04 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/09 18:14:49 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	destroy_unit(void *param)
{
	struct s_fdf	*fdf;

	if (param == NULL)
		return ;
	fdf = param;
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->map)
		free(fdf->map);
	fdf->win = NULL;
	fdf->img = NULL;
	fdf->map = NULL;
	fdf->status = EXIT;
}

void	create_unit(void *param)
{
	struct s_fdf	*fdf;

	if (param == NULL)
		return ;
	fdf = param;
	fdf->win = mlx_new_window(fdf->mlx, WINDOW_X, WINDOW_Y, fdf->file);
	fdf->img = mlx_new_image(fdf->mlx, WINDOW_X, WINDOW_Y);
	fdf->map = import_map(fdf->file);
	if (fdf->win == NULL || fdf->img == NULL || fdf->map == NULL)
	{
		destroy_unit(param);
		return ;
	}
	mlx_key_hook(fdf->win, keyhook, fdf);
//	mlx_mouse_hook(fdf->win, mousehook, fdf);
	mlx_expose_hook(fdf->win, exposehook, fdf);
	mlx_hook(fdf->win, DestroyNotify, 0, destroyhook, fdf);
}

int	main(int argc, char **argv)
{
	int				i;
	void			*mlx;
	t_list			*curr;
	t_list			*units;

	mlx = mlx_init();
	ft_except(mlx == NULL, __FILE__, __LINE__, 1);
	i = 0;
	while (++i < argc)
	{
		curr = ft_lstnew(NULL);
		ft_except(curr == NULL, __FILE__, __LINE__, 1);
		curr->content = ft_calloc(1, sizeof(struct s_fdf));
		ft_except(curr->content == NULL, __FILE__, __LINE__, 1);
		((struct s_fdf *)curr->content)->mlx = mlx;
		((struct s_fdf *)curr->content)->file = argv[i];
		ft_lstadd_front(&units, curr);
	}
	ft_lstiter(units, create_unit);
	mlx_loop_hook(mlx, loophook, units);
	mlx_loop(mlx);
	exit(EXIT_SUCCESS);
}
