/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem2join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:46:40 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/25 18:53:28 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mem2join(char *dest, char *s1, char *s2, size_t size)
{
	if (size == 0 || !s1 || !s2)
		return;
	ft_strcpy(dest, s1);
	dest += ft_strlen(dest);
	while (size-- && *s2)
	{
		*dest = *s2;
		dest++;
		s2++;
	}
	*s1 = '\0';
}
