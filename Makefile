# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 15:52:37 by rdel-fra          #+#    #+#              #
#    Updated: 2024/11/01 15:55:49 by rdel-fra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	cc

FLAGS		=	-Wall -Werror -Wextra

SRCS		=	ft_printf.c \
				ft_utils.c \
				ft_types.c \
				ft_lib.c

SRCS_BONUS	=	ft_printf_bonus.c \
				ft_utils_bonus.c \
				ft_types_bonus.c \
				ft_flags_bonus.c \
				ft_lib_bonus.c

INCLUDES	=	ft_printf.h \
				ft_printf_bonus.h

AR			=	ar rcs
RM			=	rm -rf

OBJS		=	${SRCS:.c=.o}

OBJS_BONUS		=	${SRCS_BONUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}

%.o:%.c ${INCLUDES}
	${CC} ${FLAGS} -c $< -o $@
	${AR} ${NAME} $@

bonus: ${OBJS_BONUS}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus