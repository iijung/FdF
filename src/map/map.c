/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:37:43 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/05 13:53:24 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

struct s_map	*import_map(char *file)
{
	struct s_map	*map;

	map = ft_calloc(1, sizeof(struct s_map));
	ft_except(map == NULL, __FILE__, __LINE__, 1);
	if (parse_file(map, file) < 0)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(" parsing failed.\n", 2);
		free(map);
		return (NULL);
	}
	return (map);
}
