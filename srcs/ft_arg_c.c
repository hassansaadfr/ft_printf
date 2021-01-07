/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:42:00 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/07 02:14:40 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_treat_char_precision(char arg, t_prec *lst, int *size)
{
	if (lst->size != NOT_SET)
	{
		if (lst->align_right == NOT_SET)
		{
			ft_print_char(' ', lst->size - 1);
			ft_putchar(arg);
		}
		else
		{
			ft_putchar(arg);
			ft_print_char(' ', lst->size);
		}
		*size += lst->size + 1;
	}
}

void		ft_arg_c(va_list arg, char c, t_prec **lst, int *size)
{
	unsigned char	argument;

	if (c == '%')
	{
		ft_putchar('%');
		if (*lst)
			ft_lst_prec_delone(&(*lst));
	}
	else
	{
		if (*lst)
		{
			argument = (unsigned char)va_arg(arg, int);
			ft_treat_char_precision(argument, *lst, size);
			ft_lst_prec_delone(&(*lst));
		}
		else
		{
			argument = (unsigned char)va_arg(arg, int);
			ft_putchar(argument);
			*size += 1;
		}
	}
}
