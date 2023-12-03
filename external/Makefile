# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:09:11 by minjungk          #+#    #+#              #
#    Updated: 2023/12/04 07:02:00 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:
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
LIBMLX_DIR	=	minilibx

$(LIBMLX_DIR):
	@if [ $(shell uname) = "Darwin" ]; then \
		ln -sf $(LIBMLX_DIR)-macos $(LIBMLX_DIR); \
	else \
		ln -sf $(LIBMLX_DIR)-linux $(LIBMLX_DIR); \
	fi

libmlx_fix: $(LIBMLX_DIR)
	sed -i 's///g' $(LIBMLX_DIR)/configure
	sed -i'' -r -e "/^CFLAGS\t=/a\CFLAGS+= -Wno-return-type" $(LIBMLX_DIR)/Makefile.mk
	sed -i'' -r -e "/^CFLAGS\t=/a\CFLAGS+= -Wno-parentheses" $(LIBMLX_DIR)/Makefile.mk
	sed -i'' -r -e "/^CFLAGS\t=/a\CFLAGS+= -Wno-pointer-sign" $(LIBMLX_DIR)/Makefile.mk
	sed -i'' -r -e "/^CFLAGS\t=/a\CFLAGS+= -Wno-implicit-function-declaration" $(LIBMLX_DIR)/Makefile.mk
	sed -i'' -r -e "/^CFLAGS=/a\CFLAGS+= -Wno-return-type" $(LIBMLX_DIR)/test/Makefile.mk
	sed -i'' -r -e "/^CFLAGS=/a\CFLAGS+= -Wno-parentheses" $(LIBMLX_DIR)/test/Makefile.mk
	sed -i'' -r -e "/^CFLAGS=/a\CFLAGS+= -Wno-pointer-sign" $(LIBMLX_DIR)/test/Makefile.mk
	sed -i'' -r -e "/^CFLAGS=/a\CFLAGS+= -Wno-implicit-function-declaration" $(LIBMLX_DIR)/test/Makefile.mk

libmlx_all: $(LIBMLX_DIR)
	$(MAKE) -C $(LIBMLX_DIR)

libmlx_clean: $(LIBMLX_DIR)
	$(MAKE) -C $(LIBMLX_DIR) clean
	$(RM) $(LIBMLX_DIR)

.PHONY: $(LIBMLX_DIR) libmlx_fix libmlx_all libmlx_clean

# **************************************************************************** #
