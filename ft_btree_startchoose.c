/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_startchoose.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 02:37:23 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/19 00:55:18 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "/Users/jraymond/ft_ls/ft_ls.h"

t_btree	*ft_found_place(t_btree *elem, void *data, int *i, t_btree *parent)
{
	while (elem)
	{
		parent = elem;
		*i = ft_strcmp((char *)data, elem->ptrdata);
		elem = (*i < 0) ? (t_btree *)elem->left : (t_btree *)elem->right;
	}
	elem = parent;
	return (elem);
}

void ft_left(t_btree *elem, void *data, size_t size_data, int *i)
{
	t_btree	*parent;
	
	parent = elem;
	if (!elem->left)
		elem->left = (struct s_btree *)ft_newbtree(data, size_data);
	else
	{
		if (!(elem = elem->left))
			elem = parent;
		else
			elem = ft_found_place(elem, data, i, parent);
		if (*i < 0)
			elem->left = (struct s_btree *)ft_newbtree(data, size_data);
		else
			elem->right = (struct s_btree *)ft_newbtree(data, size_data);
		elem->parent = (struct s_btree *)parent;
	}
}

void ft_right(t_btree *elem, void *data, size_t size_data, int *i)
{
	t_btree	*parent;
	
	parent = elem;
	if (!elem->right)
		elem->right = (struct s_btree *)ft_newbtree(data, size_data);
	else
	{
		if (!(elem = elem->right))
			elem = parent;
		else
			elem = ft_found_place(elem, data, i, parent);
		if (*i < 0)
			elem->left = (struct s_btree *)ft_newbtree(data, size_data);
		else
			elem->right = (struct s_btree *)ft_newbtree(data, size_data);
		elem->parent = (struct s_btree *)parent;
	}
}

t_btree	*ft_btree_start(t_btree *root, void *data, size_t size_data, int branch)
{
	t_btree	*elem;
	int		i;

	i = 0;
	if (!root)
	{
		elem = ft_newbtree(NULL, 0);
		root = elem;
	}
	else
		elem = root;
	if (branch == 0)
		ft_left(elem, data, size_data, &i);
	else
		ft_right(elem, data, size_data, &i);
	return (root);
}
