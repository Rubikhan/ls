/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:34:32 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 14:35:40 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*z;
	size_t	a;

	a = 0;
	z = (char*)s;
	while (a < n)
	{
		if (*z == (char)c)
			return (z);
		z++;
		a++;
	}
	return (NULL);
}
