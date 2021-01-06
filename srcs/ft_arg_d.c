/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:42:26 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/06 11:23:33 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_treat_int_prec(char *arg, t_prec *lst)
{
	size_t	zeros;
	size_t	space_nb;

	zeros = 0;
	space_nb = 0;
	if (lst->after_dot != NOT_SET)
		if (lst->after_dot > ft_strlen(arg))
			zeros = lst->after_dot - ft_strlen(arg);
	space_nb = lst->size - (ft_strlen(arg) + zeros);
	if (lst->align_right == NOT_SET)
		ft_print_char(' ', space_nb);
	ft_print_char('0', zeros);
	ft_putstr(arg);
	if (lst->align_right == 1)
		ft_print_char(' ', space_nb);
}

void		ft_arg_d(va_list arg, t_prec **lst)
{
	char		*argument;

	if (*lst)
	{
		if ((*lst)->star_precision != NOT_SET)
			(*lst)->after_dot = (int)va_arg(arg, int);
		argument = ft_itoa((int)va_arg(arg, int));
		ft_treat_int_prec(argument, *lst);
		ft_lst_prec_delone(&(*lst));
	}
	else
	{
		argument = ft_itoa((int)va_arg(arg, int));
		ft_putstr(argument);
	}
	free(argument);
}
