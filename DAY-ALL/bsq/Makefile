SRCSC	= src/process_file.c src/algo.c src/process_file.c
OBJS	= ${SRCSC:.c=.o}
HEADER	= ft.h
NAME	= BSQ
CFLAGS	= -Wall -Wextra -Werror
CC		= gcc
%.o: %.c
			${CC} -c ${CFLAGS} -o $@ $< -I ${HEADER}
all:		${NAME}
${NAME}: 	${OBJS}
clean:
	rm -f ${OBJS}
fclean:	clean
		rm -f ${NAME}
re:		fclean all
.PHONY: all clean fclean re