/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:40:03 by jraymond          #+#    #+#             */
/*   Updated: 2017/11/16 15:45:09 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*curr;

	if (!f || !lst)
		return ;

	curr = lst;
	while (curr)
	{
		f(curr);
		curr = curr->next;
	}
}