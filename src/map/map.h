/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:56:03 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/11 04:59:23 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <fcntl.h>
# include "util.h"

typedef struct s_vertex	t_vertex;

struct s_vertex
{
	int	x;
	int	y;
	int	z;
	int	color;
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
