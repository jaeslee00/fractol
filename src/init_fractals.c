/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:53:42 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/17 15:28:18 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_fractal *fr)
{
	fr->real_max = 0.7;
	fr->real_min = -2.3;
	fr->img_max = 1.5;
	fr->img_min = -1.5;
	fr->zoom = 1.0;
}

void	init_julia(t_fractal *fr)
{
	fr->real_max = -1.5;
	fr->real_min = 1.5;
	fr->img_max = 1.5;
	fr->img_min = -1.5;
	fr->zoom = 1.0;
	fr->julia_real = -0.79;
	fr->julia_img = 0.15;
}

void	init_buringship(t_fractal *fr)
{
	fr->real_max = 0.7;
	fr->real_min = -2.3;
	fr->img_max = 1.5;
	fr->img_min = -1.5;
	fr->zoom = 1.0;
}

void	init_mlx(t_fractal *fr, char *argv)
{
	int		bpp;
	int		s_l;
	int		endian;

	fr->mlx_ptr = mlx_init();
	if (!(fr->win_ptr =
		mlx_new_window(fr->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, argv)))
		exit(0);
	if (!(fr->img_ptr = mlx_new_image(fr->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		exit(0);
	if (!(fr->buffer = mlx_get_data_addr(fr->img_ptr, &bpp, &s_l, &endian)))
		exit(0);
}
