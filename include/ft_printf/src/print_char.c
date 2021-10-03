/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:24:08 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/02 21:24:08 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_char(va_list args, t_guide *guide)
{
	char	c;

	c = va_arg(args, int);
	if (guide->width > 1 && guide->f_zero == 1)
		guide->pzero = guide->width - 1;
	else
		guide->pzero = 0;
	if (guide->width > 1 && guide->pzero == 0)
		guide->pspace = guide->width - 1;
	else
		guide->pspace = 0;
	guide->len += guide->pspace + guide->pzero + 1;
	if (guide->f_minus == 0)
		while (guide->pspace-- > 0)
			ft_putchar_fd(' ', 1);
	if (guide->f_zero == 1)
		while (guide->pzero-- > 0)
			ft_putchar_fd('0', 1);
	ft_putchar_fd(c, 1);
	if (guide->f_minus == 1)
		while (guide->pspace-- > 0)
			ft_putchar_fd(' ', 1);
}
