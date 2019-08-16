/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 16:00:52 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/16 17:53:53 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdint.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# define WINDOW_X 900
# define WINDOW_Y 600
# define SUCCESS 1
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define MAIN_PAD_W			13
# define MAIN_PAD_S			1
# define MAIN_PAD_A			0
# define MAIN_PAD_D			2
# define ESC				53
# define KEY_PRESS			2
typedef struct	s_fractal
{
	int		color;
	void	*mlx_ptr;
	void	*img_ptr;
	void	*win_ptr;
	char	*buffer;
	double	x_offset;
	double	y_offset;
	double	size_real;
	double	size_img;
}				t_fractal;

void	draw(t_fractal *fr);

#endif
