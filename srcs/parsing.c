/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:20:19 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/21 10:48:13 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

int	parsing(char *str)
{
	int	i;
	int	count;
	int	sign;

	count = 0;
	sign = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count ++;
		else if (str[i] == '+' || str[i] == '-')
			sign++;
		else if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	if (count > 1 || sign > 1)
		return (-1);
	return (1);
}
