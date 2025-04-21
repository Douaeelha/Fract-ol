/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 06:04:50 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/21 09:06:24 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	data_init(t_fractal_data *fractal)
{
	fractal->escape_value = 4;
	fractal->max_iteration = 42;
	fractal->zoom = 1.0;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
}

void	event_init(t_fractal_data *fractal)
{
	mlx_hook(fractal->mlx_window, 2, 0, key_hook, fractal);
	mlx_hook(fractal->mlx_window, 4, 0, mouse_handle, fractal);
	mlx_hook(fractal->mlx_window, 17, 0, destroy_handle, fractal);
	mlx_hook(fractal->mlx_window, 6, 0, track_julia, fractal);
}

void	fractal_init(t_fractal_data *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		exit(1);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (!fractal->mlx_window)
	{
		free(fractal->mlx_connection);
		exit(1);
	}
	fractal->img.image = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (!fractal->img.image)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		exit(1);
	}
	fractal->img.pixel = mlx_get_data_addr(fractal->img.image,
			&fractal->img.bit_per_pixel,
			&fractal->img.len,
			&fractal->img.endian);
	data_init(fractal);
	event_init(fractal);
}
