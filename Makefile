CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./ft_printf.c ./ft_printf_utils.c ./ft_indic.c ./ft_indic2.c ./ft_convertbase.c
OBJS = ${SRCS:.c=.o}

INCLUDES =	./ft_printf.h

NAME =		libftprintf.a

LINK = ar rcs

${NAME}:	${SRCS} ft_printf.h
			cd libft && make bonus
			${CC} ${CFLAGS} -I${INCLUDES} -c ${SRCS}
			${LINK} ${NAME} ${OBJS} libft/libft.a
			ranlib libftprintf.a

all:		${NAME}

test:		${NAME}
			${CC} ${CFLAGS} libft/libft.a ./libftprintf.a ./main.c 

clean:
			rm -f ${OBJS}
			cd libft && make clean

fclean:		clean
			rm -f ${NAME} a.out
			cd libft && make fclean

re: 		fclean all

.PHONY: all clean fclean re test