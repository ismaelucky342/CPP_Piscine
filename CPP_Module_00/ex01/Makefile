NAME		= phonebook
CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror -MMD -MP
LDFLAGS		= -lreadline -lncurses

SRCS		= P_book.cpp contact.cpp
OBJS		= $(SRCS:.cpp=.o)
DEPS		= $(OBJS:.o=.d)

all: $(NAME)
	@echo "------------------------------------------"
	@echo "  $(NAME) compiled successfully"
	@echo "------------------------------------------"

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
