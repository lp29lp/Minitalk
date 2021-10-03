/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 02:10:18 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/21 12:55:23 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_nbsize(long n)
{
	int		size;

	size = 1;
	while (n / 10)
	{
		n = n / 10;
		size++;
	}
	if (n < 0)
		size++;
	return (size);
}

static long	ft_getunit(long n, int unit)
{
	while (unit--)
		n = n / 10;
	return (n % 10);
}

char	*ft_utoa(unsigned int n)
{
	char	*rst;
	int		i;
	int		j;

	i = 0;
	j = ft_nbsize(n);
	rst = (char *)malloc(sizeof(char) * (j + 1));
	if (!rst)
		return (NULL);
	if (n == 0)
		return (NULL);
	if (rst)
	{
		while (j - i)
		{
			rst[i] = '0' + ft_getunit(n, j - i - 1);
			i++;
		}
		rst[i] = '\0';
	}
	return (rst);
}
