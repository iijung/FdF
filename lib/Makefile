# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:09:11 by minjungk          #+#    #+#              #
#    Updated: 2023/12/04 07:02:20 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:
.DEFAULT_GOAL := all

MAKEFLAGS	= -j 8

LIBS		=	libft/libft.a

all bonus clean fclean re:
	@for dir in $(dir $(LIBS)); do \
		$(MAKE) -C $$dir $@; \
	done

.PHONY: all clean fclean re bonus
