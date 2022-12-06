/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:13:04 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/07 05:09:31 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	struct s_fdf	fdf;

	if (argc != 2)
		exit(EXIT_FAILURE);
	fdf.map = import_map(argv[1]);
	ft_except(fdf.map == NULL, __FILE__, __LINE__, 1);
	exit(EXIT_SUCCESS);
}
