SRCS			= ex0107.cpp
OBJS			= $(SRCS:.cpp=.o)

CLANG			= clang++
RM				= rm -f
CLANGFLAGS		= -Wall -Wextra -Werror -I.

NAME			= ex0107

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CLANG) $(CLANGFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) 

re:				fclean $(NAME)

.PHONY:			all clean fclean re test