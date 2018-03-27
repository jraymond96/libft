/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_debil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:25:10 by jraymond          #+#    #+#             */
/*   Updated: 2018/03/27 18:19:44 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*lst;

	i = 1;
	lst = NULL;
	if (argc < 2)
		return (0);
	while (argv[i])
	{
		ft_lstaddback(&lst, ft_lstnew((char *)argv[i++], sizeof(char *)));
	}
	while (lst)
	{
		ft_putstr((char *)lst->content);
		ft_putchar('\n');
		lst = lst->next;
	}
	return (0);
}
