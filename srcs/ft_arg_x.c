/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:42:55 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/11 23:04:24 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_treat_x_precision(char *arg, t_prec *lst, int *size)
{
	size_t	zeros;
	size_t	space_nb;

	zeros = 0;
	space_nb = 0;
	if (lst->after_dot != NOT_SET)
		if (lst->after_dot > (int)ft_strlen(arg))
			zeros = lst->after_dot - ft_strlen(arg);
	space_nb = lst->size - ((int)ft_strlen(arg) + zeros);
	if (lst->align_right == NOT_SET)
	{
		if (lst->sub != NOT_SET)
			ft_print_char('0', space_nb);
		else
			ft_print_char(' ', space_nb);
	}
	ft_print_char('0', zeros);
	ft_putstr(arg);
	*size += space_nb + zeros + ft_strlen(arg);
	if (lst->align_right == 1)
		ft_print_char(' ', space_nb);
}

void		ft_arg_x(va_list arg, int is_upper, t_prec **lst, int *size)
{
	long		argument;
	char		*out;
	char		*base_to;

	if (is_upper)
		base_to = HEXA_UPPER;
	else
		base_to = HEXA_LOWER;
	if (*lst)
	{
		argument = (unsigned int)va_arg(arg, unsigned int);
		out = ft_convert_hex(argument, base_to);
		ft_treat_x_precision(out, *lst, size);
		ft_lst_prec_delone(&(*lst));
	}
	else
	{
		argument = (unsigned int)va_arg(arg, unsigned int);
		out = ft_convert_hex(argument, base_to);
		ft_putstr(out);
		*size += ft_strlen(out);
	}
	free(out);
}
