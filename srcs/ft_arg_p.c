/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:43:13 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/06 12:17:32 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_treat_p_precision(char *arg, t_prec *lst)
{
	size_t nb_space;

	nb_space = 0;
	if (lst->size > (int)ft_strlen(arg))
		nb_space = lst->size - (int)ft_strlen(arg);
	if (lst->size != NOT_SET)
	{
		if (lst->align_right == NOT_SET)
		{
			ft_print_char(' ', nb_space);
			ft_putstr("0x");
			ft_print_char('0', lst->after_dot - ft_strlen(arg));
			ft_putstr(arg);
		}
		else
		{
			ft_putstr("0x");
			ft_print_char('0', lst->after_dot - ft_strlen(arg));
			ft_putstr(arg);
			ft_print_char(' ', nb_space);
		}
	}
}

void			ft_arg_p(va_list arg, t_prec **lst)
{
	long int	argument;
	char		*out;
	char		*base_to;
	char		*dest;

	base_to = HEXA_LOWER;
	if (*lst)
	{
		if ((*lst)->star_precision != NOT_SET)
			(*lst)->after_dot = (int)va_arg(arg, int);
		argument = (long int)va_arg(arg, long int);
		out = ft_convert_hex(argument, base_to);
		ft_treat_p_precision(out, *lst);
		ft_lst_prec_delone(&(*lst));
	}
	else
	{
		argument = (long int)va_arg(arg, long int);
		out = ft_convert_hex(argument, base_to);
		dest = ft_strjoin("0x", out);
		ft_putstr(dest);
		free(dest);
	}
	free(out);
}
