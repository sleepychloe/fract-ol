/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:55:08 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 18:57:03 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	show_guide(void)
{
	ft_printf("╔════════════════════════════════╗\n");
	ft_printf("║       for every fractal        ║\n");
	ft_printf("╠═════════════╦══════════════════╣\n");
	ft_printf("║ SCROLL_UP   ║ zoom out         ║\n");
	ft_printf("║ SCROLL_DOWN ║ zoom in          ║\n");
	ft_printf("║ KEY_ESC     ║ exit             ║\n");
	ft_printf("║ KEY_C       ║ change color     ║\n");
	ft_printf("╠═════════════╩══════════════════╣\n");
	ft_printf("║         for julia set          ║\n");
	ft_printf("╠═════════════╦══════════════════╣\n");
	ft_printf("║ KEY_1       ║ real num: -      ║\n");
	ft_printf("║ KEY_2       ║ real num: +      ║\n");
	ft_printf("║ KEY_Q       ║ imaginary num: - ║\n");
	ft_printf("║ KEY_W       ║ imaginary num: + ║\n");
	ft_printf("╚═════════════╩══════════════════╝\n");
}

void	ft_fractol(t_mlx *mlx, int check)
{
	if (mlx->fractol == 1 || mlx->fractol == 2 || mlx->fractol == 3)
	{
		show_guide();
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
}

void	available_list(void)
{
	ft_printf("╔═════════════════════════════════════════╗\n");
	ft_printf("║           available fractals            ║\n");
	ft_printf("╠═════════════════════════════════════════╣\n");
	ft_printf("║         1. Mandelbrot                   ║\n");
	ft_printf("║         2. Julia                        ║\n");
	ft_printf("║         3. Burning_ship                 ║\n");
	ft_printf("╚═════════════════════════════════════════╝\n");
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		if ((!ft_strncmp(argv[1], "Mandelbrot", 10))
			&& ft_strlen(argv[1]) == 10)
			mlx.fractol = 1;
		else if ((!ft_strncmp(argv[1], "Julia", 5))
			&& ft_strlen(argv[1]) == 5)
			mlx.fractol = 2;
		else if (!(ft_strncmp(argv[1], "Burning_ship", 12))
			&& ft_strlen(argv[1]) == 12)
			mlx.fractol = 3;
		ft_fractol((void *)&mlx, 0);
		available_list();
	}
	else
	{
		ft_printf("%sError: argument error\n", RED);
		ft_printf("(command: ./fractol fractal_name)%s\n", BLACK);
		available_list();
	}
}
