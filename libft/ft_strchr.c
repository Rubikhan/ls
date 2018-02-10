/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:52:54 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 14:53:55 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*z;

	z = (char*)s;
	if (*z == (char)c)
		return (z);
	while (*z)
	{
		z++;
		if (*z == (char)c)
			return (z);
	}
	return (NULL);
}
