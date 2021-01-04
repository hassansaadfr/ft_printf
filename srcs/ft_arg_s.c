/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:42:39 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/04 15:06:52 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_treat_s_precision(char *arg, t_precision *lst, size_t star)
{
	size_t	len;
	int		space_nb;

	if (ft_strlen(arg) < lst->after_dot)
		len = ft_strlen(arg);
	else
		len = lst->after_dot;
	if (star != (size_t)-1)
		len = star;
	space_nb = lst->size - len;
	if (lst->align_right == 1)
	{
		ft_part_putstr(arg, len);
		while (space_nb && space_nb--)
			ft_putchar(' ');
	}
	else
	{
		while (space_nb && space_nb--)
			ft_putchar(' ');
		ft_part_putstr(arg, len);
	}
}

void	ft_arg_s(va_list arg, t_precision **lst)
{
	char	*argument;

	if (*lst)
	{
		if ((*lst)->star_precision)
			(*lst)->star_precision = (int)va_arg(arg, int);
		argument = (char*)va_arg(arg, char*);
		ft_treat_s_precision(argument, *lst, (*lst)->star_precision);
		ft_lst_prec_delone(&(*lst));
	}
	else
		ft_putstr(argument);
}
