/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 05:44:37 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/21 11:29:10 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complex	sum(t_complex z, t_complex c)
{
	t_complex	result;

	result.real = z.real + c.real;
	result.i = z.i + c.i;
	return (result);
}

t_complex	square(t_complex z)
{
	t_complex	result;

	result.real = (z.real * z.real) - (z.i * z.i);
	result.i = 2 * z.real * z.i;
	return (result);
}

double	scale(int coordinate, int dimension, double zoom)
{
	return (((coordinate - (dimension / 2.0)) * 4 / (dimension * zoom)));
}
