/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 16:00:23 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/19 16:42:57 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		pick_color(int iter)
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

void	get_fractal(t_fractal *fr, char *argv)
{
	if (!ft_strcmp(argv, "mandelbrot"))
	{
		fr->fract_draw = mandelbrot_draw;
		fr->fract_init = init_mandelbrot;
	}
	else if (!ft_strcmp(argv, "julia"))
	{
		(fr->fract_draw) = julia_draw;
		fr->fract_init = init_julia;
	}
	else if (!ft_strcmp(argv, "burningship"))
	{
		fr->fract_draw = burningship_draw;
		fr->fract_init = init_buringship;
	}
	else
	{
		ft_putendl("usage : ./fractol [fractal_name]");
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	t_fractal	fr;

	ft_bzero(&fr, sizeof(t_fractal));
	if (argc == 2)
	{
		get_fractal(&fr, argv[1]);
		init_mlx(&fr, argv[1]);
		fr.fract_init(&fr);
		fr.fract_draw(&fr);
		mlx_hook(fr.win_ptr, KEY_PRESS, 0, key_press, &fr);
		mlx_hook(fr.win_ptr, MOUSE_PRESS, 0, mouse_press, &fr);
		mlx_hook(fr.win_ptr, MOUSE_MOVE, 0, mouse_move, &fr);
		mlx_loop(fr.mlx_ptr);
	}
	else
		ft_putendl("usage : ./fractol [fractal_name]");
	return (0);
}
