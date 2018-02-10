/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:38:03 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 14:38:55 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*a;
	char		*b;

	a = src;
	b = dst;
	while (n > 0)
	{
		n--;
		*b = *a;
		b++;
		a++;
	}
	return (dst);
}
