/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:19:17 by smaddux           #+#    #+#             */
/*   Updated: 2018/03/05 17:04:51 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	int		b;
	int		c;
	int		d;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	b = ft_strlen(s1);
	c = ft_strlen(s2);
	a = ft_strnew(b + c);
	if (a == NULL)
		return (NULL);
	d = 0;
	a = ft_strcpy(a, s1);
	ft_strcpy(&a[b], s2);
	return (a);
}
