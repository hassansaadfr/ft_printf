/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:38:26 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/06 11:47:26 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main()
{
    ft_printf("%.3sOp2v%-2um%0.5XBr5OJdC%-XM\n", "H4aTEv6XtNVMsXpPZ7B6XZGQ8WD8U TPJ", 0, -2147483647, 2080778212);
    printf("%.3sOp2v%-2um%0.5XBr5OJdC%-XM\n", "H4aTEv6XtNVMsXpPZ7B6XZGQ8WD8U TPJ", 0, -2147483647, 2080778212);
	return (0);
}
