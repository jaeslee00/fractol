/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 09:23:23 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/17 15:19:50 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		julia_set(double real, double img, t_complex *c)
{
	t_complex	z;
	t_complex	z2;
	int			iter;

	z.real = real;
	z.img = img;
	z2.real = real * real;
	z2.img = img * img;
	iter = -1;
	while (++iter < MAX_ITER && (z2.real + z2.img < 4))
	{
		z.img = 2.0 * z.real * z.img + c->img;
		z.real = z2.real - z2.img + c->real;
		z2.real = z.real * z.real;
		z2.img = z.img * z.img;
	}
	return (iter);
}

void	julia_draw(t_fractal *fr)
{
	int			color;
	int			x;
	int			y;
	t_complex	c;

	y = -1;
	fr->x_scale = (fr->real_max - fr->real_min) / (double)WIN_WIDTH;
	fr->y_scale = (fr->img_max - fr->img_min) / (double)WIN_HEIGHT;
	reset_buffer(fr->buffer);
	c.img = fr->julia_img;
	c.real = fr->julia_real;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			color = pick_color(julia_set(fr->real_min + x * fr->x_scale,
				fr->img_min + y * fr->y_scale, &c));
			pixel_in_buffer((unsigned char*)fr->buffer, x, y, color);
		}
	}
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
}
