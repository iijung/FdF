# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:09:11 by minjungk          #+#    #+#              #
#    Updated: 2022/11/23 16:52:37 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

re:
	$(MAKE) clean
	$(MAKE) all 

fix:
	$(MAKE) libmlx_fix

all bonus:
	$(MAKE) libmlx_all

clean fclean:
	$(MAKE) libmlx_clean

.PHONY: all clean fclean re bonus fix

# **************************************************************************** #
LIBMLX		=	minilibx-linux/libmlx.a
LIBMLX_DIR	=	$(dir $(LIBMLX))
$(LIBMLX):

libmlx_fix:
	sed -i "/env/d" $(LIBMLX_DIR)configure
	sed -i'' -r -e "/^CFLAGS\t=/a\CFLAGS+= -Wno-return-type" $(LIBMLX_DIR)Makefile.mk
	sed -i'' -r -e "/^CFLAGS\t=/a\CFLAGS+= -Wno-parentheses" $(LIBMLX_DIR)Makefile.mk
	sed -i'' -r -e "/^CFLAGS\t=/a\CFLAGS+= -Wno-pointer-sign" $(LIBMLX_DIR)Makefile.mk
	sed -i'' -r -e "/^CFLAGS\t=/a\CFLAGS+= -Wno-implicit-function-declaration" $(LIBMLX_DIR)Makefile.mk
	sed -i'' -r -e "/^CFLAGS=/a\CFLAGS+= -Wno-return-type" $(LIBMLX_DIR)test/Makefile.mk
	sed -i'' -r -e "/^CFLAGS=/a\CFLAGS+= -Wno-parentheses" $(LIBMLX_DIR)test/Makefile.mk
	sed -i'' -r -e "/^CFLAGS=/a\CFLAGS+= -Wno-pointer-sign" $(LIBMLX_DIR)test/Makefile.mk
	sed -i'' -r -e "/^CFLAGS=/a\CFLAGS+= -Wno-implicit-function-declaration" $(LIBMLX_DIR)test/Makefile.mk

libmlx_all:
	$(MAKE) -C $(LIBMLX_DIR)

libmlx_clean:
	$(MAKE) -C $(LIBMLX_DIR) clean

.PHONY: libmlx_fix libmlx_all libmlx_clean

# **************************************************************************** #
