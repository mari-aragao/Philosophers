NAME	=	philo

SRCS	=	\
		./srcs/main.c \
		./srcs/utils.c \
		./srcs/checks.c

INCLUDES	= ./includes

CC	= -Wall -Wextra -Werror -g

${NAME}:	${SRCS}	
	cc ${CC} -I ${INCLUDES} ${SRCS} -o ${NAME}

all:	${NAME}

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}
	rm -rf *.dSYM

re:	fclean all

.PHONY:	re fclean clean all
