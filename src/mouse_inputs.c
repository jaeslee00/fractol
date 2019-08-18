/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 09:34:13 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/18 11:38:49 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_press(int button, int x, int y, void *param)
{
	t_fractal *fr;

	(void)x;
	(void)y;
	fr = (t_fractal*)param;
	if (button == SCROLL_UP)
		zoom(fr, ZOOM_IN);
	else if (button == SCROLL_DOWN)
		zoom(fr, ZOOM_OUT);
	fr->fract(fr);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_fractal *fr;

	fr = (t_fractal*)param;
	fr->julia_real = (((double)x) / (double)WIN_WIDTH) * 0.5 - 0.5;
	fr->julia_img = (((double)y) / (double)WIN_HEIGHT) * 0.5 - 0.5;
	fr->fract(fr);
	return (0);
}
