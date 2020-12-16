/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:35:11 by hsaadaou          #+#    #+#             */
/*   Updated: 2020/12/16 20:21:04 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include "../libft/libft.h"

int		ft_printf(const char *, ...);
int		ft_args_count(char *str);
char	*get_pointer_address(void *var);
double	ft_atod(char *str);
char	*convert_number(long long nbr, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

#endif
