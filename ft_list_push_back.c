/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:31:56 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/19 20:22:57 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_b_list *begin_list, void *data)
{
	t_bis_list	*list;

	list = begin_list->first_element;
	if (list)
	{
		while (list && list->next)
			list = list->next;
		list->next = ft_create_elem(data);
	}
	else
		begin_list->first_element = ft_create_elem(data);
}
