# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 18:31:54 by hsaadaou          #+#    #+#              #
#    Updated: 2020/12/04 19:21:55 by hsaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang

FLAGS		=	-Wall -Wextra -Werror

NAME		=	libftprintf.a

LIBFT		=	libft.a

SRCS		=	srcs/ft_printf.c

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
				make fclean -C libft

fclean:			clean
				rm -rf $(NAME) ${LIBFT}

re:				fclean all

.PHONY:			all clean fclean re
