/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 05:24:31 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/07 02:27:16 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include "libft.h"
# include <stdio.h>

# ifdef DEBUG
#  define DEBUG	1
# else
#  define DEBUG	0
# endif

void	ft_debug(void (*f)(void *), void *param);
void	ft_except(int condition, char *file, int line, int is_exit);
#endif
