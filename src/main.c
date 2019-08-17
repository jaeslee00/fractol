/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 16:00:23 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/17 06:16:09 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	pixel_in_buffer(unsigned char *buffer, int x, int y, int color)
{

	buffer[4 * (x + y * WIN_WIDTH)] = color & 0xFF;
	buffer[4 * (x + y * WIN_WIDTH) + 1] = color >> 8 & 0xFF;
	buffer[4 * (x + y * WIN_WIDTH) + 2] = color >> 16 & 0xFF;

}

void reset_buffer(char *buffer)
{
	int i;

	i = -1;
	while (++i < 4 * WIN_WIDTH * WIN_HEIGHT)
		buffer[i] = 0;
}

int	pick_color(int iter)
{
	int color;
	int	rgb;

	rgb = iter * 2;
	//smooth_iter = iter - log2(log2(pixel->real + pixel->img)) + 4.0;
	if (iter % 2 == 0)
		color = rgb | (rgb << 8) | (rgb << 16);
	else
		color = rgb | (rgb << 8);
	return (color);
}

void	zoom(t_fractal *fr, double z)
{
	double	new_width;
	double	new_height;
	double	curr_width;
	double	curr_height;

	new_width = (fr->real_max - fr->real_min) * fr->zoom * z;
	new_height = (fr->img_max - fr->img_min) * fr->zoom * z;
	curr_width = (fr->real_max - fr->real_min) * fr->zoom;
	curr_height = (fr->img_max - fr->img_min) * fr->zoom;
	fr->x_offset -= 0.5 * (new_width - curr_width);
	fr->y_offset -= 0.5 * (new_height - curr_height);
	fr->zoom *= z;
}

void	press_move(int key, t_fractal *fr)
{
	if (key == ARROW_DOWN)
		fr->y_offset -= fr->zoom * 0.1;
	else if (key == ARROW_UP)
		fr->y_offset += fr->zoom * 0.1;
	else if (key == ARROW_RIGHT)
		fr->x_offset -= fr->zoom * 0.1;
	else if (key == ARROW_LEFT)
		fr->x_offset += fr->zoom * 0.1;
}

void	transform_julia(int key, t_fractal *fr)
{
	if (key == MAIN_PAD_E)
	{
		fr->julia_real += 0.01;
		fr->julia_img += 0.01;
	}
	else if (key == MAIN_PAD_Q)
	{
		fr->julia_real -= 0.01;
		fr->julia_img -= 0.01;
	}
}

void	reset(t_fractal *fr)
{
	fr->x_offset = -2.5;
	fr->y_offset = -1.0;
	fr->real_max = 1.0;
	fr->real_min = -2.0;
	fr->img_max = 1.0;
	fr->img_min = -1.0;
	fr->zoom = 1.0;
	fr->julia_real = -0.79;
	fr->julia_img = 0.15;
}

int		key_press(int key, void *param)
{
	t_fractal *fr;
	fr = param;

	if (key == ARROW_UP || key == ARROW_DOWN ||
		key == ARROW_LEFT || key == ARROW_RIGHT)
		press_move(key, fr);
	else if (key == MAIN_PAD_W)
		zoom(fr, 1 / ZOOM);
	else if (key == MAIN_PAD_S)
		zoom(fr, ZOOM);
	else if (key == MAIN_PAD_Q || key == MAIN_PAD_E)
		transform_julia(key, fr);
	else if (key == SPACE)
		reset(fr);
	else if (key == ESC)
		exit(0);
	fr->fract(fr);
	return (0);
}

int	initialize(t_fractal *fr)
{
	int	bpp;
	int	s_l;
	int	endian;

	ft_bzero(fr, sizeof(t_fractal));
	fr->x_offset = -2.5;
	fr->y_offset = -1.0;
	fr->real_max = 1.0;
	fr->real_min = -2.0;
	fr->img_max = 1.0;
	fr->img_min = -1.0;
	fr->zoom = 1.0;
	fr->julia_real = -0.79;
	fr->julia_img = 0.15;
	fr->mlx_ptr = mlx_init();
	fr->win_ptr = mlx_new_window(fr->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fractal");
	fr->img_ptr = mlx_new_image(fr->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	fr->buffer = mlx_get_data_addr(fr->img_ptr, &bpp, &s_l, &endian);

	return (SUCCESS);
}

void	mandelbrot_draw(t_fractal *fr)
{
	int		color;
	int x;
	int y;
	t_pixel	pixel;

	y = -1;
	reset_buffer(fr->buffer);
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			pixel = mandelbrot_set(x, y, fr);
			color = pick_color(pixel.iter);
			pixel_in_buffer((unsigned char*)fr->buffer, x, y, color);
		}
	}
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
}

void	julia_draw(t_fractal *fr)
{
	int		color;
	int x;
	int y;
	t_pixel	pixel;
	y = -1;
	reset_buffer(fr->buffer);
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			pixel = julia_set(x, y, fr);
			color = pick_color(pixel.iter);
			pixel_in_buffer((unsigned char*)fr->buffer, x, y, color);
		}
	}
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
}

void	get_fractal(t_fractal *fr, const char *argv)
{
	if (!ft_strcmp(argv, "mandelbrot"))
		fr->fract = mandelbrot_draw;
	else if (!ft_strcmp(argv, "julia"))
		(fr->fract) = julia_draw;
	else
		exit(0);
}

int		main(int argc, char **argv)
{
	t_fractal	fr;

	if (argc == 2)
	{
		initialize(&fr);
		get_fractal(&fr, argv[1]);
		fr.fract(&fr);
		mlx_hook(fr.win_ptr, KEY_PRESS, 0, key_press, &fr);
		mlx_loop(fr.mlx_ptr);
	}
	return (0);
}
