/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delimitcount.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:00:58 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 14:02:51 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_delimitcount(char *str, int a)
{
	int n;

	n = 0;
	while (*str)
	{
		if (*str != (char)a)
			n++;
		while (*str != (char)a)
		{
			str++;
			if (!*str)
				return (n);
		}
		str++;
	}
	return (n);
}
