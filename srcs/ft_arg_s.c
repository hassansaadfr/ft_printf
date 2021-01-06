/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:42:39 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/06 11:21:58 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print(char *s, int nb_space, size_t after_dot, int align_right)
{
	if (align_right)
	{
		ft_print_char(' ', nb_space);
		ft_part_putstr(s, after_dot);
	}
	else
	{
		ft_print_char(' ', nb_space);
		ft_part_putstr(s, after_dot);
	}
}

static void	ft_treat_s_precision(char *arg, t_prec *lst)
{
	int		nb_space;
	size_t	len;

	len = ft_strlen(arg);
	nb_space = 0;
	if (lst->size != NOT_SET)
	{
		if (lst->after_dot != NOT_SET)
		{
			nb_space -= lst->after_dot;
			if (lst->after_dot < len)
				len = lst->after_dot;
		}
		if (lst->size > len)
			nb_space = lst->size - len;
	}
	ft_print(arg, nb_space, lst->after_dot, lst->align_right == NOT_SET);
}

void		ft_arg_s(va_list arg, t_prec **lst)
{
	char	*argument;

	if (*lst)
	{
		if ((*lst)->star_precision != NOT_SET)
			(*lst)->after_dot = (int)va_arg(arg, int);
		argument = (char*)va_arg(arg, char*);
		if (!argument)
			argument = ft_strdup("(null)");
		ft_treat_s_precision(argument, *lst);
		ft_lst_prec_delone(&(*lst));
	}
	else
	{
		argument = (char*)va_arg(arg, char*);
		if (!argument)
			argument = ft_strdup("(null)");
		ft_putstr(argument);
	}
	free(argument);
}
