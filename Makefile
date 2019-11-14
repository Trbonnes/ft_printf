CC = gcc
CFLAGS = -Wall -Wextra -Werror -I${INCLUDES} -c

SRCS = libft/ft_atoi.c libft/ft_itoa.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c src/ft_printf.c src/ft_printf_utils.c src/ft_printf_utils2.c src/ft_convert.c src/ft_indic.c src/ft_indic2.c  src/ft_indiclong.c src/ft_indiclong2.c src/ft_convertbase.c src/ft_longitoa.c src/ft_unsigned_itoa.c src/ft_flag.c src/ft_flag2.c src/ft_indicshort.c src/ft_doublef.c src/ft_doubleitoa.c src/ft_isdouble.c src/ft_iswhat.c src/ft_dtol.c src/ft_wchar.c
OBJS = ${SRCS:.c=.o}

INCLUDES =	./includes/ft_printf.h

NAME =		libftprintf.a

LINK = ar rcs

${NAME}:	${OBJS} ./includes/ft_printf.h
			cd libft && make bonus
			${LINK} ${NAME} ${OBJS}
			ranlib libftprintf.a

all:		${NAME}

test:		${NAME}
			${CC} -Wall -Wextra -Werror ./libftprintf.a libft/libft.a ./main.c 

test2:		${NAME}
			${CC} -Wall -Wextra -Werror ./libftprintf.a libft/libft.a ./test_main.c

bonus:		${NAME}

clean:
			rm -f ${OBJS}
			cd libft && make clean

fclean:		clean
			rm -f ${NAME}
			rm -f a.out
			cd libft && make fclean

re: 		fclean all

.PHONY: all clean fclean re test