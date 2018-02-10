/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:32:52 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/29 23:25:08 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**tbh not sure why its size + 1
**maybe something to do with null terminators of strings?
*/

char	*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}
