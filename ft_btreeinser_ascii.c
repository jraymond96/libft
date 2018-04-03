/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeinser_ascii.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:14:45 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/03 15:21:35 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "/Users/jraymond/ft_ls/ft_ls.h"

t_btree	*ft_btreeinser_ascii(t_btree *root, void *data, size_t size_data)
{
	t_btree	*elem;
	t_btree	*parent;
	int		i;

	if (!(elem = root))
		return (ft_newbtree(data, size_data));
	parent = root;
	while (elem)
	{
		i = ft_strcmp(((t_finfo*)data)->name, ((t_finfo*)elem->ptrdata)->name);
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

/*
**int		ft_compdata(void *data , void *data2, size_t data_size)
**{
**	int	res;
**
**	res = ft_strcmp(data, data2);
**	(void)data_size;
**	return (res);
**}
*/
