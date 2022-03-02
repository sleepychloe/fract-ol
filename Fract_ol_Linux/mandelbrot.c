/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:03:51 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/01 01:43:07 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_set(double c_re, double c_im, t_mlx *mlx)
{
	int		iter;
	double	x;
	double	y;
	double	temp;

	x = 0;
	y = 0;
	iter = 1;
	while (iter < ITER_MAX)
	{
		temp = x;
		x = x * x - y * y + c_re;
		y = (2 * temp * y) + c_im;
		if (x * x + y * y > 4)
		{
			my_mlx_pixel_put(mlx, mlx->count_x, mlx->count_y,
				(mlx->color) + 0x00110011 * iter);
			return (0);
		}
		iter++;
	}
	my_mlx_pixel_put(mlx, mlx->count_x, mlx->count_y, 0x00000000);
	return (0);
}

int	mandelbrot(t_mlx *mlx)
{
	double	c_re;
	double	c_im;

	mlx->count_x = 0;
	mlx->count_y = 0;
	mlx_clear_window(mlx->mlx_ptr, mlx->win);
	while (mlx->count_y < WIN_Y)
	{
		while (mlx->count_x < WIN_X)
		{
			c_re = mlx->xmin + (mlx->count_x * (mlx->xmax - mlx->xmin)
					/ WIN_X);
			c_im = mlx->ymax - (mlx->count_y * (mlx->ymax - mlx->ymin)
					/ WIN_Y);
			mandelbrot_set(c_re, c_im, mlx);
			mlx->count_x++;
		}
		mlx->count_y++;
		mlx->count_x = 0;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img_ptr, 0, 0);
	return (1);
}

int	window_init_mandelbrot(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_X, WIN_Y, "Mandelbrot");
	if (!mlx->win)
		return (0);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_X, WIN_Y);
	if (!mlx->img_ptr)
		return (0);
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	if (!mlx->addr)
		return (0);
	return (1);
}

void	draw_mandelbrot(void)
{
	t_mlx	mlx;

	mlx.xmin = MINX;
	mlx.xmax = MAXX;
	mlx.ymin = MINY;
	mlx.ymax = MAXY;
	if (!window_init_mandelbrot(&mlx))
		return ;
	mlx.color = 0;
	mlx.fractol = 1;
	mandelbrot((void *)&mlx);
	mlx_hook(mlx.win, 17, 2, ft_exit, (void *)0);
	mlx_key_hook(mlx.win, keys, (void *)&mlx);
	mlx_mouse_hook(mlx.win, zoom, (void *)&mlx);
	mlx_loop(mlx.mlx_ptr);
}
