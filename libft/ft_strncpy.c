/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:29:52 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/13 02:35:31 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** the ( len - 1 ) is crucial in both places
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*save;
	size_t	a;
	size_t	b;

	if (len == 0)
		return (dst);
	b = ft_strlen(src);
	a = 0;
	save = dst;
	while (((*save++ = *src++) && a < (len - 1)))
		a++;
	while (b++ < (len - 1))
		*save++ = '\0';
	return (dst);
}
