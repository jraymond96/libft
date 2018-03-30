/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newbtree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:18:10 by jraymond          #+#    #+#             */
/*   Updated: 2018/03/30 19:21:28 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_creat_belem(void)
{
	t_btree	*new;
	size_t	size;

	if (!(new = (t_btree *)malloc((size = sizeof(t_btree)))))
		return (NULL);
	ft_bzero(new, size);
	return (new);
}

t_btree *ft_newbtree(void const *data, size_t size_data)
{
	t_btree	*new;

	if (!(new = ft_creat_belem()))
		return (NULL);
	if (!data || !size_data)
	{
		new->ptrdata = NULL;
		new->data_size = 0;
	}
	else
	{
		if (!(new->ptrdata = (void *)malloc(size_data)))
		{
			ft_memdel((void **)&new);
			return (NULL);
		}
		ft_memmove(new->ptrdata, data, size_data);
		new->data_size = size_data;
	}
	return (new);
}
