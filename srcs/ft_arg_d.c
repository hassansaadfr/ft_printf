/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:42:26 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/02 22:41:25 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_treat_s_precision(char *arg, t_precision *lst, size_t star)
{
	size_t	len;
	int		space_nb;

	if ((int)ft_strlen(arg) < lst->after_dot)
		len = ft_strlen(arg);
	else
		len = lst->after_dot;
	if (star != (size_t)-1)
		len = star;
	space_nb = lst->size - len;
	if (lst->align_right == 1)
	{
		ft_print_char('0', star - ft_strlen(arg));
		ft_putstr(arg);
		ft_print_char(' ', space_nb);
	}
	else
	{
		ft_print_char(' ', space_nb);
		ft_part_putstr(arg, len);
	}
}

void	ft_arg_d(va_list arg, t_precision **lst)
{
	char		*argument;

	if (*lst)
	{
		if ((*lst)->star_precision)
			(*lst)->star_precision = (int)va_arg(arg, int);
		argument = ft_itoa((int)va_arg(arg, int));
		ft_treat_s_precision(argument, *lst, (*lst)->star_precision);
		ft_lst_prec_delone(&(*lst));
		// if (!((*lst)->size == 0 && (*lst)->after_dot == 0))
		// {
		// 	argument = ft_itoa((int)va_arg(arg, int));
		// 	ft_putstr(argument);
		// 	free(argument);
		// }
	}
	else
	{
		argument = ft_itoa((int)va_arg(arg, int));
		ft_putstr(argument);
		free(argument);
	}
}
