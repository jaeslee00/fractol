/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 09:06:47 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/17 15:28:15 by jaelee           ###   ########.fr       */
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
	fr->init_fract(fr);
}
