/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:28:53 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/13 02:30:49 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t a;

	if (n == 0)
		return (0);
	a = 0;
	while (*s1 == *s2 && (*s1 != '\0' || *s2 != '\0'))
	{
		a++;
		if (a == n)
			break ;
		s1++;
		s2++;
	}
	if (*s1 != *s2)
	{
		return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	else
		return (0);
}
