/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 04:04:07 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/13 04:23:51 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_consolidate(long result, int bool)
{
	if (result == -2147483648)
		return (-1);
	if (result < -2147483649)
		return (bool == 1) ? (-1) : (0);
	result = (result * bool);
	return (result);
}

int			ft_atoi(const char *str)
{
	long	result;
	int		bool;

	bool = 1;
	result = 0;
	while (*str != '\0')
	{
		while (ft_isspace((int)*str) == 1)
			str++;
		if (*str == '-')
		{
			str++;
			bool = -1;
		}
		else if (*str == '+')
			str++;
		while (*str >= '0' && *str <= '9')
		{
			result = result * 10;
			result = result + (*str++ - '0');
		}
		if (*str < '0' || *str++ > '9')
			break ;
	}
	return (ft_consolidate(result, bool));
}
