/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:11:51 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/13 03:54:28 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_intache(void)
{
	char	*a;

	a = ft_strnew(12);
	a = ft_strcpy(a, "-2147483648");
	return (a);
}

char		*ft_itoa(int n)
{
	int		b;
	char	*a;

	b = 0;
	if (n == -2147483648)
		return (ft_intache());
	if (n < 0)
	{
		n = n * -1;
		b++;
	}
	b = (b + (int)ft_intlen(n));
	if (!(a = ft_strnew(b--)))
		return (NULL);
	while (n > 9)
	{
		a[b--] = ((n % 10) + '0');
		n = (n / 10);
	}
	a[b] = (n + '0');
	if (b-- == 1)
		a[b] = '-';
	return (a);
}
