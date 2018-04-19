/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 23:52:01 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/19 00:09:44 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	min_max : -1 for get max value and 1 for get min vale of binary tree
*/

#include "libft.h"

t_btree	*ft_btreeend(t_btree *root, int min_max)
{
	if (min_max == -1)
	{
		while (root->left)
			root = root->left;
	}
	else
	{
		while (root->right)
			root = root->right;
	}
	return (root);
}
