/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:05:32 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/03 15:26:23 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreedel(t_btree **root, void (*btdel)(void *))
{
	if (!root || !btdel)
		return ;
	if ((*root)->left)
		ft_btreedel(&(*root)->left, btdel);
	if ((*root)->right)
		ft_btreedel(&(*root)->right, btdel);
	btdel((*root)->ptrdata);
	ft_memdel((void **)root);
}
