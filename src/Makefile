# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 15:26:44 by minjungk          #+#    #+#              #
#    Updated: 2022/12/01 20:42:34 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

CFLAGS		= -Wall -Wextra -Werror -MMD -MP
LDLIBS		= -lm

CPPFLAGS	+= -I../external/minilibx
LDFLAGS		+= -L../external/minilibx
LDLIBS		+= -lmlx 

CPPFLAGS	+= -I../lib/libft
LDFLAGS		+= -L../lib/libft
LDLIBS		+= -lft

ifneq ($(shell uname), Darwin)
	LDLIBS	+= -lXext -lX11 -lbsd
else
	LDFLAGS += -framework OpenGL -framework AppKit
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

exe: $(FDF)
	-export DYLD_LIBRARY_PATH=../external/minilibx; \
	./$(FDF) $(ARGS)
