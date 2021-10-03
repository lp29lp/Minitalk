/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coprihx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 00:10:33 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/21 12:55:45 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	coprihx(unsigned int num, const char *text, t_guide *guide)
{
	unsigned int	base;
	char			*info_base;

	base = 16;
	if (text[guide->i] == 'x')
	{
		info_base = "0123456789abcdef";
		if (num / base > 0)
			coprihx(num / base, text, guide);
		ft_putchar_fd(info_base[num % base], 1);
	}
	else
	{
		info_base = "0123456789ABCDEF";
		if (num / base > 0)
			coprihx(num / base, text, guide);
		ft_putchar_fd(info_base[num % base], 1);
	}
}
