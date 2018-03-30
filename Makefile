##
## Makefile for Missile Command in /home/okami/rendu/Orsay/missileCommand2
##
## Made by Pierrick Garcia
## Login   <pierrick.garcia@u-psud.fr>
##
## Started on  Tue Oct 10 13:52:27 2017 Pierrick Garcia
## Last update Sat Jan 13 23:43:43 2018 Pierrick Garcia
##

COMP		= g++

EDITOR		= emacs -nw

CFLAGS		+= -W -Wall -Wextra -O3 -std=c++11

INCLUDES	+= -I./include

RM		= rm -f

NAME		= output

LDFLAGS		+=

DBGFLAGS	= -g3

SRC		= src/main.cpp

OBJ		= $(SRC:.cpp=.o)

ECHO		= echo -e

DEFAULT		= "\033[00m"
GREEN		= "\033[0;32m"
BLUE		= "\033[1;36m"
RED		= "\033[0;31m"

all: $(NAME)

%.o: %.cpp
	@$(COMP) -o $@ -c $< $(CFLAGS) $(LDFLAGS) $(INCLUDES) && \
	 ($(ECHO) $(GREEN) "[OK]" $(BLUE) $@ $(DEFAULT)) || \
	 ($(ECHO) $(RED) "[XX]" $(BLUE) $@ $(DEFAULT))

$(NAME): $(OBJ)
	@$(COMP) $(OBJ) -o $@ $(CFLAGS) $(LDFLAGS) $(INCLUDES) && \
	 ($(ECHO) $(GREEN) "[OK]" $(BLUE) $@ $(DEFAULT)) || \
	 ($(ECHO) $(RED) "[XX]" $(BLUE) $@ $(DEFAULT))

clean:
	@$(RM) $(OBJ)
	@$(ECHO) $(BLUE) "Cleaning object files" $(DEFAULT)

fclean: clean
	@$(RM) $(NAME)
	@$(ECHO) $(BLUE) "Cleaning binary" $(DEFAULT)

re: fclean all

rec: all clean

edit:
	$(EDITOR) $(SRC)

debug:	CFLAGS += $(DBGFLAGS)
debug:	re

.PHONY: all clean fclean re rec edit debug
