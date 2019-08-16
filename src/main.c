/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 16:00:23 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/16 18:12:36 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	pixel_in_buffer(unsigned char *buffer, int x, int y, int color)
{
	if (x < WINDOW_X && y < WINDOW_Y)
	{
		buffer[4 * (x + y * WINDOW_X)] = color & 0xFF;
		buffer[4 * (x + y * WINDOW_X) + 1] = color >> 8 & 0xFF;
		buffer[4 * (x + y * WINDOW_X) + 2] = color >> 16 & 0xFF;
	}
}

void reset_buffer(char *buffer)
{
	int i;

	i = -1;
	while (++i < 4 * WINDOW_X * WINDOW_Y)
		buffer[i] = 0;
}

int	pick_color(int iter)
{
	int color;
	int	rgb;

	rgb = iter * 2;
	color = rgb | (rgb << 8) | (rgb << 16);
	return (color);
}

void	fract_size(int key, t_fractal *fr)
{
	if (key == MAIN_PAD_W)
	{
		fr->size_img += 0.004;
		fr->size_real += 0.004;
	}
	else if (key == MAIN_PAD_S)
	{
		fr->size_img -= 0.004;
		fr->size_real -= 0.004;
	}
}

void	press_move(int key, t_fractal *fr)
{
	if (key == ARROW_DOWN)
		fr->y_offset += 0.004;
	else if (key == ARROW_UP)
		fr->y_offset -= 0.004;
	else if (key == ARROW_RIGHT)
		fr->x_offset += 0.004;
	else if (key == ARROW_LEFT)
		fr->x_offset -= 0.004;
}

int		key_press(int key, void *param)
{
	t_fractal *fr;
	fr = param;

	if (key == ARROW_UP || key == ARROW_DOWN ||
		key == ARROW_LEFT || key == ARROW_RIGHT)
		press_move(key, fr);
	else if (key == MAIN_PAD_W || key == MAIN_PAD_S ||
		key == MAIN_PAD_A || key == MAIN_PAD_D)
		fract_size(key, fr);
	else if ( key == ESC)
		exit(0);
	draw(fr);
	return (0);
}

int	initialize(t_fractal *fr)
{
	int	bpp;
	int	s_l;
	int	endian;

	ft_bzero(fr, sizeof(t_fractal));
	fr->x_offset = -1.75;
	fr->y_offset = -0.25;
	fr->size_real = 0.45;
	fr->size_img = 0.25;
	fr->mlx_ptr = mlx_init();
	fr->win_ptr = mlx_new_window(fr->mlx_ptr, WINDOW_X, WINDOW_Y, "fractal");
	fr->img_ptr = mlx_new_image(fr->mlx_ptr, WINDOW_X, WINDOW_Y);
	fr->buffer = mlx_get_data_addr(fr->img_ptr, &bpp, &s_l, &endian);

	return (SUCCESS);
}

void	draw(t_fractal *fr)
{
	double	scale_x;
	double	scale_y;
	double	c_real;
	double	c_img;
	double	z_real;
	double	z_img;
	double	tmp_real;
	int		iter;
	int		color;
	int x;
	int y;
	scale_x = fr->size_real / (double)WINDOW_X;
	scale_y = fr->size_img / (double)WINDOW_Y;
	y = -1;
	reset_buffer(fr->buffer);
	while (++y < WINDOW_Y)
	{
		x = -1;
		while (++x < WINDOW_X)
		{
			c_real = (double)x * scale_x + fr->x_offset;
			c_img = (double)y * scale_y + fr->y_offset;
			z_real = 0.0;
			z_img = 0.0;
			iter  = -1;
			color = 0;
			while (++iter < 100 && (z_real * z_real + z_img * z_img < 4))
			{
				tmp_real = z_real * z_real - z_img * z_img + c_real;
				z_img = 2.0 * z_real * z_img + c_img;
				z_real = tmp_real;
			}
			color = pick_color(iter);
			pixel_in_buffer((unsigned char*)fr->buffer, x, y, color);
		}
	}
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
}

int		main(int argc, char **argv)
{
	t_fractal	fr;
	(void)argc;
	(void)argv;
	initialize(&fr);
	draw(&fr);
	mlx_hook(fr.win_ptr, KEY_PRESS, 0, key_press, &fr);
	mlx_loop(fr.mlx_ptr);
	return (0);
}
