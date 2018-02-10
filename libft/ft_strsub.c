/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:43:56 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 16:58:20 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*a;
	int		b;

	if (s == NULL)
		return (NULL);
	b = 0;
	a = malloc(sizeof(char) * (len + 1));
	if (a == NULL)
		return (NULL);
	ft_bzero(a, (len + 1));
	while (len > 0)
	{
		a[b] = s[start];
		len--;
		start++;
		b++;
	}
	return (a);
}
