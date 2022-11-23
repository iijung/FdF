# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:09:11 by minjungk          #+#    #+#              #
#    Updated: 2022/11/23 16:15:00 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

FDF = fdf

all bonus clean fclean re:
	$(MAKE) -C external $@
	$(MAKE) -C lib $@
	$(MAKE) -C src $@

$(FDF):
	$(MAKE) -C external
	$(MAKE) -C lib
	$(MAKE) -C src

.PHONY: all clean fclean re bonus $(FDF)
