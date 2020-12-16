# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 18:31:54 by hsaadaou          #+#    #+#              #
#    Updated: 2020/12/16 18:45:08 by hsaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang

FLAGS		=	-Wall -Wextra -Werror

NAME		=	libftprintf.a

LIBFT		=	libft.a

SRCS		=	ft_printf.c srcs/parse_args.c srcs/converter/ft_atod.c \
				srcs/converter/utils.c srcs/converter/ft_convert_base.c \
				srcs/converter/ft_convert_base2.c

HEADERS		=	includes

OBJECTS		=	${SRCS:.c=.o}

all:			$(NAME)

.c.o:
				${CC} ${FLAGS} -I./${HEADERS} -c $< -o ${<:.c=.o}

$(NAME) :		${OBJECTS}
				$(MAKE) bonus -C libft
				cp libft/${LIBFT} .
				ar rc ${NAME} ${OBJECTS}

clean:
				rm -rf ${OBJECTS}
				rm -rf ${LIBFT}
				make fclean -C libft

fclean:			clean
				rm -rf $(NAME) ${OBJECTS}

re:				fclean all

.PHONY:			all clean fclean re
