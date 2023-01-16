# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:09:11 by minjungk          #+#    #+#              #
#    Updated: 2023/01/11 18:31:32 by minjungk         ###   ########.fr        #
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

exe: $(FDF)
	-export DYLD_LIBRARY_PATH=./external/minilibx; \
	./$(FDF) $(ARGS)

.PHONY: all clean fclean re bonus $(FDF)
