NAME = harl

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Harl.cpp

OBJS = ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS} Makefile Harl.hpp
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