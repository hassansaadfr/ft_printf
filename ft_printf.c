/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:36:46 by hsaadaou          #+#    #+#             */
/*   Updated: 2020/12/29 17:53:24 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


int		ft_printf(const char *str, ...)
{
	va_list		arg_list;

	va_start(arg_list, str);
	ft_process_args(str, arg_list, NULL);
	return (1);
}
