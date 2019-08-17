/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 16:00:52 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/17 15:17:40 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdint.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# define WIN_WIDTH			500
# define WIN_HEIGHT			500
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
# define MOUSE_PRESS		5
# define MOUSE_MOVE			6
# define ZOOM				1.1
# define MAX_ITER			100
# define MOUSE_ON			1
# define MOUSE_OFF			0

typedef struct	s_pixel
{
	double real;
	double img;
	int		iter;
}				t_pixel;

typedef struct	s_complex
{
	double	real;
	double	img;
}				t_complex;

typedef struct	s_fractal	t_fractal;
typedef void	(*fractal_set)(t_fractal*);
typedef void	(*fractal_init)(t_fractal*);

typedef struct	s_fractal
{
	int		color;

	void	*mlx_ptr;
	void	*img_ptr;
	void	*win_ptr;
	char	*buffer;

	double	x_scale;
	double	y_scale;

	double	real_max;
	double	real_min;
	double	img_max;
	double	img_min;

	double	julia_real;
	double	julia_img;

	double	zoom;

	int		mouse_x;
	int		mouse_y;
	int		prev_mouse_x;
	int		prev_mouse_y;

	fractal_set		fract;
	fractal_init 	init_fract;
}					t_fractal;

void	pixel_in_buffer(unsigned char *buffer, int x, int y, int color);
void	reset_buffer(char *buffer);
int		pick_color(int iter);

void	get_fractal(t_fractal *fr, char *argv);
void	init_mandelbrot(t_fractal *fr);
void	init_julia(t_fractal *fr);
void	init_buringship(t_fractal *fr);
void	init_mlx(t_fractal *fr, char *argv);

void	mandelbrot_draw(t_fractal *fr);
int		mandelbrot_set(t_complex *c);

void	julia_draw(t_fractal *fr);
int		julia_set(double real, double img, t_complex *c);

void	burningship_draw(t_fractal *fr);
int		burningship_set(t_complex *c);

int		key_press(int key, void *param);
void	zoom(t_fractal *fr, double z);
void	move(double x, double y, t_fractal *fr);
void	transform_julia(int key, t_fractal *fr);
void	reset(t_fractal *fr);

int		mouse_press(int button, void *param);
int		mouse_release(int button, void *param);
int		mouse_move(int x,int y, void *param);
#endif
