/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:17:11 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/09 18:06:17 by minjungk         ###   ########.fr       */
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
	DRAW = 1,
	STOP = 2,
	EXIT = 3
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

int		loophook(t_list **);
int		destroyhook(struct s_fdf *fdf);
int		exposehook(struct s_fdf *fdf);
int		mousehook(int x, int y, struct s_fdf *fdf);
int		keyhook(int keycode, struct s_fdf *fdf);
#endif
