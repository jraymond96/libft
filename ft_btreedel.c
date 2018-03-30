/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:05:32 by jraymond          #+#    #+#             */
/*   Updated: 2018/03/30 19:22:46 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	btdel(void *elem)
{
	ft_memdel((void **)&((t_finfo *)elem)->name);
	ft_memdel((void **)&((t_finfo *)elem)->n_id_user);
	ft_memdel((void **)&((t_finfo *)elem)->n_id_group);
	ft_memdel(&elem);
}

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
