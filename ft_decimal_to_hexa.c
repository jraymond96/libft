/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:02:13 by jraymond          #+#    #+#             */
/*   Updated: 2020/02/08 13:47:44 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			malloc_size(int *modulos)
{
	int		malloc_size;

	malloc_size = 0;
	while (*modulos)
	{
		malloc_size++;
		modulos++;
	}
	return (malloc_size + 1);
}

void		ft_decimal_to_hexa(long number, char *res)
{
	int		modulos[30];
	int		index;
	int		index_bis;

	index = -1;
	index_bis = -1;
	ft_bzero(modulos, 30);
	if (number <= 0)
		return ;
	while (number)
	{
		modulos[++index] = number % 16;
		number /= 16;
	}
	while (index >= 0)
	{
		if (modulos[index] > 9)
			res[++index_bis] = 55 + modulos[index--];
		else
			res[++index_bis] = modulos[index--] + 48;
	}
	res[++index_bis] = '\0';
}
