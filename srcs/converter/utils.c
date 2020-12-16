/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:08:37 by hsaadaou          #+#    #+#             */
/*   Updated: 2020/12/16 20:25:40 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*get_pointer_address(void *var)
{
	char	*address;
	char	*dec_base;
	char	*hexa_base;

	dec_base = "0123456789";
	hexa_base = "0123456789abcdef";

	address = ft_convert_base(ft_itoa((long int)(&(*var))), dec_base, hexa_base);
	return (ft_strjoin("0x10", address));
}
