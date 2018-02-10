/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:34:30 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/13 03:23:33 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t a;
	size_t b;

	a = 0;
	b = ft_strlen(little);
	if (*little == '\0')
		return ((char*)big);
	if (b == len)
		return (ft_strncmp(big, little, b) == 0) ? (char*)big : NULL;
	while (*big != '\0' && (a < len))
	{
		if (ft_strncmp(big, little, b) == 0)
		{
			if (len - a >= b)
				return ((char*)big);
			else
				return (NULL);
		}
		a++;
		big++;
	}
	return (NULL);
}
