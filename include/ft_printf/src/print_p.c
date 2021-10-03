/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:17:02 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/17 20:17:02 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	coprih(unsigned long int num);
static int	flags_p(unsigned long int num, t_guide *guide, int size);
static int	check_size(unsigned long int num);

void	print_p(va_list args, t_guide *guide)
{
	unsigned long int	num;
	int					size;

	num = va_arg(args, unsigned long int);
	size = flags_p(num, guide, check_size(num));
	if (!guide->f_minus)
		while (guide->pspace-- > 0)
			ft_putchar_fd(' ', 1);
	ft_putstr_fd("0x", 1);
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		guide->len += 1;
	}
	while (guide->precision-- > 0)
		ft_putchar_fd('0', 1);
	if (size > 2)
		coprih(num);
	if (guide->f_minus)
		while (guide->pspace-- > 0)
			ft_putchar_fd(' ', 1);
}

static int	flags_p(unsigned long int num, t_guide *guide, int size)
{
	if (guide->precision > size)
		guide->precision = guide->precision - size;
	else
		guide->precision = 0;
	if (!num && !guide->dot && !guide->precision)
		size = 2;
	else
		size += 2;
	if (guide->width > size)
	{
		if (size > 2)
			guide->pspace = guide->width - size ;
		else
			guide->pspace = guide->width - size - 1;
	}
	guide->len += guide->pspace + size + guide->precision;
	return (size);
}

static void	coprih(unsigned long int num)
{
	size_t	base;
	char	*info_base;

	base = 16;
	info_base = "0123456789abcdef";
	if (num / base > 0)
		coprih(num / base);
	ft_putchar_fd(info_base[num % base], 1);
}

static int	check_size(unsigned long int num)
{
	unsigned long int	size;

	size = 0;
	if (num == 1)
		return (1);
	while (num >= 1)
	{
		num /= 16;
		size++;
	}
	return (size);
}
