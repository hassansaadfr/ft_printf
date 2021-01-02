/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:42:00 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/02 21:21:19 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arg_c(va_list arg, char c)
{
	unsigned char	argument;

	if (c == '%')
		ft_putchar('%');
	else
	{
		argument = (unsigned char)va_arg(arg, int);
		ft_putchar(argument);
	}
}
