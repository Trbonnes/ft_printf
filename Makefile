CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./ft_printf.c ./ft_printf_utils.c ./ft_indic.c ./ft_indic2.c ./ft_convertbase.c
OBJS = ${SRCS:.c=.o}

INCLUDES =	./ft_printf.h

NAME =		libftprintf.a

LINK = ar rcs

${NAME}:	${SRCS} ft_printf.h
			make libft
			${CC} ${CFLAGS} -I${INCLUDES} -c ${SRCS}
			${LINK} ${NAME} ${OBJS} libf/libft.a
			ranlib ${NAME}

all:		${NAME}

test:		${NAME}
			${CC} ${CFLAGS} libf/libft.a ./libftprintf.a ./main.c 

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re: 		fclean all

.PHONY: all clean fclean re test