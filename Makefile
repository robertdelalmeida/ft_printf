NAME		=	ft_printf
CC			=	 gcc
FLAGS		=	-Wall -Werror -Wextra

SRCS		=	ft_printf.c

LIBFT		=	libft/libft.a

INCLUDES	=	-Ilibft \
				-I.

AR			=	ar rcs
RM			=	rm -rf

OBJS		=	${SRCS:.c=.o}
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} ${LIBFT} ${INCLUDES} -o ${NAME}

%.o:%.c ${INCLUDES}
	${CC} ${FLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus