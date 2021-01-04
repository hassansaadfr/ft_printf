/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:08:37 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/04 16:55:43 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_convert_hex(long int var, char *base_to)
{
	char	*address;
	char	*dec;

	dec = "0123456789";
	address = ft_convert_base(ft_itoa(var), dec, base_to);
	return (address);
}

void	ft_part_putstr(const char *s, size_t len)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (*s && i < len)
	{
		write(1, s, 1);
		s++;
		i++;
	}
}

void	ft_print_char(char c, int nb)
{
	while (nb-- > 0)
		ft_putchar(c);
}
