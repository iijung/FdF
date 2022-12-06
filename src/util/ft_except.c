/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_except.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 03:11:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/04 17:08:54 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	ft_except(int condition, char *file, int line, int is_exit)
{
	if (condition == 0)
	{
		errno = 0;
		return ;
	}
	ft_putstr_fd(file, 2);
	write(2, ":", 1);
	ft_putnbr_fd(line, 2);
	perror(":");
	if (is_exit)
		exit(EXIT_FAILURE);
}
