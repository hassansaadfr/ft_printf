/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:10:12 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/06 14:09:11 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_errors(t_prec **lst, const char *s, int end)
{
	int i;

	i = end;
	while (s[i] != '%')
		i--;
	ft_part_putstr(s + i, (end - i) + 1);
	if (*lst)
		ft_lst_prec_delone(&(*lst));
}

// void static		ft_treat(const char *s, va_list arg, t_prec *lst, int i)
// {
// 	if (s[i] == 'c' || s[i] == '%')
// 	{
// 		ft_arg_c(arg, s[i], &lst);
// 	}
// 	else if (s[i] == 's')
// 		ft_arg_s(arg, &lst);
// 	else if (s[i] == 'p')
// 		ft_arg_p(arg, &lst);
// 	else if (s[i] == 'd' || s[i] == 'i' || s[i] == 'u')
// 		ft_arg_d(arg, &lst);
// 	else if (s[i] == 'x' || s[i] == 'X')
// 		ft_arg_x(arg, s[i] == 'X', &lst);
// 	else
// 		ft_print_errors(&lst, s, i);
// }

void			ft_process_args(const char *s, va_list arg, t_prec *lst)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && ++i)
		{
			if (ft_strchr("-.*0123456789", s[i]))
				ft_treat_prec(arg, &i, s, &lst);
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
				ft_print_errors(&lst, s, i);
			i++;
		}
		else
			ft_putchar(s[i++]);
	}
}
