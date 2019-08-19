NAME = fractol

SRCS =	main.c \
		key_inputs.c \
		mouse_inputs.c \
		draw_to_buffer.c \
		init_fractals.c \
		fractal/mandelbrot.c \
		fractal/julia.c \
		fractal/burning_ship.c

OBJS = $(patsubst %.c, obj/%.o, $(SRCS))

INCLUDES = ./includes/fractol.h \
		 ./libft/includes/libft.h

INCLUDE_PATH = -I ./includes -I ./libft/includes -I /Users/jaeslee/Downloads/minilibx_macos

LIBFT =	libft/libft.a

HEADER_MLX = -I /usr/local/include/

LIB_MLX = -L /usr/local/lib/

MLX = -lmlx -framework OpenGL -framework AppKit

CC = gcc

CFLAGS := $(FLAGS) -Wall -Wextra -Werror

.PHONY : all, re, clean, flcean

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(OBJS) -o $(NAME) $(LIBFT) $(LIB_MLX) $(MLX)

obj:
	mkdir -p obj
	mkdir -p obj/fractal

obj/%.o: src/%.c $(LIBFT) $(INCLUDES) | obj
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_PATH) $(HEADER_MLX)


$(LIBFT):
	make -C ./libft/

clean:
	rm -rf obj
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/

re: fclean all

