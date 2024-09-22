NAME = Class_in_Orthodox_Canonical_Form

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp

OBJS = ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS} Makefile Fixed.hpp
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

bonus: ${NAME_BONUS}

%.o:%.cpp
	${CC} ${FLAGS} -c  $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
	
re: fclean all

.PHONY: all clean fclean re	