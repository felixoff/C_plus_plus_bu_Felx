SRCS			= megaphone.cpp
OBJS			= $(SRCS:.cpp=.o)

CLANG				= clang++
RM				= rm -f
CLANGFLAGS		= -Wall -Wextra -Werror

NAME			= megaphone

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CLANG) $(CLANGFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re