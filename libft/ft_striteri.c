/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:17:25 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 21:19:52 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int a;
	unsigned int z;

	if (s == NULL)
		return ;
	if (f == NULL)
		return ;
	z = 0;
	a = ft_strlen(s);
	while (z < a)
	{
		f(z, s);
		s++;
		z++;
	}
}
