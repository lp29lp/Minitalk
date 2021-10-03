/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_porcent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:05:21 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/18 17:05:21 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_porcent(t_guide *guide)
{
	if (guide->width > 1 && guide->f_zerop)
		guide->pzero = guide->width - 1;
	else
		guide->pzero = 0;
	if (guide->width > 1 && !guide->pzero)
		guide->pspace = guide->width - 1;
	else
		guide->pspace = 0;
	guide->len += guide->pzero + guide->pspace + 1;
	if (!guide->f_minus)
		while (guide->pspace-- > 0)
			ft_putchar_fd(' ', 1);
	if (guide->f_zerop)
		while (guide->pzero-- > 0)
			ft_putchar_fd('0', 1);
	ft_putchar_fd('%', 1);
	if (guide->f_minus)
		while (guide->pzero-- > 0)
			ft_putchar_fd(' ', 1);
}
