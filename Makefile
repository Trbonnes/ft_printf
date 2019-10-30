CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./ft_printf.c ./ft_printf_utils.c ./ft_printf_utils2.c ./ft_convert.c ./ft_indic.c ./ft_indic2.c  ./ft_indiclong.c ./ft_convertbase.c ./ft_longitoa.c ./ft_unsigned_itoa.c ./ft_flag.c ./ft_flag2.c ./ft_indicshort.c ./ft_doublef.c ./ft_doubleitoa.c ./ft_isdouble.c ./ft_iswhat.c
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

test2:		${NAME}
			${CC} ${CFLAGS} libft/libft.a ./libftprintf.a ./test_main.c -D MINE -D BONUS

clean:
			rm -f ${OBJS}
			cd libft && make clean

fclean:		clean
			rm -f ${NAME} a.out
			cd libft && make fclean

re: 		fclean all

.PHONY: all clean fclean re test