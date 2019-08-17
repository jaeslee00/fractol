/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_to_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 09:20:58 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/17 15:10:27 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	pixel_in_buffer(unsigned char *buffer, int x, int y, int color)
{
	buffer[4 * (x + y * WIN_WIDTH)] = color & 0xFF;
	buffer[4 * (x + y * WIN_WIDTH) + 1] = color >> 8 & 0xFF;
	buffer[4 * (x + y * WIN_WIDTH) + 2] = color >> 16 & 0xFF;
}

void	reset_buffer(char *buffer)
{
	int i;

	i = -1;
	while (++i < 4 * WIN_WIDTH * WIN_HEIGHT)
		buffer[i] = 0;
}
