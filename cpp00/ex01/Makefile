SRCS		=	main.cpp \
				classCreate.cpp 

OBJS		= ${SRCS:.cpp=.o}

NAME		= phoneBook

CC			= clang++
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror 

$(NAME):	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
