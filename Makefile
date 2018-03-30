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

LDFLAGS		+=

DBGFLAGS	= -g3

DET		= detection_test

SRC_DET		= src/detection/main.cpp

OBJ_DET		= $(SRC_DET:.cpp=.o)

OPTI		= opti_test

SRC_OPTI	= src/optimisation/main.cpp

OBJ_OPTI	= $(SRC_OPTI:.cpp=.o)

ECHO		= echo -e

DEFAULT		= "\033[00m"
GREEN		= "\033[0;32m"
BLUE		= "\033[1;36m"
RED		= "\033[0;31m"

all: $(DET) $(OPTI)

%.o: %.cpp
	@$(COMP) -o $@ -c $< $(CFLAGS) $(LDFLAGS) $(INCLUDES) && \
	 ($(ECHO) $(GREEN) "[OK]" $(BLUE) $@ $(DEFAULT)) || \
	 ($(ECHO) $(RED) "[XX]" $(BLUE) $@ $(DEFAULT))

$(DET): $(OBJ_DET)
	@$(COMP) $(OBJ_DET) -o $@ $(CFLAGS) $(LDFLAGS) $(INCLUDES) && \
	 ($(ECHO) $(GREEN) "[OK]" $(BLUE) $@ $(DEFAULT)) || \
	 ($(ECHO) $(RED) "[XX]" $(BLUE) $@ $(DEFAULT))

$(OPTI): $(OBJ_OPTI)
	@$(COMP) $(OBJ_OPTI) -o $@ $(CFLAGS) $(LDFLAGS) $(INCLUDES) && \
	 ($(ECHO) $(GREEN) "[OK]" $(BLUE) $@ $(DEFAULT)) || \
	 ($(ECHO) $(RED) "[XX]" $(BLUE) $@ $(DEFAULT))

clean:
	@$(RM) $(OBJ_DET) $(OBJ_OPTI)
	@$(ECHO) $(BLUE) "Cleaning object files" $(DEFAULT)

fclean: clean
	@$(RM) $(DET) $(OPTI)
	@$(ECHO) $(BLUE) "Cleaning binary" $(DEFAULT)

re: fclean all

rec: all clean

edit:
	$(EDITOR) $(SRC)

debug:	CFLAGS += $(DBGFLAGS)
debug:	re

.PHONY: all clean fclean re rec edit debug
