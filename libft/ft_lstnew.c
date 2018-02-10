/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:23:20 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 14:25:42 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** passes Alelievr without the free(new)
** passes Alelievr without void cast in ft_memcpy
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *fresh;

	fresh = (t_list *)malloc(sizeof(t_list));
	if (fresh == NULL)
		return (NULL);
	if (content == NULL)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
	}
	else
	{
		fresh->content = malloc(content_size);
		if (fresh->content == NULL)
		{
			free(fresh);
			return (NULL);
		}
		ft_memcpy(fresh->content, (void*)content, content_size);
		fresh->content_size = content_size;
	}
	fresh->next = NULL;
	return (fresh);
}
