/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:43:13 by hsaadaou          #+#    #+#             */
/*   Updated: 2020/12/28 13:46:00 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arg_p(va_list arg)
{
	long int	argument;
	char		*out;
	char		*base_to;

	base_to = HEXA_LOWER;
	argument = (long int)va_arg(arg, long int);
	out = ft_convert_hex(argument, base_to);
	ft_putstr("0x");
	ft_putstr(out);
}
