/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:32:23 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 14:33:46 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** revist this if only to properly learn what its doing
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*d;
	char			*s;
	char			*y;

	d = (char*)dst;
	s = (char*)src;
	i = 0;
	y = 0;
	while (i < n && y == 0)
	{
		d[i] = s[i];
		if (s[i] == ((char)c))
			y = d + i + 1;
		i++;
	}
	return (y);
}
