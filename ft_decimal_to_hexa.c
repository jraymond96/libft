/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:02:13 by jraymond          #+#    #+#             */
/*   Updated: 2020/01/23 19:22:08 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			malloc_size(int	*modulos)
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

char		*ft_decimal_to_hexa(long number)
{
	int		modulos[30];
	int		index;
	int		index_bis;
//	char	*result;
	char	result[30];

	index = -1;
	index_bis = -1;
	ft_bzero(modulos, 30);
	ft_bzero(result, 30);
	if (number <= 0)
	{
		ft_putstr("decimal to hexa NULL\n");
		return ("0");
	}
	while (number)
	{
		modulos[++index] = number % 16;
		number /= 16;
	}

/*	if (!(result = malloc(malloc_size(modulos))))
		return (NULL);
		*/
	while (index >= 0)
	{
		if (modulos[index] > 9)
			result[++index_bis] = 55 + modulos[index--];
		else
			result[++index_bis] = modulos[index--] + 48;
	}
	result[++index_bis] = '\0';
	ft_putstr(result);

//	return (result);
	return (NULL);
}
