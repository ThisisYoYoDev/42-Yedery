NAME	= rush-02
SRCS	= srcs/main.c srcs/ft_ft.c srcs/parser.c srcs/print.c srcs/splitter.c
OBJS	= ${SRCS:.c=.o}
HEADER	= srcs/ft_rush.h

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -I ${HEADER}

%.o: %.c
			${CC} -c ${CFLAGS} -o $@ $< -I ${HEADER}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean
			all