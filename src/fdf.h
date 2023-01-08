/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:17:11 by minjungk          #+#    #+#             */
/*   Updated: 2023/01/08 18:44:06 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "map.h"
# include "mlx.h"
# include "event.h"
# define _USE_MATH_DEFINES
# include <math.h>

# define WINDOW_X	1600
# define WINDOW_Y	900

enum e_status
{
	IDLE = 0,
	STOP = 1,
	DRAW = 2
};

struct s_envinorment
{
	int	scale;
	int	rotate[3];
	int	translation[3];
	int	mouse[3];
};

struct s_fdf
{
	int						status;
	char					*file;
	void					*mlx;
	void					*win;
	void					*img;
	struct s_map			*map;
	struct s_envinorment	env;
};

void	create_unit(void *param);
void	destroy_unit(void *param);

int		loophook(t_list *units);
void	inithook(struct s_fdf *fdf);

void	drawline(struct s_fdf *fdf, t_vertex *v0, t_vertex *v1);
void	draw_rect(struct s_fdf *fdf, int width, int height, int color);
void	generate_guide(struct s_fdf *fdf);
void	generate_image(struct s_fdf *fdf);
#endif
