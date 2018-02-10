/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:57:52 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/29 23:26:36 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupf(char *s1)
{
	int		a;
	char	*b;

	a = ft_strlen(s1);
	b = malloc(sizeof(char) * (a + 1));
	if (b == NULL)
		return (NULL);
	b = ft_strcpy(b, s1);
	free(s1);
	return (b);
}
