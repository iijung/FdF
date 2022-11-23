# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 15:26:44 by minjungk          #+#    #+#              #
#    Updated: 2022/11/23 16:55:27 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

CFLAGS		= -Wall -Wextra -Werror -MMD -MP
LDLIBS		= -lXext -lX11 -lm

CPPFLAGS	+= -I../external/minilibx-linux
LDFLAGS		+= -L../external/minilibx-linux
LDLIBS		+= -lmlx 

CPPFLAGS	+= -I../lib/libft
LDFLAGS		+= -L../lib/libft
LDLIBS		+= -lft

ifneq ($(shell uname), Darwin)
	LDLIBS	+= -lbsd
endif

# **************************************************************************** #
FDF			= fdf
FDF_SRCS	= \
	fdf.c \

FDF_OBJS	= $(FDF_SRCS:%.c=%.o)
FDF_DEPS	= $(FDF_SRCS:%.c=%.d)
-include $(FDF_DEPS)

$(FDF): $(FDF_OBJS)
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@
# **************************************************************************** #

all: $(FDF)

clean:
	$(RM) $(FDF_OBJS) $(FDF_DEPS)

fclean: clean
	$(RM) $(FDF)

re: clean
	$(MAKE) all
