/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:38:26 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/04 17:06:13 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int		main()
{
	// int a = 10;
	ft_printf("_%-8.20d_\n", 14);
	printf("_%-8.20d_\n", 14);
	// ft_printf("%c\n", 'c');
	// ft_printf("%d\n", 12);
	// ft_printf("%u\n", 120);
	// ft_printf("%i\n", 1200);
	// ft_printf("%p\n", &a);
	// ft_printf("%x\n", a);
	// ft_printf("%X\n", a);
	return (0);
}
