/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:20:19 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/21 15:57:27 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_char(char c)
{
	return (ft_isdigit(c) || c == '.' || c == '+' || c == '-');
}

static int	check_dot(char *str, int i, int *dot_count)
{
	if (*dot_count > 0)
		return (-1);
	(*dot_count)++;
	if ((i == 0 || !ft_isdigit(str[i - 1]))
		&& (!str[i + 1] || !ft_isdigit(str[i + 1])))
		return (-1);
	return (0);
}

int	parsing(char *str)
{
	int	i;
	int	dot;

	dot = 0;
	i = 0;
	if (!str || !str[i])
		return (-1);
	while (str[i])
	{
		if (!is_valid_char(str[i]))
			return (-1);
		if ((str[i] == '+' || str[i] == '-'))
		{
			if (i != 0)
				return (-1);
		}
		else if (str[i] == '.')
		{
			if (check_dot(str, i, &dot) == -1)
				return (-1);
		}
		i++;
	}
	return (1);
}
