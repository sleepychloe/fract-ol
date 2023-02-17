/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:53:56 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 18:35:24 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MINX		-2.0
# define MAXX		2.0

# define MINY		-2.0
# define MAXY		2.0

# define WIN_X		1000
# define WIN_Y		1000

# define ITER_MAX	255

# define ESC		0xFF1B
# define SCROLL_UP	4
# define SCROLL_DOWN	5
# define KEY_1		0x31
# define KEY_2		0x32
# define KEY_Q		0x71
# define KEY_W		0x77
# define KEY_C		0x63

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "../mlx_linux/mlx.h"
# include "../libft/incs/libft.h"
# include "../libft/incs/ft_printf.h"

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

/* mandelbrot.c */
int		mandelbrot_set(double c_re, double c_im, t_mlx *mlx);
int		mandelbrot(t_mlx *mlx);
int		window_init_mandelbrot(t_mlx *mlx);
void	draw_mandelbrot(void);

/* julia.c */
int		julia_set(double x, double y, t_mlx *mlx);
int		julia(t_mlx *mlx);
int		window_init_julia(t_mlx *mlx);
void	draw_julia(void);

/* burning_ship.c */
int		burning_ship_set(double c_re, double c_im, t_mlx *mlx);
int		burning_ship(t_mlx *mlx);
int		window_init_burning_ship(t_mlx *mlx);
void	draw_burning_ship(void);

/* fractol_utils.c */
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		keys(int key, t_mlx *mlx);
int		ft_exit(void);
int		zoom(int key, int x, int y, t_mlx *mlx);

/* main.c */
void	show_guide(void);
void	ft_fractol(t_mlx *mlx, int check);
void	available_list(void);
int		main(int argc, char **argv);

#endif
