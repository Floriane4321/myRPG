##
## EPITECH PROJECT, 2020
## MY MAKEFILES
## File description:
## the ultimate makefile
##

.RECIPEPREFIX =	-


NAME	=	my_rpg
OBJECT	=	obj
SOURCES	=	src

###################
## Compil option ##
###################

CC      =       gcc
CFLAG   =	-lm \
##-W -Wall -Wextra \
#		 -Wno-unused-variable \
###########
## imput ##
###########

DIRS = . gdata \
	m_event \
	game_admin \
	data_base \
	entity \
	button \
	music \
	tower \
	player \
	map \
	proj \
	text \
	fight \
	obj_const	\
	view \
	item \

BLACK_LIST_DIR	= .
BLACK_LIST_SRC = 

DIR_INCLUDE = -I include/
DIR_LIB = -L lib/c_star/ -lc_star -L lib/my/ -lmy \
        -lcsfml-graphics \
        -lcsfml-window \
        -lcsfml-system \
        -lcsfml-audio

#######################
## directory find .c ##
#######################

FILE    =       $(subst /.,, $(files))

files	=	$(foreach dir,$(DIR_SRC_PATH),$(wildcard $(dir)/*.c))

####################
### PATH Manager ###
####################

NEW_OBJ_DIR = $(filter-out $(BLACK_LIST_DIR), $(DIRS))

DIR_SRC_PATH = $(addprefix $(SOURCES)/, $(DIRS))
DIR_OBJ_PATH = $(addprefix $(OBJECT)/, $(NEW_OBJ_DIR))

###########
### OBJ ###
###########

ALL_OBJ =       $(patsubst %.c, $(OBJECT)/%.o, $(SRC))

SRC	=	$(filter-out $(BLACK_LIST_SRC), $(subst $(SOURCES)/,, $(FILE)))

############
### RULE ###
############

.PHONY: all re clean folder fclean 
.DEFAULT: all

all:	Folder $(NAME)
-@echo	-e "\e[32mlinking compliete\e[39m"

$(NAME): Form_preCompil subdir $(ALL_OBJ)
-@gcc -o $(NAME) $(ALL_OBJ) $(DIR_LIB) $(CFLAG) -g -Wno-unused-variable

Folder:	|	$(OBJECT)

subdir:
-@echo -e "\n\e[1;94mLib compilation\e[0m"
-@make -C lib/c_star
-@make -C lib/my

clean:
-@echo -e "\e[33m-->Cleaning time\e[00m"
-rm -f ./$(OBJECT)/*.o
-rm -f  $(addsuffix /*.o, $(DIR_OBJ_PATH))

fclean:	clean
-make fclean -C lib/my
-make fclean -C lib/c_star
-rm -rf $(OBJECT)/
-rm -f $(NAME)

re:	clean all

###################
### INTERN RULE ###
###################
        ##dialogue rule
Form_preCompil:
-@echo -e "\n\e[1;94mCompilation start\e[0m"

        ##dir generate
$(OBJECT):
-@echo -e "\e[95mOBJ Directory Generate\e[0m"
-@mkdir -p $(OBJECT)
-@mkdir  $(DIR_OBJ_PATH)

       ##target: $() = destiantion final; depandance: $(sources)/ = fichier de base
$(OBJECT)/%.o	: $(SOURCES)/%.c
-@$(CC) -c -o $@ $< $(CFLAG) -I include/ -g3
-@echo -e "\t\e[36mCompilate \e[3;97;4m$@\e[00m; \e[1;92mSUCCES\e[00m"
