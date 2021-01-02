/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:05:42 by hsaadaou          #+#    #+#             */
/*   Updated: 2020/12/20 18:05:59 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long int	nbr;

	nbr = nb;
	if (nb == -2147483648)
	{
		ft_putchar('-');
		nbr = 2147483648;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	if (nbr < 10)
	{
		ft_putchar(nbr % 10 + '0');
	}
}
