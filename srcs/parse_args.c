/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:10:12 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/02 22:16:16 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_process_args(const char *s, va_list arg, t_precision *lst)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && i++)
		{
			if (s[i] == '-' || (s[i] >= '0' && s[i] <= '9'))
				ft_treat_precision(&i, s, &lst);
			if (s[i] == 'c' || s[i] == '%')
				ft_arg_c(arg, s[i]);
			else if (s[i] == 's')
				ft_arg_s(arg, &lst);
			else if (s[i] == 'p')
				ft_arg_p(arg);
			else if (s[i] == 'd' || s[i] == 'i' || s[i] == 'u')
				ft_arg_d(arg, &lst);
			else if (s[i] == 'x' || s[i] == 'X')
				ft_arg_x(arg, s[i] == 'X');
			i++;
		}
		ft_putchar(s[i++]);
	}
}
