NAME = iter

CC = c++

FLAGS = -g3 -Wall -Wextra -Werror -std=c++98

SRC = main.cpp 

OBJS = ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

%.o:%.cpp Makefile iter.hpp
	${CC} ${FLAGS} -c  $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
	
re: fclean all

.PHONY: all clean fclean re	