/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:26:21 by smaddux           #+#    #+#             */
/*   Updated: 2018/03/05 17:09:35 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char *s1, char const *s2)
{

	char *new_str;

	new_str = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (new_str);

/* 	char			*a; */
/* 	char			*z; */
/* 	int				b; */
/* 	int				c; */
/* 	int				d; */

/* 	if (s1 == NULL || s2 == NULL) */
/* 		return (NULL); */
/* 	b = ft_strlen(s1); */
/* 	c = ft_strlen(s2); */
/* 	a = ft_strnew(b + c); */
/* 	z = ft_strdup(s1); */
/* 	ft_strdel(&s1); */
/* 	if (a == NULL) */
/* 		return (NULL); */
/* 	d = 0; */
/* 	a = ft_strcpy(a, z); */
/* 	ft_strcpy(&a[b], s2); */
/* 	free(z); */
/* 	return (a); */
}
