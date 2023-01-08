/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:56:03 by minjungk          #+#    #+#             */
/*   Updated: 2023/01/08 15:42:19 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <fcntl.h>
# include "util.h"

typedef struct s_vertex	t_vertex;

union u_coor
{
	struct
	{
		double	x;
		double	y;
		double	z;
	};
};

union u_color
{
	unsigned int		c;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
};

struct s_vertex
{
	union u_color	color;
	union u_coor	org;
	union u_coor	cur;
};

struct s_map
{
	int			width;
	int			height;
	t_vertex	*vertices;
};

void			destroy_map(struct s_map *map);
struct s_map	*import_map(char *file);
int				parse_file(struct s_map *map, char *file);

#endif
