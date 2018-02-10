/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:26:05 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 16:53:27 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	a;
	unsigned int	z;
	char			*c;

	if (s == NULL)
		return (NULL);
	z = 0;
	a = ft_strlen(s);
	c = malloc(sizeof(char) * (a + 1));
	if (c == NULL)
		return (NULL);
	ft_bzero(c, (a + 1));
	while (z < a)
	{
		c[z] = f(z, s[z]);
		z++;
	}
	return (c);
}
