/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:10:12 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/06 12:38:52 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_errors(t_prec **lst, char flag)
{
	ft_putchar('%');
	if (*lst)
	{
		if ((*lst)->align_right != NOT_SET)
			ft_putchar('-');
		if ((*lst)->size != NOT_SET)
			ft_putstr(ft_itoa((*lst)->size));
		if ((*lst)->after_dot != NOT_SET)
		{
			ft_putchar('.');
			ft_putstr(ft_itoa((*lst)->after_dot));
		}
		if ((*lst)->star_precision != NOT_SET)
		{
			ft_putchar('.');
			ft_putchar('*');
		}
	}
	ft_putchar(flag);
}
#include <stdio.h>
void			ft_process_args(const char *s, va_list arg, t_prec *lst)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && ++i)
		{
			if (s[i] == '-' || (s[i] >= '0' && s[i] <= '9') || s[i] == '.')
				ft_treat_prec(&i, s, &lst);
			if (s[i] == 'c' || s[i] == '%')
				ft_arg_c(arg, s[i], &lst);
			else if (s[i] == 's')
				ft_arg_s(arg, &lst);
			else if (s[i] == 'p')
				ft_arg_p(arg, &lst);
			else if (s[i] == 'd' || s[i] == 'i' || s[i] == 'u')
				ft_arg_d(arg, &lst);
			else if (s[i] == 'x' || s[i] == 'X')
				ft_arg_x(arg, s[i] == 'X', &lst);
			else
				ft_print_errors(&lst, s[i]);
			i++;
		}
		else
			ft_putchar(s[i++]);
	}
}
