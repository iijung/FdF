/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 05:25:35 by minjungk          #+#    #+#             */
/*   Updated: 2023/01/08 20:16:27 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "theme.h"

static void	mapinfo(struct s_fdf *fdf)
{
	char	*str;

	mlx_string_put(fdf->mlx, fdf->win, 10, 30, FOREGROUND1, "# map info");
	mlx_string_put(fdf->mlx, fdf->win, 20, 50, FOREGROUND0, "width : ");
	str = ft_itoa(fdf->map->width);
	mlx_string_put(fdf->mlx, fdf->win, 140, 50, FOREGROUND2, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->win, 20, 70, FOREGROUND0, "height : ");
	str = ft_itoa(fdf->map->height);
	mlx_string_put(fdf->mlx, fdf->win, 140, 70, FOREGROUND2, str);
	free(str);
}

static void	setinfo(struct s_fdf *fdf)
{
	char	*str;

	mlx_string_put(fdf->mlx, fdf->win, 10, 100, FOREGROUND1, "# settings");
	mlx_string_put(fdf->mlx, fdf->win, 20, 120, FOREGROUND0, "scale : ");
	str = ft_itoa(fdf->scale);
	mlx_string_put(fdf->mlx, fdf->win, 140, 120, FOREGROUND2, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->win, 20, 140, FOREGROUND0, "rorate x : ");
	str = ft_itoa(fdf->rotate[0]);
	mlx_string_put(fdf->mlx, fdf->win, 140, 140, FOREGROUND2, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->win, 20, 160, FOREGROUND0, "rorate y : ");
	str = ft_itoa(fdf->rotate[1]);
	mlx_string_put(fdf->mlx, fdf->win, 140, 160, FOREGROUND2, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->win, 20, 180, FOREGROUND0, "rorate z : ");
	str = ft_itoa(fdf->rotate[2]);
	mlx_string_put(fdf->mlx, fdf->win, 140, 180, FOREGROUND2, str);
	free(str);
}

void	generate_guide(struct s_fdf *fdf)
{
	mapinfo(fdf);
	setinfo(fdf);
}
