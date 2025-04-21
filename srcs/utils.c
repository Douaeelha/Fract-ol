/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 04:47:25 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/21 10:21:16 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

double	atodbl(char *s)
{
	long	int_part;
	double	fraction_part;
	double	power;
	int		sign;

	int_part = 0;
	fraction_part = 0;
	sign = +1;
	power = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;

			
	while (*s != '.' && *s)
		int_part = (int_part * 10) + (*s++ - 48);
	if ('.' == *s)
		s++;
	while (*s)
	{
		power /= 10;
		fraction_part = fraction_part + (*s++ - 48) * power;
	}
	return ((int_part + fraction_part) * sign);
}
