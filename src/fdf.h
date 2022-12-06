/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:17:11 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/07 04:55:11 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "map.h"

# define WINDOW_X	1600
# define WINDOW_Y	900

struct s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	struct s_map	*map;
};
#endif
