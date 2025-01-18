NAME = reinterpret


CC = c++

FLAGS = -g3 -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Serializer.cpp

OBJS = ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

%.o:%.cpp Makefile Serializer.hpp Data.hpp
	${CC} ${FLAGS} -c  $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
	
re: fclean all

.PHONY: all clean fclean re	