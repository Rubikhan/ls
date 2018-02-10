/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:36:14 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 20:09:53 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			a;
	unsigned char	*z1;
	unsigned char	*z2;

	if (n == 0)
		return (0);
	a = 0;
	z1 = (unsigned char*)s1;
	z2 = (unsigned char*)s2;
	while (*z1 == *z2)
	{
		a++;
		if (a == n)
			break ;
		z1++;
		z2++;
	}
	if (*z1 != *z2)
		return (*z1 - *z2);
	else
		return (0);
}
