/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 09:06:47 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/19 16:51:18 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractal *fr, double z)
{
	double	new_width;
	double	new_height;
	double	curr_width;
	double	curr_height;

	new_width = (fr->real_max - fr->real_min) * z;
	new_height = (fr->img_max - fr->img_min) * z;
	curr_width = (fr->real_max - fr->real_min);
	curr_height = (fr->img_max - fr->img_min);
	fr->real_min -= 0.5 * (new_width - curr_width);
	fr->img_min -= 0.5 * (new_height - curr_height);
	fr->real_max = fr->real_min + new_width;
	fr->img_max = fr->img_min + new_height;
}

void	move(double x, double y, t_fractal *fr)
{
	double	curr_width;
	double	curr_height;
	double	dx;
	double	dy;

	curr_width = (fr->real_max - fr->real_min);
	curr_height = (fr->img_max - fr->img_min);
	dx = curr_width * x;
	dy = curr_height * y;
	fr->real_min -= dx;
	fr->img_min -= dy;
	fr->real_max -= dx;
	fr->img_max -= dy;
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
	fr->fract_init(fr);
}

int		key_press(int key, void *param)
{
	t_fractal *fr;

	fr = (t_fractal*)param;
	if (key == MAIN_PAD_W)
		move(0.0, 0.1, fr);
	else if (key == MAIN_PAD_S)
		move(0.0, -0.1, fr);
	else if (key == MAIN_PAD_A)
		move(0.1, 0.0, fr);
	else if (key == MAIN_PAD_D)
		move(-0.1, 0.0, fr);
	else if (key == NBR_PAD_PLUS)
		zoom(fr, ZOOM_IN);
	else if (key == NBR_PAD_MINUS)
		zoom(fr, ZOOM_OUT);
	else if (key == SPACE)
		reset(fr);
	else if (key == ESC)
	{
		mlx_destroy_image(fr->mlx_ptr, fr->img_ptr);
		mlx_destroy_window(fr->mlx_ptr, fr->win_ptr);
		exit(0);
	}
	fr->fract_draw(fr);
	return (0);
}
