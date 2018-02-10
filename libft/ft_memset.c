/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:44:14 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 14:45:11 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*z;
	size_t			a;
	unsigned char	k;

	k = c;
	a = 0;
	z = b;
	while (a != len)
	{
		z[a] = k;
		a++;
	}
	return (z);
}
