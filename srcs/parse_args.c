/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:10:12 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/07 21:42:32 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_errors(t_prec **lst, const char *s, int end, int *size)
{
	int i;

	i = end;
	while (s[i] != '%')
		i--;
	ft_part_putstr(s + i, (end - i) + 1);
	*size += end - i + 1;
	if (*lst)
		ft_lst_prec_delone(&(*lst));
}

void		ft_treat(char s, va_list arg, t_prec **lst, int *size)
{
	if (s == 'c' || s == '%')
		ft_arg_c(arg, s, &(*lst), size);
	else if (s == 's')
		ft_arg_s(arg, &(*lst), size);
	else if (s == 'p')
		ft_arg_p(arg, &(*lst), size);
	else if (s == 'd' || s == 'i' || s == 'u')
		ft_arg_d(arg, &(*lst), size);
	else if (s == 'x' || s == 'X')
		ft_arg_x(arg, s == 'X', &(*lst), size);
	else
		ft_print_errors(&(*lst), s, i, size);
}

void		ft_process_args(const char *s, va_list arg, t_prec *lst, int *size)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && ++i && s[i])
		{
			if (ft_strchr("-.*0123456789", s[i]))
				ft_treat_prec(arg, &i, s, &lst);
			ft_treat(s + i, arg, &lst, size);
			i++;
		}
		else
		{
			ft_putchar(s[i++]);
			(*size)++;
		}
	}
}
