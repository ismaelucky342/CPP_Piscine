NAME		= violence
CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror -MMD -MP

SRCS		= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS		= $(SRCS:.cpp=.o)
DEPS		= $(OBJS:.o=.d)

all: $(NAME)
	@echo "------------------------------------------"
	@echo "  $(NAME) compiled successfully"
	@echo "------------------------------------------"

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
