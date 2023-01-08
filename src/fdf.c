/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:13:04 by minjungk          #+#    #+#             */
/*   Updated: 2023/01/08 22:20:41 by minjungk         ###   ########.fr       */
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
	destroy_map(fdf->map);
	fdf->win = NULL;
	fdf->img = NULL;
	fdf->map = NULL;
	ft_printf("destory unit[%s]\n", fdf->file);
	free(fdf);
}

void	create_unit(void *param)
{
	struct s_fdf	*fdf;

	if (param == NULL)
		return ;
	fdf = param;
	ft_printf("create unit[%s]\n", fdf->file);
	fdf->win = mlx_new_window(fdf->mlx, WINDOW_X, WINDOW_Y, fdf->file);
	fdf->img = mlx_new_image(fdf->mlx, WINDOW_X, WINDOW_Y);
	if (fdf->win == NULL || fdf->img == NULL)
	{
		fdf->status = STOP;
		return ;
	}
	fdf->scale = 5;
	fdf->rotate[0] = 45;
	fdf->rotate[1] = -35;
	fdf->rotate[2] = 30;
	fdf->status = DRAW;
	inithook(fdf);
}

void	initialize_units(t_list **lst, void *mlx, int cnt, char **files)
{
	int				i;
	t_list			*new;
	struct s_fdf	*fdf;

	if (cnt < 1)
		errno = EINVAL;
	if (lst == NULL || mlx == NULL || files == NULL || cnt < 1)
		ft_except(1, __FILE__, __LINE__, 1);
	*lst = NULL;
	i = -1;
	while (++i < cnt)
	{
		new = ft_lstnew(NULL);
		ft_except(new == NULL, __FILE__, __LINE__, 1);
		new->content = ft_calloc(1, sizeof(struct s_fdf));
		ft_except(new->content == NULL, __FILE__, __LINE__, 1);
		fdf = new->content;
		fdf->mlx = mlx;
		fdf->file = files[i];
		fdf->map = import_map(fdf->file);
		if (fdf->map)
			ft_lstadd_front(lst, new);
	}
}

int	main(int argc, char **argv)
{
	void	*mlx;
	t_list	units;

	mlx = mlx_init();
	ft_except(mlx == NULL, __FILE__, __LINE__, 1);
	initialize_units(&units.next, mlx, argc - 1, argv + 1);
	ft_lstiter(units.next, create_unit);
	mlx_loop_hook(mlx, loophook, &units);
	mlx_loop(mlx);
	exit(EXIT_SUCCESS);
}
