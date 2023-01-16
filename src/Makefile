# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 15:26:44 by minjungk          #+#    #+#              #
#    Updated: 2023/01/11 18:30:29 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

CFLAGS		= -Wall -Wextra -Werror -MMD -MP -O3 -ffast-math
CPPFLAGS	= -I. -Iutil -Imap -Ievent
LDLIBS		= -lm

CPPFLAGS	+= -I../external/minilibx
LDFLAGS		+= -L../external/minilibx
LDLIBS		+= -lmlx 

CPPFLAGS	+= -I../lib/libft
LDFLAGS		+= -L../lib/libft
LDLIBS		+= -lft

ifneq ($(shell uname), Darwin)
	CPPFLAGS	+= -D__LINUX__
	LDLIBS		+= -lXext -lX11 -lbsd
else
	LDFLAGS 	+= -framework OpenGL -framework AppKit
endif

ifdef	DEBUG
	CPPFLAGS	+= -DDEBUG -g -O0
endif

# **************************************************************************** #
FDF			= fdf
FDF_SRCS	= \
	util/ft_except.c \
	util/ft_debug.c \
	map/parse_file.c \
	map/map.c \
	event/event.c \
	event/key_hook.c \
	event/mouse_hook.c \
	draw/draw.c \
	draw/image.c \
	draw/guide.c \
	fdf.c \

FDF_OBJS	= $(FDF_SRCS:%.c=%.o)
FDF_DEPS	= $(FDF_SRCS:%.c=%.d)
-include $(FDF_DEPS)

../$(FDF):
	ln -sf $(CURDIR)/$(FDF) ../$(FDF)

$(FDF): $(FDF_OBJS) | ../$(FDF)
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

# **************************************************************************** #

all: $(FDF)

bonus: $(FDF)

clean:
	$(RM) $(FDF_OBJS) $(FDF_DEPS)

fclean: clean
	$(RM) ../$(FDF)
	$(RM) $(FDF)

re: clean
	$(MAKE) all

exe: $(FDF)
	-export DYLD_LIBRARY_PATH=../external/minilibx; \
	./$(FDF) $(ARGS)
