# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 17:30:16 by jaelee            #+#    #+#              #
#    Updated: 2019/08/19 17:07:54 by jaelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_islower.c \
		ft_isprint.c \
		ft_isupper.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_realloc.c \
		ft_swapaddr.c \
		ft_pow.c \
		ft_factorial.c \
		ft_putnbr_base.c \
		ft_strlcpy.c \
		ft_strndup.c \
		ft_min.c \
		ft_max.c \
		get_next_line.c \
		list/list_new.c \
		list/list_delone.c \
		list/list_del.c \
		list/list_add.c \
		list/list_pop.c \
		list/list_iter.c \
		list/list_map.c \
		list/list_search.c \
		list/list_rem.c \
		list/list_append.c \
		list/list_rollback.c \
		list/list_length.c \
		list/list_swap.c \
		array/array_init.c \
		array/array_clear.c \
		array/array_pop_back.c \
		array/array_push_back.c \
		array/array_reserve.c \
		array/array_shrink.c \
		queue/queue_init.c \
		queue/queue_pop.c \
		queue/queue_push.c \
		queue/queue_destroy.c \
		tree/tree_recolor.c \
		tree/tree_insert.c \
		tree/tree_rebalance.c \
		tree/tree_rotation.c \
		tree/tree_util.c \
		tree/tree_restructure.c \
		tree/tree_clear.c \
		tree/tree_search.c \
		tree/tree_pre_traverse.c \
		tree/tree_in_traverse.c \
		tree/tree_post_traverse.c \
		priority_queue/priority_queue.c
OBJS = $(patsubst %.c,obj/%.o,$(SRCS))
CC = gcc
CFLAGS := $(FLAGS) -Wall -Wextra -Werror
INCLUDES = includes/libft.h \
		includes/list.h \
		includes/get_next_line.h \
		includes/array.h \
		includes/queue.h \
		includes/tree.h \
		includes/priority_queue.h
INCLUDE_FOLDERS = -Iincludes/
NAME = libft.a

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^

obj:
	mkdir -p obj
	mkdir -p obj/list
	mkdir -p obj/array
	mkdir -p obj/queue
	mkdir -p obj/tree
	mkdir -p obj/priority_queue

obj/%.o: %.c $(INCLUDES) | obj
	gcc $(CFLAGS) $(INCLUDE_FOLDERS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all
