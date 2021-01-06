/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:04:34 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/06 13:28:01 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_lst_prec_delone(t_prec **lst)
{
	if (!*lst)
		return ;
	(*lst)->after_dot = 0;
	(*lst)->align_right = 0;
	(*lst)->size = 0;
	(*lst)->substitution = 0;
	(*lst)->type = 0;
	(*lst) = NULL;
	free(*lst);
}

static int		ft_lst_new_prec(t_prec **lst)
{
	if (!(*lst = malloc(sizeof(t_prec))))
		return (-1);
	(*lst)->after_dot = -1;
	(*lst)->align_right = -1;
	(*lst)->size = 0;
	(*lst)->substitution = -1;
	(*lst)->type = 0;
	return (1);
}

static int		ft_get_star_arg(va_list arg, char *str)
{
	if (str[0] == '*')
		return ((int)va_arg(arg, int));
	else
		return (ft_atoi(str));
	return (0);
}

static t_prec	*ft_lst_init(va_list arg, char *str)
{
	t_prec			*tmp;
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
	tmp->size = ft_get_star_arg(arg, str + i);
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '*'))
		i++;
	if (str[i] && str[i] == '.')
		tmp->after_dot = ft_get_star_arg(arg, str + i + 1);
	tmp->type = str[ft_strlen(str) - 1];
	return (tmp);
}

void			ft_treat_prec(va_list a, int *i, const char *str, t_prec **lst)
{
	int		l;
	char	*tmp;

	l = *i + 1;
	while (str[l] && ((str[l] >= '0' && str[l] <= '9')
	|| str[l] == '.' || str[l] == '-' || str[l] == '*'))
		l++;
	tmp = ft_substr(str + *i, 0, ((l + 1) - *i));
	if (ft_strlen(tmp))
		*lst = ft_lst_init(a, tmp);
	free(tmp);
	*i = l;
}
