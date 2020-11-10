##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## cpp
##

SRC =	main.cpp	\
		src/Components/Clock.cpp \
		src/Components/False.cpp \
		src/Components/Input.cpp \
		src/Components/FactoryComponent.cpp \
		src/Components/Output.cpp \
		src/Components/True.cpp \
		src/Components/AComponent.cpp \
		src/Components/C4001.cpp \
		src/Components/C4011.cpp \
		src/Components/C4030.cpp \
		src/Components/C4040.cpp \
		src/Components/C4069.cpp \
		src/Components/C4071.cpp \
		src/Components/C4081.cpp \
		src/Core/Core.cpp \
		src/Parser/Parser.cpp \
		src/Core/Prompt.cpp

NAME =	nanotekspice

CPP =	g++

OBJ =	$(SRC:.cpp=.o)

CPPFLAGS =	-Iinclude -Iinclude/Core -Iinclude/Components -Iinclude/Exceptions -Iinclude/Parser
CPPFLAGS +=	-W -Wall -Wextra -Werror -std=c++14

all:	$(NAME)

$(NAME): $(OBJ)
	$(CPP) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:		fclean all