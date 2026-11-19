NAME		= span
CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRCS		= main.cpp Span.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)
	@echo "------------------------------------------"
	@echo "  $(NAME) compiled successfully"
	@echo "------------------------------------------"

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
