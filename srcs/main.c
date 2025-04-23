/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:12:49 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/23 09:54:18 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"


void	error(void)
{
	ft_putstr_fd("Invalid input\n", 2);
	ft_putstr_fd("Usage : \nmandelbrot\njulia <real> <imaginary>\n", 2);
	exit(1);
}

void	print_error(void)
{
	ft_putstr_fd("Ivalid range\nPlease insert values between -2 and 2\n", 2);
	exit(1);
}

int	main(int ac, char **av)
{
	t_fractal_data	fractal;
	fractal.ac = ac;

	if (ac < 2)
		error();
	if ((!ft_strncmp(av[1], "mandelbrot", 10) && ac == 2) 
		|| (!ft_strncmp(av[1], "julia", 5) && ac == 4) || (!ft_strncmp(av[1], "julia", 5) && ac == 2))
	{
		fractal.name = av[1];
		if (!ft_strncmp(av[1], "julia", 5) && ac == 4)
		{
			if (parsing(av[2]) == -1 || parsing (av[3]) == -1)
				error();
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
			if ((fractal.julia_x > 2 || fractal.julia_x < -2) 
				|| (fractal.julia_y < -2 || fractal.julia_y > 2))
				print_error();
		}
		fractal_init(&fractal);
		render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else 
		error();
	exit(0);
}
