/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:25:09 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/19 16:22:35 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	flags_int(t_guide *guide);
static int	check_sign(t_guide *guide, const char *text);
static void	ct_pdiu(t_guide *guide, char *src);
static void	ct_fdiu(t_guide *guide);

void	print_diu(const char *text, va_list args, t_guide *guide)
{
	char	*src;

	src = NULL;
	if (text[guide->i] == 'd' || text[guide->i] == 'i')
		guide->num = va_arg(args, int);
	else
		guide->unum = va_arg(args, unsigned int);
	if ((guide->num < 0 && text[guide->i] == 'd')
		|| (guide->num < 0 && text[guide->i] == 'i'))
	{
		guide->num = check_sign(guide, text);
		if (guide->width > 0)
			guide->width -= 1;
	}
	if (text[guide->i] == 'd' || text[guide->i] == 'i')
		src = ft_itoa(guide->num);
	if (text[guide->i] == 'u' && guide->unum != 0)
		src = ft_utoa(guide->unum);
	if (guide->unum != 0 || guide->num != 0)
		guide->size = ft_strlen(src);
	ct_pdiu(guide, src);
}

static void	ct_pdiu(t_guide *guide, char *src)
{
	if (guide->size == 0 && guide->dot == 0)
	{
		ft_putchar_fd('0', 1);
		guide->len += 1;
		guide->precision -= 1;
		guide->width -= 1;
	}
	flags_int(guide);
	if (guide->f_minus == 0)
		while (guide->pspace-- > 0)
			ft_putchar_fd(' ', 1);
	if ((guide->f_zero == 1) || (!guide->f_zero)
		|| (guide->precision > guide->size))
	{
		if (guide->sign == 1)
			ft_putchar_fd('-', 1);
		while (guide->pzero-- > 0)
			ft_putchar_fd('0', 1);
		while (guide->size-- > 0)
			write(1, &src[guide->count++], 1);
		if (guide->f_minus == 1)
			while (guide->pspace-- > 0)
				ft_putchar_fd(' ', 1);
	}
	free (src);
}

static void	flags_int(t_guide *guide)
{
	if (guide->precision > guide->size && guide->precision != guide->width)
	{
		if (guide->width > guide->precision && guide->precision > guide->size)
		{
			guide->pzero = guide->precision - guide->size;
			guide->pspace = guide->width - guide->precision;
		}
		else if (guide->width < guide->precision
			&& guide->precision > guide->size)
			guide->pzero = guide->precision - guide->size;
		guide->len += guide->size + guide->pzero + guide->pspace;
		return ;
	}
	if (guide->width > guide->size && guide->size == 0 && guide->precision == 0)
	{
		guide->pspace = guide->width - guide->size;
		guide->len += guide->pspace;
		return ;
	}
	if (guide->width > guide->size && guide->f_zero == 1)
		guide->pzero = guide->width - guide->size;
	ct_fdiu(guide);
}

static void	ct_fdiu(t_guide *guide)
{
	if (guide->width > guide->size && guide->f_zero == 0
		&& guide->width != guide->precision)
	{
		guide->pspace = guide->width - guide->size;
		guide->len += guide->size + guide->pzero + guide->pspace;
		return ;
	}
	guide->len += guide->size + guide->pzero + guide->pspace;
	if (guide->width == guide->precision && guide->width > 0
		&& guide->precision > 0)
	{
		guide->pzero = guide->width - guide->size;
		guide->len += guide->pzero;
		return ;
	}
}

static int	check_sign(t_guide *guide, const char *text)
{
	if (text[guide->i] == 'd' || text[guide->i] == 'i')
	{
		guide->sign = 1;
		guide->len += 1;
		return (guide->num * -1);
	}
	if (text[guide->i] == 'u')
		return (guide->num * -1);
	else
		return (guide->num);
}
