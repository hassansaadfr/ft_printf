/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:38:26 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/06 12:30:32 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main()
{
    ft_printf("_%010.*dcwE%9.2s%012xvvf_\n", -6, 2147483647, "2yNkAv8sHDmoa3U3vFMWWeCXcoPMc7", -2147483647);
    printf("_%010.*dcwE%9.2s%012xvvf_\n", -6, 2147483647, "2yNkAv8sHDmoa3U3vFMWWeCXcoPMc7", -2147483647);
	return (0);
}
