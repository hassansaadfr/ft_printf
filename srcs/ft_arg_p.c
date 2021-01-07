/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:43:13 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/07 02:19:24 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_precision(int zeros, int spaces, char *arg, int right)
{
	if (!right)
	{
		ft_print_char(' ', spaces);
		ft_putstr("0x");
		ft_print_char('0', zeros);
		ft_putstr(arg);
	}
	else
	{
		ft_putstr("0x");
		ft_print_char('0', zeros);
		ft_putstr(arg);
		ft_print_char(' ', spaces);
	}
}

static void		ft_treat_p_precision(char *arg, t_prec *lst, int *size)
{
	int	space;
	int	zeros;

	space = 0;
	zeros = 0;
	if (lst->size > (int)ft_strlen(arg))
		space = lst->size - ft_strlen(arg);
	if (lst->size != NOT_SET)
	{
		zeros = lst->after_dot - ft_strlen(arg);
		ft_print_precision(zeros, space, arg, lst->align_right == NOT_SET);
	}
	*size += space + zeros;
}

void			ft_arg_p(va_list arg, t_prec **lst, int *size)
{
	long int	argument;
	char		*out;
	char		*dest;

	if (*lst)
	{
		argument = (long int)va_arg(arg, long int);
		out = ft_convert_hex(argument, HEXA_LOWER);
		ft_treat_p_precision(out, *lst, size);
		ft_lst_prec_delone(&(*lst));
	}
	else
	{
		argument = (long int)va_arg(arg, long int);
		out = ft_convert_hex(argument, HEXA_LOWER);
		dest = ft_strjoin("0x", out);
		ft_putstr(dest);
		*size += ft_strlen(dest);
		free(dest);
	}
	free(out);
}
