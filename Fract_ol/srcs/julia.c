/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 05:25:36 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/01 06:12:38 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	julia_set(double x, double y, t_mlx *mlx)
{
	int		iter;
	double	c_re;
	double	c_im;
	double	temp;

	c_re = x;
	c_im = y;
	iter = 1;
	while (iter < ITER_MAX)
	{
		temp = c_re;
		c_re = (c_re * c_re - c_im * c_im) - 0.444 + mlx->julia_x_change;
		c_im = (2 * temp * c_im) - 0.666 + mlx->julia_y_change;
		if (c_re * c_re + c_im * c_im > 4)
		{
			my_mlx_pixel_put(mlx, mlx->count_x, mlx->count_y,
				(mlx->color) + 0x00001111 * iter);
			return (0);
		}
		iter++;
	}
	my_mlx_pixel_put(mlx, mlx->count_x, mlx->count_y, 0x00000000);
	return (0);
}

int	julia(t_mlx *mlx)
{
	double	x;
	double	y;

	mlx->count_x = 0;
	mlx->count_y = 0;
	mlx_clear_window(mlx->mlx_ptr, mlx->win);
	while (mlx->count_y < WIN_Y)
	{
		while (mlx->count_x < WIN_X)
		{
			x = mlx->xmin + (mlx->count_x * (mlx->xmax - mlx->xmin)
					/ WIN_X);
			y = mlx->ymax - (mlx->count_y * (mlx->ymax - mlx->ymin)
					/ WIN_Y);
			julia_set(x, y, mlx);
			mlx->count_x++;
		}
		mlx->count_y++;
		mlx->count_x = 0;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img_ptr, 0, 0);
	return (1);
}

int	window_init_julia(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_X, WIN_Y, "Julia");
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

void	draw_julia(void)
{
	t_mlx	mlx;

	mlx.xmin = MINX;
	mlx.xmax = MAXX;
	mlx.ymin = MINY;
	mlx.ymax = MAXY;
	mlx.julia_x_change = 0;
	mlx.julia_y_change = 0;
	if (!window_init_julia(&mlx))
		return ;
	mlx.color = 0;
	mlx.fractol = 2;
	julia((void *)&mlx);
	mlx_hook(mlx.win, 17, 2, ft_exit, (void *)0);
	mlx_key_hook(mlx.win, keys, (void *)&mlx);
	mlx_mouse_hook(mlx.win, zoom, (void *)&mlx);
	mlx_loop(mlx.mlx_ptr);
}
