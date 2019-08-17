/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 16:00:23 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/17 13:44:38 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	pick_color(int iter)
{
	int color;
	int	rgb;

	rgb = iter * 2;
	if (iter % 2 == 0)
		color = rgb | (rgb << 8) | (rgb << 16);
	else
		color = rgb | (rgb << 8);
	return (color);
}

int		key_press(int key, void *param)
{
	t_fractal *fr;
	fr = param;

	if (key == ARROW_UP)
		move(0.0, 0.1, fr);
	else if (key == ARROW_DOWN)
		move(0.0, -0.1, fr);
	else if (key == ARROW_LEFT)
		move(0.1, 0.0, fr);
	else if (key == ARROW_RIGHT)
		move(-0.1, 0.0, fr);
	else if (key == MAIN_PAD_W)
		zoom(fr, 0.90909090909);
	else if (key == MAIN_PAD_S)
		zoom(fr, 1.1);
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
	ft_bzero(fr, sizeof(t_fractal));
	fr->real_max = 1.0;
	fr->real_min = -2.5;
	fr->img_max = 1.0;
	fr->img_min = -1.0;
	fr->zoom = 1.0;
	fr->julia_real = -0.79;
	fr->julia_img = 0.15;

	return (SUCCESS);
}

void	get_fractal(t_fractal *fr, char *argv)
{
	int	bpp;
	int	s_l;
	int	endian;

	if (!ft_strcmp(argv, "mandelbrot"))
		fr->fract = mandelbrot_draw;
	else if (!ft_strcmp(argv, "julia"))
		(fr->fract) = julia_draw;
	else if (!ft_strcmp(argv, "burningshit"))
		fr->fract = burningshit_draw;
	else
		exit(0);
	fr->mlx_ptr = mlx_init();
	fr->win_ptr = mlx_new_window(fr->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, argv);
	fr->img_ptr = mlx_new_image(fr->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	fr->buffer = mlx_get_data_addr(fr->img_ptr, &bpp, &s_l, &endian);
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
		mlx_hook(fr.win_ptr, MOUSE_MOVE, 0, mouse_move, &fr);
		mlx_loop(fr.mlx_ptr);
	}
	return (0);
}
