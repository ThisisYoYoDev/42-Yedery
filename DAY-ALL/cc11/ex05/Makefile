NAME	=	do-op
SRCS	=	calc.c comp.c do_op.c
OBJS	=	${SRCS:.c=.o}
HEADER	=	ft.h

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all:	${SRCS}
		${CC} -c ${CFLAGS} ${SRCS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} -I ${HEADER}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
