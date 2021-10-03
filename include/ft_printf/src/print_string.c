/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:44:15 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/06 14:44:15 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	flags_string(int size, t_guide *guide);

void	print_string(va_list args, t_guide *guide)
{
	char	*src;
	int		size;

	src = va_arg(args, char *);
	if (!src)
		src = "(null)";
	size = flags_string(ft_strlen(src), guide);
	if (guide->f_minus == 0)
		while (guide->pspace-- > 0)
			ft_putchar_fd(' ', 1);
	if (guide->f_zero == 1)
		while (guide->pzero-- > 0)
			ft_putchar_fd('0', 1);
	while (size-- > 0)
	{
		ft_putchar_fd(*src, 1);
		src++;
	}
	if (guide->f_minus == 1)
		while (guide->pspace-- > 0)
			ft_putchar_fd(' ', 1);
}

static int	flags_string(int size, t_guide *guide)
{
	if (guide->precision > 0 && guide->precision < size)
		size = guide->precision;
	else if (guide->dot == 1 && guide->precision == 0)
		size = 0;
	if (guide->width > size && guide->f_zero == 1)
		guide->pzero = guide->width - size;
	else
		guide->pzero = 0;
	if (guide->width > size && guide->f_zero == 0)
		guide->pspace = guide->width - size;
	guide->len += size + guide->pzero + guide->pspace;
	return (size);
}
