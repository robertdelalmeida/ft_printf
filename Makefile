NAME		=	libftprintf.a
CC			=	 gcc
FLAGS		=	-Wall -Werror -Wextra

SRCS		=	ft_printf.c \
				ft_aux_len.c \
				ft_types.c \
				ft_flags.c \
				ft_lib.c

INCLUDES	=	-I.

AR			=	ar rcs
RM			=	rm -rf

OBJS		=	${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

%.o:%.c ${INCLUDES}
	${CC} ${FLAGS} -c $< -o $@

bonus: ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re