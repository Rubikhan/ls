/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:51:03 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 14:52:27 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**idk why, but manipulating a instead of s1 solved all my problems.
**something about pointer arithmetic with a local variable I guess
*/

char	*ft_strcat(char *s1, const char *s2)
{
	char	*a;

	a = s1;
	while (*a != '\0')
		a++;
	while ((*a++ = *s2++))
		;
	return (s1);
}
