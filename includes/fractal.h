/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 16:00:52 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/17 05:40:07 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdint.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# define WIN_WIDTH			1200
# define WIN_WIDTH_MID		600
# define WIN_HEIGHT			900
# define WIN_HEIGHT_MID		450
# define SUCCESS			1
# define FAIL				0
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define MAIN_PAD_W			13
# define MAIN_PAD_S			1
# define MAIN_PAD_A			0
# define MAIN_PAD_D			2
# define MAIN_PAD_Q			12
# define MAIN_PAD_E			14
# define SPACE				49
# define ESC				53
# define KEY_PRESS			2
# define ZOOM				1.1
# define MAX_ITER			100

typedef struct	s_pixel
{
	double real;
	double img;
	int		iter;
}				t_pixel;

typedef struct	s_fractal	t_fractal;
typedef void	(*fractal_set)(t_fractal*);

struct	s_fractal
{
	int		color;
	void	*mlx_ptr;
	void	*img_ptr;
	void	*win_ptr;
	char	*buffer;
	double	x_offset;
	double	y_offset;
	double	real_max;
	double	real_min;
	double	img_max;
	double	img_min;
	double	julia_real;
	double	julia_img;
	double	zoom;
	fractal_set	fract;
};

void	julia_draw(t_fractal *fr);
void	mandelbrot_draw(t_fractal *fr);
t_pixel	mandelbrot_set(int x, int y, t_fractal *fr);
t_pixel	julia_set(int x, int y, t_fractal *fr);

#endif
