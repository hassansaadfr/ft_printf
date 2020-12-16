/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:10:12 by hsaadaou          #+#    #+#             */
/*   Updated: 2020/12/16 16:13:42 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This function is used by ft_args_count for check if the arg is valid
*/
static int		ft_verify_arg_list(char *str)
{
	char	**cmp;
	int		i;
	int		nbArg;

	i = 0;
	nbArg = 9;
	cmp = ft_split("c,s,p,d,i,u,x,X,lu", ',');
	while (i < nbArg)
	{
		if (ft_memcmp(cmp[i], str, ft_strlen(cmp[i])) == 0)
		{
			free(cmp);
			return (1);
		}
		i++;
	}
	return (0);
}

/*
**	This function count args
** %d%c => 2
** %d%c%%%d => 3
*/

int				ft_args_count(char *str)
{
	int		i;
	char	**splitted;

	splitted = ft_split(str, '%');
	i = 0;
	while (splitted && *splitted)
	{
		if (ft_verify_arg_list(*splitted))
			i++;
		splitted++;
	}
	return (i);
}
