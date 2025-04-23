/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 07:11:03 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/23 09:57:45 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	destroy_handle(t_fractal_data *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.image);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	exit(0);
}

int	key_hook(int keycode, t_fractal_data *fractal)
{
	if (keycode == 53)
		destroy_handle(fractal);
	else if (keycode == 124)
		fractal->shift_x = fractal->shift_x + (0.1 * fractal->zoom);
	else if (keycode == 123)
		fractal->shift_x = fractal->shift_x - (0.1 * fractal->zoom);
	else if (keycode == 126)
		fractal->shift_y = fractal->shift_y - (0.1 * fractal->zoom);
	else if (keycode == 125)
		fractal->shift_y = fractal->shift_y + (0.1 * fractal->zoom);
	else if (keycode == 69)
		fractal->max_iteration = fractal->max_iteration + 10;
	else if (keycode == 78)
		fractal->max_iteration = fractal->max_iteration - 10;
	render(fractal);
	return (0);
}

int	mouse_handle(int mousecode, int x, int y, t_fractal_data *fractal)
{
	(void)x;
	(void)y;
	if (mousecode == 5)
		fractal->zoom *= 0.95;
	else if (mousecode == 4)
		fractal->zoom *= 1.05;
	render(fractal);
	return (0);
}
int	track_julia(int x, int y, t_fractal_data *fractal)
{
	double	scale_x;
	double	scale_y;
	if (!ft_strncmp(fractal->name, "julia", 5) && fractal->ac == 2)
	{
		scale_x = ((x - (WIDTH / 2.0)) * 4.0 / (WIDTH * fractal->zoom));
		scale_y = ((y - (HEIGHT / 2.0)) * 4.0 / (HEIGHT * fractal->zoom));
		fractal->julia_x = scale_x + fractal->shift_x;
		fractal->julia_y = scale_y + fractal->shift_y;
		render(fractal);
	}
	return (0);
}
