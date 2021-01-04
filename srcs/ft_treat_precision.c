/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:04:34 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/04 15:24:35 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_lst_prec_delone(t_precision **lst)
{
	if (!*lst)
		return ;
	(*lst)->after_dot = 0;
	(*lst)->align_right = 0;
	(*lst)->size = 0;
	(*lst)->substitution = 0;
	(*lst)->type = 0;
	(*lst)->star_precision = 0;
	(*lst) = NULL;
	free(*lst);
}

static int			ft_lst_new_prec(t_precision **lst)
{
	if (!(*lst = malloc(sizeof(t_precision))))
		return (-1);
	(*lst)->after_dot = NOT_SET;
	(*lst)->align_right = NOT_SET;
	(*lst)->size = NOT_SET;
	(*lst)->substitution = NOT_SET;
	(*lst)->type = 0;
	(*lst)->star_precision = NOT_SET;
	return (1);
}

static t_precision	*ft_lst_init(char *str)
{
	t_precision		*tmp;
	int				i;

	i = 0;
	if (!(ft_lst_new_prec(&tmp)))
		return (NULL);
	if (str[i] == '-')
	{
		tmp->align_right = 1;
		i++;
	}
	if (str[i] == '0')
		tmp->substitution = 1;
	tmp->size = ft_atoi(str + i);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] && str[i] == '.')
	{
		if (str[i + 1] == '*')
			tmp->star_precision = 1;
		else
			tmp->after_dot = ft_atoi(str + i + 1);
	}
	tmp->type = str[ft_strlen(str) - 1];
	return (tmp);
}

void				ft_treat_precision(int *i, const char *str, t_precision **lst)
{
	int		l;
	char	*tmp;

	l = *i + 1;
	while (str[l] && ((str[l] >= '0' && str[l] <= '9')
	|| str[l] == '.' || str[l] == '-' || str[l] == '*'))
		l++;
	tmp = ft_substr(str + *i, 0, ((l + 1) - *i));
	if (ft_strlen(tmp))
		*lst = ft_lst_init(tmp);
	free(tmp);
	*i = l;
}
