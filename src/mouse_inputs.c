/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 09:34:13 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/19 16:19:27 by jaelee           ###   ########.fr       */
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
	fr->fract_draw(fr);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_fractal *fr;

	fr = (t_fractal*)param;
	fr->julia_real = 2.0 * (((double)x) / (double)WIN_WIDTH) - 1.0;
	fr->julia_img = 2.0 * (((double)y) / (double)WIN_HEIGHT) - 1.0;
	fr->fract_draw(fr);
	return (0);
}
