/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:30:11 by hsaadaou          #+#    #+#             */
/*   Updated: 2020/12/16 16:25:03 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double	ft_atod(char *str)
{
	double	res;
	double	rest;
	int		nbzeros;

	nbzeros = 0;
	rest = 0;
	res = ft_atoi(str);
	while (*str != '.')
		str++;
	if (*str++ == '.')
	{
		while (*str == '0')
		{
			nbzeros++;
			str++;
		}
		while (*str >= '0' && *str <= '9')
			rest = rest * 10 + *str++ - '0';
		while (rest > 1)
			rest = rest / 10;
		while (nbzeros--)
			rest = rest / 10;
		return (res < 0 ? (rest - res) * -1 : (rest + res));
	}
	return (res);
}
