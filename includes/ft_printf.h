/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:35:11 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/02 22:33:47 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"

typedef struct			s_precision {
	int					substitution;
	int					align_right;
	size_t				size;
	int					after_dot;
	int					star_precision;
	char				type;
}						t_precision;

int		ft_printf(const char *, ...);
int		ft_args_count(char *str);
char	*ft_convert_hex(long int var, char *base_to);
char	*convert_number(long long nbr, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
void	ft_process_args(const char *s, va_list arg, t_precision *lst);
void	ft_treat_precision(int *i, const char *str, t_precision **lst);
void	ft_arg_c(va_list arg, char c);
void	ft_arg_d(va_list arg, t_precision **lst);
void    ft_arg_s(va_list arg, t_precision **lst);
void	ft_arg_x(va_list arg, int is_upper);
void	ft_arg_p(va_list arg);
void	ft_lst_prec_delone(t_precision **lst);
void	ft_part_putstr(const char *s, size_t i);
void	ft_print_char(char c, int nb);

#endif
