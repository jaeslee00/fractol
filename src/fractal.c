/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 01:37:32 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/17 06:05:41 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_pixel	mandelbrot_set(int x, int y, t_fractal *fr)
{
	double	c_real;
	double	c_img;
	double	z_real;
	double	z_img;
	double	tmp_real;
	double	x_scale;
	double	y_scale;
	int		iter;
	t_pixel	pixel;

	x_scale = (fr->real_max - fr->real_min) / (double)WIN_WIDTH;
	y_scale = (fr->img_max - fr->img_min) / (double)WIN_HEIGHT;
	z_real = (double)x * x_scale * fr->zoom + fr->x_offset;
	z_img = (double)y * y_scale * fr->zoom + fr->y_offset;
	c_real = z_real;
	c_img = z_img;

	iter = -1;
	while (++iter < MAX_ITER && (z_real * z_real + z_img * z_img < 4))
	{
		tmp_real = z_real * z_real - z_img * z_img + c_real;
		z_img = 2.0 * z_real * z_img + c_img;
		z_real = tmp_real;
	}
	pixel.real = z_real;
	pixel.img = z_img;
	pixel.iter = iter;
	return (pixel);
}

t_pixel	julia_set(int x, int y, t_fractal *fr)
{
	double	c_real;
	double	c_img;
	double	z_real;
	double	z_img;
	double	tmp_real;
	double	x_scale;
	double	y_scale;
	int		iter;
	t_pixel	pixel;

	x_scale = (fr->real_max - fr->real_min) / (double)WIN_WIDTH;
	y_scale = (fr->img_max - fr->img_min) / (double)WIN_HEIGHT;
	z_real = (double)x * x_scale * fr->zoom + fr->x_offset;
	z_img = (double)y * y_scale * fr->zoom + fr->y_offset;
	c_real = fr->julia_real;
	c_img = fr->julia_img;

	iter = -1;
	while (++iter < MAX_ITER && (z_real * z_real + z_img * z_img < 16.0))
	{
		tmp_real = z_real * z_real - z_img * z_img + c_real;
		z_img = 2.0 * z_real * z_img + c_img;
		z_real = tmp_real;
	}
	pixel.real = z_real;
	pixel.img = z_img;
	pixel.iter = iter;
	return (pixel);
}
