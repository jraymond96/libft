/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_debil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:25:10 by jraymond          #+#    #+#             */
/*   Updated: 2018/04/23 10:41:26 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_erase(char *str)
{
	ft_memdel((void **)&str);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*lst;
	t_list	*tmp;
	void	*ptr;

	ptr = ft_erase;
	i = 1;
	lst = NULL;
	if (argc < 2)
		return (0);
	while (argv[i])
	{
		ft_lstaddback(&lst, ft_lstnew((char *)argv[i++], sizeof(char *)));
	}
	lst = ft_lst_sort(lst);
	tmp = lst;
	while (lst)
	{
		ft_putstr((char *)lst->content);
		ft_putchar('\n');
		lst = lst->next;
	}
	ft_lstdel(&tmp, ptr);
	return (0);
}
