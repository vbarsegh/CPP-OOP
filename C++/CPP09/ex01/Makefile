NAME = RPN

CC = c++

FLAGS = -g3 -Wall -Wextra -Werror -std=c++98

SRC = main.cpp RPN.cpp

OBJS = ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

%.o:%.cpp Makefile RPN.hpp
	${CC} ${FLAGS} -c  $< -o $@  -I.

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
	
re: fclean all

.PHONY: all clean fclean re	