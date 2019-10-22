CC = gcc
CFLAGS = -Wall -Wextra -Werror -I${INCLUDES}

SRCS =	./ft_printf.c ./ft_printf_utils.c ./ft_indic.c ./ft_indic2.c ./ft_convertbase.c libftfolder/ft_atoi.c libftfolder/ft_itoa.c libftfolder/ft_bzero.c libftfolder/ft_calloc.c libftfolder/ft_isalnum.c libftfolder/ft_isalpha.c libftfolder/ft_isascii.c libftfolder/ft_isdigit.c libftfolder/ft_isprint.c libftfolder/ft_memccpy.c libftfolder/ft_memchr.c libftfolder/ft_memcmp.c libftfolder/ft_memcpy.c libftfolder/ft_memmove.c libftfolder/ft_memset.c libftfolder/ft_putchar_fd.c libftfolder/ft_putendl_fd.c libftfolder/ft_putnbr_fd.c libftfolder/ft_putstr_fd.c libftfolder/ft_split.c libftfolder/ft_strchr.c libftfolder/ft_strdup.c libftfolder/ft_strjoin.c libftfolder/ft_strlcat.c libftfolder/ft_strlcpy.c libftfolder/ft_strlen.c libftfolder/ft_strmapi.c libftfolder/ft_strncmp.c libftfolder/ft_strnstr.c libftfolder/ft_strrchr.c libftfolder/ft_strtrim.c libftfolder/ft_substr.c libftfolder/ft_tolower.c libftfolder/ft_toupper.c libftfolder/ft_lstadd_back_bonus.c libftfolder/ft_lstdelone_bonus.c libftfolder/ft_lstmap_bonus.c libftfolder/ft_lstadd_front_bonus.c libftfolder/ft_lstiter_bonus.c libftfolder/ft_lstnew_bonus.c libftfolder/ft_lstclear_bonus.c libftfolder/ft_lstlast_bonus.c libftfolder/ft_lstsize_bonus.c

OBJS =	${SRCS:.c=.o}

INCLUDES =	libftfolder/libft.h ./ft_printf.h

NAME =		libftprintf.a

LINK = ar rcs

${NAME}:	${SRCS} ${OBJS}
			${LINK} ${NAME} ${OBJS}
			ranlib ${NAME}

all:	${NAME}

test:	${NAME}
		${CC} ${CFLAGS} ./main.c ${NAME}
		
clean:
		rm -f ${OBJS}
	
fclean:	clean
		rm -f ${NAME}

re: 	fclean all

.PHONY:	all clean fclean re test