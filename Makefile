# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 18:31:54 by hsaadaou          #+#    #+#              #
#    Updated: 2021/01/13 21:31:13 by hsaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang

FLAGS		=	-Wall -Wextra -Werror

NAME		=	libftprintf.a

SRCS		=	ft_printf.c srcs/parse_args.c srcs/ft_lst_init.c \
				srcs/converter/utils.c srcs/converter/ft_convert_base.c \
				srcs/converter/ft_convert_base2.c srcs/ft_treat_precision.c \
				srcs/converter/ft_utoa.c \
				srcs/ft_arg_c.c srcs/ft_arg_d.c srcs/ft_arg_p.c \
				srcs/ft_arg_s.c srcs/ft_arg_x.c srcs/utils/ft_atoi.c \
				srcs/utils/ft_itoa.c srcs/utils/ft_putchar.c \
				srcs/utils/ft_putstr.c srcs/utils/ft_strlen.c \
				srcs/utils/ft_strjoin.c srcs/utils/ft_substr.c \
				srcs/utils/ft_calloc.c srcs/utils/ft_bzero.c \
				srcs/utils/ft_strchr.c

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
