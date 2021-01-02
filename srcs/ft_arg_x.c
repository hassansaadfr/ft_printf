/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:42:55 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/01 22:07:42 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arg_x(va_list arg, int is_upper)
{
	long int	argument;
	char		*out;
	char		*base_to;

	if (is_upper)
		base_to = HEXA_UPPER;
	else
		base_to = HEXA_LOWER;
	argument = (long int)va_arg(arg, long int);
	out = ft_convert_hex(argument, base_to);
	ft_putstr(out);
}
