/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:17:11 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/13 22:00:39 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "map.h"
# include "mlx.h"
# include "event.h"

# define WINDOW_X	1600
# define WINDOW_Y	900

enum e_status
{
	IDLE = 0,
	STOP = 1,
	DRAW = 2
};

struct s_fdf
{
	int				status;
	char			*file;
	void			*mlx;
	void			*win;
	void			*img;
	struct s_map	*map;
};

void	create_unit(void *param);
void	destroy_unit(void *param);

int		loophook(t_list *units);
int		destroyhook(struct s_fdf *fdf);
int		keyhook(int keycode, struct s_fdf *fdf);
int		mousehook(int button, int x, int y, struct s_fdf *fdf);
#endif
