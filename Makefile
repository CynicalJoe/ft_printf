SRCS	= writer.c free.c conversion.c conversionptr.c flags.c ft_printf.c ressources.c untoa.c treatflags.c width.c

HEADER	= includes

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc

RM		= rm -f

CFLAGS	= -c -Wall -Wextra -Werror -I${HEADER}

all:	${NAME}

${NAME}:	${OBJS}
	${MAKE} bonus -C ./libft
	cp libft/libft.a ${NAME}
	${CC} ${CFLAGS} ${SRCS} 
	ar rcs ${NAME} ${OBJS}

clean:	
	${RM}	${OBJS} 
	${MAKE} clean -C ./libft

fclean:	clean
	${RM} ${NAME}
	${MAKE} fclean -C ./libft

re:	fclean all