/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:55:08 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/01 02:06:42 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractol(t_mlx *mlx, int check)
{
	if (mlx->fractol == 1)
	{
		if (check)
			mandelbrot(mlx);
		else
			draw_mandelbrot();
	}
	if (mlx->fractol == 2)
	{
		if (check)
			julia(mlx);
		else
			draw_julia();
	}
	if (mlx->fractol == 3)
	{
		if (check)
			burning_ship(mlx);
		else
			draw_burning_ship();
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s2[i] && s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	available_list(void)
{
	write(1, "********************************************\n", 45);
	write(1, "--------------------------------------------\n", 45);
	write(1, "--- command : ./fractol <avaliable name> ---\n", 45);
	write(1, "--------------------------------------------\n", 45);
	write(1, "********************************************\n", 45);
	write(1, "**********< available fractals> ************\n", 45);
	write(1, "********************************************\n", 45);
	write(1, "--------------------------------------------\n", 45);
	write(1, "-----------1.Mandelbrot---------------------\n", 45);
	write(1, "-----------2.Julia--------------------------\n", 45);
	write(1, "-----------3.Burning_ship-------------------\n", 45);
	write(1, "--------------------------------------------\n", 45);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "Mandelbrot")
			|| !ft_strcmp(argv[1], "mandelbrot"))
			mlx.fractol = 1;
		else if (!ft_strcmp(argv[1], "Julia")
			|| !ft_strcmp(argv[1], "julia"))
			mlx.fractol = 2;
		else if (!ft_strcmp(argv[1], "Burning_ship")
			|| !ft_strcmp(argv[1], "burning_ship"))
			mlx.fractol = 3;
		ft_fractol((void *)&mlx, 0);
		write(1, "********************************************\n", 45);
		write(1, "** please type the avaliable fractal name **\n", 45);
		available_list();
	}
	else
	{
		write(1, "********************************************\n", 45);
		write(1, "************* invalid argument *************\n", 45);
		available_list();
	}
}
