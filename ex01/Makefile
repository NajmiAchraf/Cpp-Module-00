#*******************************#
#			INIT				#
#*******************************#

NAME = PhoneBook

NAME_UP  = $(shell echo $(NAME) | tr  '[:lower:]' '[:upper:]')

CPP = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = \
	Contact.Class.cpp	\
	PhoneBook.Class.cpp	\
	PhoneBook.cpp		\

OBJ = $(SRCS:.cpp=.o)

#*******************************#
#			COLORS				#
#*******************************#

C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m

#*******************************#
#			MAKING				#
#*******************************#

.PHONY : all clean fclean re

%.o : %.cpp
	@$(CPP) $(CPPFLAGS) -c $^ -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "$(C_GREEN)[${NAME_UP} CREATED!]$(C_RES)"

clean :
	@rm -f $(OBJ)
	@echo "$(C_RED)[${NAME_UP} OBJECTS DELETED!]$(C_RES)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(C_RED)[${NAME_UP} EXECUTABLES DELETED!]$(C_RES)"

re : fclean all

run : re
	@echo "$(C_L_BLUE)[RUN ${NAME_UP}!]$(C_RES)"
	@./$(NAME)
