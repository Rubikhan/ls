/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:23:20 by smaddux           #+#    #+#             */
/*   Updated: 2018/02/27 15:01:16 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


t_curr	*ft_mlstnew(char *content)
{
	t_curr *fresh;

	fresh = (t_curr *)malloc(sizeof(t_curr));
	if (fresh == NULL)
		return (NULL);
	if (content == NULL)
	{
		fresh->mname = NULL;
	}
	else
	{
		fresh->mname = malloc(sizeof(char) * ft_strlen(content));
		if (fresh->mname == NULL)
		{
			free(fresh);
			return (NULL);
		}
		fresh->mname = ft_strcpy(fresh->mname, content);
	}
	fresh->next = NULL;
	return (fresh);
}
