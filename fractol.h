/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 06:04:58 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/21 10:44:08 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdbool.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

# define COLOR_BLACK   0x000000
# define COLOR_CYAN    0x00FFFF

typedef struct complex 
{
	double	real;
	double	i;
}	t_complex;

typedef struct image
{
	void	*image;
	char	*pixel;
	int		bit_per_pixel;
	int		endian;
	int		len;
}	t_img_data;

typedef struct fractal
{
	void		*mlx_connection;
	void		*mlx_window;
	t_img_data	img;
	char		*name;
	double		escape_value;
	int			max_iteration;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
}	t_fractal_data;

int			destroy_handle(t_fractal_data *fractal);
int			key_hook(int keycode, t_fractal_data *fractal);
int			mouse_handle(int mousecode, int x, int y, t_fractal_data *fractal);
void		data_init(t_fractal_data *fractal);
void		event_init(t_fractal_data *fractal);
void		fractal_init(t_fractal_data *fractal);
int			main(int ac, char **av);
void		error(void);
t_complex	sum(t_complex z, t_complex c);
t_complex	square(t_complex z);
void		my_pixel_put(int x, int y, t_img_data *img, int color);
void		handle_coordinates(int x, int y, t_fractal_data *fractal);
void		render(t_fractal_data *fractal);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, unsigned int n);
double		atodbl(char *s);
int			track_julia(int x, int y, t_fractal_data *fractal);
void		init_set(t_complex *c, t_complex *z, t_fractal_data *fractal);
void		print_error(void);
int			ft_isdigit(int c);
int			parsing(char *str);

#endif