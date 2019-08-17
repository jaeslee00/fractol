/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 09:34:13 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/17 15:11:14 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		mouse_press(int button, void *param)
{
	(void)button;
	(void)param;
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_fractal *fr;

	fr = (t_fractal*)param;
	fr->julia_real = ((double)x) / (double)WIN_WIDTH - 0.5;
	fr->julia_img = ((double)y) / (double)WIN_HEIGHT - 0.5;
	fr->fract(fr);
	return (0);
}
