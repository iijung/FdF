/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_except.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 03:11:34 by minjungk          #+#    #+#             */
/*   Updated: 2024/08/18 06:52:43 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	ft_except(int condition, char *file, int line, int is_exit)
{
	const int	save_errno = errno;

	if (condition == 0)
	{
		errno = 0;
		return ;
	}
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putchar_fd(':', STDERR_FILENO);
	ft_putnbr_fd(line, STDERR_FILENO);
	errno = save_errno;
	perror(":");
	if (is_exit)
		exit(EXIT_FAILURE);
	else
		errno = 0;
}
