/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 03:45:07 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/23 09:56:13 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_pixel_put(int x, int y, t_img_data *img, int color)
{
	int		offset;
	char	*buffer;

	offset = (y * img->len) + (x * (img->bit_per_pixel / 8));
	buffer = img->pixel + offset;
	*(unsigned int *)buffer = color;
}

void	init_set(t_complex *c, t_complex *z, t_fractal_data *fractal, int ac)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		if (ac == 2)
		{
			c->real = 0.4;
			c->i = -0.6;
		}
		c->real = fractal->julia_x;
		c->i = fractal->julia_y;
	}
	else
	{
		c->real = z->real;
		c->i = z->i;
		z->i = 0;
		z->real = 0;
	}
}

void	handle_coordinates(int x, int y, t_fractal_data *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.real = scale(x, WIDTH, fractal->zoom) + fractal->shift_x;
	z.i = scale(y, HEIGHT, fractal->zoom) + fractal->shift_y;
	init_set(&c, &z, fractal, fractal->ac);
	i = 0;
	while (i < fractal->max_iteration)
	{
		z = sum(square(z), c);
		if ((z.real * z.real + z.i * z.i) > fractal->escape_value)
		{
			color = COLOR_BLACK + (i * 10);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, COLOR_CYAN);
}

void	render(t_fractal_data *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_coordinates(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, 
		fractal->mlx_window, 
		fractal->img.image, 
		0, 0);
}
