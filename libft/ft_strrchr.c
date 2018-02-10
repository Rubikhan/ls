/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:35:46 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/13 02:38:30 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	a;
	size_t	b;
	char	*z;
	char	*y;
	int		bool;

	bool = 0;
	a = ft_strlen(s);
	b = 0;
	z = (char*)s;
	while (b <= a)
	{
		if (*z == (char)c)
		{
			bool = 1;
			y = z;
		}
		z++;
		b++;
	}
	if (bool == 1)
		return (y);
	return (NULL);
}
