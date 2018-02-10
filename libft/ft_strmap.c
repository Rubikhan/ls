/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:24:52 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 16:52:07 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		a;
	int		b;
	char	*c;

	if (s == NULL)
		return (NULL);
	a = 0;
	b = ft_strlen(s);
	c = malloc(sizeof(char) * (b + 1));
	if (c == NULL)
		return (NULL);
	ft_bzero(c, (b + 1));
	while (s[a])
	{
		c[a] = f(s[a]);
		a++;
	}
	return (c);
}
