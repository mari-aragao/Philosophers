NAME	=	philo

SRCS	=	\
		./srcs/main.c \
		./srcs/lldb.c \
		./srcs/actions.c \
		./srcs/destroy.c \
		./srcs/init.c \
		./srcs/utils.c \
		./srcs/print.c \
		./srcs/time.c \
		./srcs/checks.c

INCLUDES	= ./includes

CC	= -Wall -Wextra -Werror -pthread -g 

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
