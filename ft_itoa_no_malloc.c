/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_no_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:48:31 by jraymond          #+#    #+#             */
/*   Updated: 2020/02/07 17:40:01 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static long		ft_countint(int n)
{
	long	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len++);
}

static int		ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_itoa_nomalloc(long n, char *buf)
{
	long	n_lenght;
	long	len;

	n_lenght = n;
	len = ft_countint(n_lenght);
	if (!buf)
		return (NULL);
	buf[len] = '\0';
	len--;
	if (n_lenght < 0)
		n_lenght = -n_lenght;
	while (len >= 0)
	{
		buf[len] = (n_lenght % 10) + '0';
		len--;
		n_lenght /= 10;
	}
	if (ft_sign(n))
		buf[0] = '-';
	return (buf);
}
