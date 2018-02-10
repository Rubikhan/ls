/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:20:49 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/13 02:37:34 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** revisit lines 27 and 29
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int a;
	int s_size;
	int d_size;
	int space;

	s_size = ft_strlen(src);
	d_size = 0;
	space = size;
	while (dst[d_size] != '\0' && space-- != 0)
		d_size++;
	space = size - d_size;
	if (space == 0)
		return ((size_t)(size + s_size));
	a = d_size;
	while (*src != '\0' && space-- > 1)
		dst[a++] = *src++;
	dst[a] = '\0';
	return ((size_t)(s_size + d_size));
}
