/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:16:49 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/01 06:03:19 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (x * mlx->bits_per_pixel / 8) + (y * mlx->line_length);
	*(unsigned int *)dst = color;
}

int	keys(int key, t_mlx *mlx)
{
	if (key == ESC)
	{
		exit(0);
		return (0);
	}
	if (key == KEY_C)
		mlx->color += 0x00abc123;
	if (key == KEY_2)
		mlx->julia_x_change += 0.2;
	if (key == KEY_1)
		mlx->julia_x_change -= 0.2;
	if (key == KEY_W)
		mlx->julia_y_change += 0.2;
	if (key == KEY_Q)
		mlx->julia_y_change -= 0.2;
	ft_fractol(mlx, 1);
	return (0);
}

int	ft_exit(void)
{
	exit(1);
	return (0);
}

int	zoom(int key, int x, int y, t_mlx *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->xmax - mlx->xmin) / WIN_X;
	dy = (mlx->ymax - mlx->ymin) / WIN_Y;
	if (key == SCROLL_UP)
	{
		mlx->xmin = (mlx->xmin + (dx * x * 0.5));
		mlx->xmax = (mlx->xmax - (dx * (WIN_X - x) * 0.5));
		mlx->ymin = (mlx->ymin + (dy * (WIN_Y - y) * 0.5));
		mlx->ymax = (mlx->ymax - (dy * y * 0.5));
	}
	if (key == SCROLL_DOWN)
	{
		mlx->xmin = (mlx->xmin - (dx * x * 0.5));
		mlx->xmax = (mlx->xmax + (dx * (WIN_X - x) * 0.5));
		mlx->ymin = (mlx->ymin - (dy * (WIN_Y - y) * 0.5));
		mlx->ymax = (mlx->ymax + (dy * y * 0.5));
	}
	ft_fractol(mlx, 1);
	return (0);
}
