/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:53:56 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/02 16:09:59 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MINX		-2.0
# define MAXX		2.0
# define MINY		-2.0
# define MAXY		2.0
# define WIN_X		1200
# define WIN_Y		1200
# define ITER_MAX	255
# define ESC		53
# define SCROLL_UP	4
# define SCROLL_DOWN	5
# define KEY_1		18
# define KEY_2		19
# define KEY_Q		12
# define KEY_W		13
# define KEY_C		8
# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	void	*img_ptr;
	char	*addr;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	int		count_x;
	int		count_y;
	double	julia_x_change;
	double	julia_y_change;
	int		color;
	int		fractol;
}	t_mlx;

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		keys(int key, t_mlx *mlx);
int		ft_exit(void);
int		zoom(int key, int x, int y, t_mlx *mlx);
int		mandelbrot_set(double c_re, double c_im, t_mlx *mlx);
int		mandelbrot(t_mlx *mlx);
int		window_init_mandelbrot(t_mlx *mlx);
void	draw_mandelbrot(void);
int		julia_set(double x, double y, t_mlx *mlx);
int		julia(t_mlx *mlx);
int		window_init_julia(t_mlx *mlx);
void	draw_julia(void);
int		burning_ship_set(double c_re, double c_im, t_mlx *mlx);
int		burning_ship(t_mlx *mlx);
int		window_init_burning_ship(t_mlx *mlx);
void	draw_burning_ship(void);
void	ft_fractol(t_mlx *mlx, int check);
int		ft_strcmp(char *s1, char *s2);
void	available_list(void);
int		main(int argc, char **argv);
#endif
