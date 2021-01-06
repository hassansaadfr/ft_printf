/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:38:26 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/06 11:34:31 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main()
{
    ft_printf("+_%10.6s_\n", 0);
    printf("-_%10.6s_\n", 0);
    ft_printf("+_%10.10s_\n", 0);
    printf("-_%10.10s_\n", 0);
    ft_printf("+_%10.1s_\n", 0);
    printf("-_%10.1s_\n", 0);
	ft_printf("+_%p_\n", 0);
	printf("-_%p_\n", 0);
	return (0);
}
