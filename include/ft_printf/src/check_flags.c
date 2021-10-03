/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 22:17:47 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/02 22:17:47 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	set_minus_zero(const char *text, t_guide *guide);
static int	mini_atoi(const char *text, t_guide *guide);

void	check_flags(const char *text, t_guide *guide)
{
	if (text[guide->i] == '-' || text[guide->i] == '0')
		set_minus_zero(text, guide);
	guide->width = mini_atoi(text, guide);
	if (text[guide->i] == '.')
	{
		guide->dot = 1;
		guide->i++;
		if (ft_isdigit(text[guide->i]) == 1)
			guide->f_zero = 0;
		guide->precision = mini_atoi(text, guide);
	}
}

static void	set_minus_zero(const char *text, t_guide *guide)
{
	while (text[guide->i] == '-' || text[guide->i] == '0')
	{
		if (text[guide->i] == '-')
		{
			guide->f_minus = 1;
			guide->f_zero = 0;
			guide->f_zerop = 0;
		}
		else if (text[guide->i] == '0' && guide->f_minus == 0)
		{
			guide->f_zero = 1;
			guide->f_zerop = 1;
		}
		guide->i++;
	}
}

static int	mini_atoi(const char *text, t_guide *guide)
{
	int	conv;

	conv = 0;
	while (ft_isdigit(text[guide->i]))
	{
		conv = conv * 10 + (text[guide->i] - '0');
		guide->i++;
	}
	return (conv);
}
