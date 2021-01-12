# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 18:31:54 by hsaadaou          #+#    #+#              #
#    Updated: 2021/01/11 16:26:39 by hsaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang

FLAGS		=	-Wall -Wextra -Werror -g

NAME		=	libftprintf.a

SRCS		=	ft_printf.c srcs/parse_args.c \
				srcs/converter/utils.c srcs/converter/ft_convert_base.c \
				srcs/converter/ft_convert_base2.c srcs/ft_treat_precision.c \
				srcs/ft_arg_c.c srcs/ft_arg_d.c srcs/ft_arg_p.c \
				srcs/ft_arg_s.c srcs/ft_arg_x.c libft/ft_atoi.c libft/ft_itoa.c \
				libft/ft_putchar.c libft/ft_putstr.c libft/ft_strlen.c \
				libft/ft_strjoin.c libft/ft_substr.c libft/ft_calloc.c \
				libft/ft_bzero.c libft/ft_strdup.c libft/ft_strlcpy.c \
				libft/ft_strchr.c srcs/converter/ft_utoa.c

HEADERS		=	includes

OBJECTS		=	${SRCS:.c=.o}

all:			$(NAME)

.c.o:
				${CC} ${FLAGS} -I./${HEADERS} -c $< -o ${<:.c=.o}

$(NAME) :		${OBJECTS}
				ar rc ${NAME} ${OBJECTS}

clean:
				rm -rf ${OBJECTS}

fclean:			clean
				rm -rf $(NAME) ${OBJECTS}

re:				fclean all

.PHONY:			all clean fclean re
