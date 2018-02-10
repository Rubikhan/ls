/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 05:38:41 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/13 05:48:31 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse_string(char *a)
{
	int b;

	if (a == NULL)
		return ;
	b = ft_strlen(a);
	while (--b >= 0)
		ft_putchar(a[b]);
	write(1, "\n", 1);
}
