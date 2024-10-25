NAME		=	libftprintf.a
CC			=	 gcc
FLAGS		=	-Wall -Werror -Wextra

SRCS		=	ft_printf.c \
				ft_printf_len.c \
				ft_printf_conversion.c \
				ft_lib.c

LIBFT		=	libft/libft.a

INCLUDES	=	-Ilibft \
				-I.

AR			=	ar rcs
RM			=	rm -rf

OBJS		=	${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

%.o:%.c ${INCLUDES}
	${CC} ${FLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus