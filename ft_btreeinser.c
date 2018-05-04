/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeinser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:22:55 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/04 19:05:00 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreeinser(t_btree *root, void *data, size_t size_data,
	   					int (comp)(void *, void*))
{	
	t_btree	*elem;
	t_btree	*parent;
	int		i;

	if (!(elem = root))
		return (ft_newbtree(data, size_data));
	parent = root;
	while (elem)
	{
		i = comp(data, elem->ptrdata);
		elem = (i < 0) ? (t_btree *)elem->left : (t_btree *)elem->right;
		if (!elem)
		{
			elem = parent;
			break;
		}
		parent = elem;
	}
	if (i < 0)
		elem->left = (struct s_btree *)ft_newbtree(data, size_data);
	else
		elem->right = (struct s_btree *)ft_newbtree(data, size_data);
	elem->parent = (struct s_btree *)parent;
	return (root);
}
