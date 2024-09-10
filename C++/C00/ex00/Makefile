NAME = megaphone

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

OBJS = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} Makefile
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

bonus: ${NAME_BONUS}

%.o:%.c
	${CC} ${FLAGS} -c  $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean re