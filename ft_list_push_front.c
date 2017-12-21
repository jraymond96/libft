/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:54:15 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/19 20:22:49 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_b_list **begin_list, void *data)
{
	t_bis_list	*list;

	list = ft_create_elem(data);
	if (list)
	{
		list->next = (*begin_list)->first_element;
		(*begin_list)->first_element = list;
	}
	else
		(*begin_list)->first_element = ft_create_elem(data);
}
