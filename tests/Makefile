##
## EPITECH PROJECT, 2022
## Bootstrap
## File description:
## Makefile
##

# This is a minimal set of ANSI/VT100 color codes
END		=	"\e[0m"
BOLD	=	"\e[1m"
ITALIC	=	"\e[3m"
DIM		=	"\e[2m"
RDIM	=	"\e[22m"

# Colors
GREEN	=	"\e[32m"
PURPLE	=	"\e[35m"
BLUE	=	"\e[36m"
LYELLOW	=	"\e[93m"


## 		OPTIONS 	##

TARGET_NAME		=	unit_tests
PROJECT_NAME	=	template
LIB_NAME		=	my
SOURCE_DIR		=	../sources
OBJECT_DIR		=	../objects
LIBRARY_DIR		=	../lib
LIBRARY_SRC		=	$(LIBRARY_DIR)/$(LIB_NAME)/sources
HEADER_DIR		=	../include
CRITERION		=	--coverage -lcriterion
ARR				=	array
MAT				=	maths
PUT				=	put
STR				=	strings


## COMPILER OPTIONS ##

CC			=	gcc
CFLAGS		=	-W -Wall -Wextra -Werror	\
				-I${HEADER_DIR}	\
				-Wno-unused-variable	\
				-Wno-unused-parameter	\
				-Wno-unused-but-set-variable	\
				-Wno-unused-but-set-parameter	\
				-g3
LFLAGS		=	-L $(LIBRARY_DIR) -lmy	\
				-L $(LIBRARY_DIR) -lchained_list



## 	SOURCES FILES 	##

SRC_LIB	=	$(LIBRARY_SRC)/$(STR)/my_addchar.c	\
			$(LIBRARY_SRC)/$(MAT)/my_getnbr.c	\
			$(LIBRARY_SRC)/$(STR)/my_is_alpha.c	\
			$(LIBRARY_SRC)/$(PUT)/my_perror.c	\
			$(LIBRARY_SRC)/$(PUT)/my_putchar.c	\
			$(LIBRARY_SRC)/$(PUT)/my_putnbr.c	\
			$(LIBRARY_SRC)/$(PUT)/my_putstr.c	\
			$(LIBRARY_SRC)/$(PUT)/my_putrevstr.c	\
			$(LIBRARY_SRC)/$(ARR)/my_putarray.c	\
			$(LIBRARY_SRC)/$(ARR)/my_putnarray.c	\
			$(LIBRARY_SRC)/$(STR)/my_revstr.c	\
			$(LIBRARY_SRC)/$(STR)/my_str_to_word_array.c	\
			$(LIBRARY_SRC)/$(STR)/my_strcat.c	\
			$(LIBRARY_SRC)/$(STR)/my_strcmp.c	\
			$(LIBRARY_SRC)/$(STR)/my_strcpy.c	\
			$(LIBRARY_SRC)/$(STR)/my_strdup.c	\
			$(LIBRARY_SRC)/$(STR)/my_strlen.c	\
			$(LIBRARY_SRC)/$(STR)/my_strncat.c	\
			$(LIBRARY_SRC)/$(STR)/my_strncmp.c	\
			$(LIBRARY_SRC)/$(STR)/my_strncpy.c	\
			$(LIBRARY_SRC)/$(STR)/my_strstr.c	\
			$(LIBRARY_SRC)/$(MAT)/my_nbrcmp.c	\
			$(LIBRARY_SRC)/$(MAT)/my_absolute_nbr.c	\
			$(LIBRARY_SRC)/my_swap.c

SRC		=	$(SRC_LIB)

UNIT_TESTS	=	unitary/lib/my/*.c


FUNC_TEST	=	functional/test.sh



## 	OBJECT FILES 	##

OBJ		=	${SRC:%.c=${OBJECT_DIR}/%.o}

${OBJECT_DIR}/%.o : %.c
	@mkdir -p $(dir $@)
	@${CC} -c $< -o $@ ${CFLAGS} ${LFLAGS}
	@echo ${BOLD}${PURPLE}"=== Compiling $<" $(END)



##		RECIPES		##

.PHONY: all re clean fclean

all: $(TARGET_NAME)
	@./$(FUNC_TEST)
	@echo ${BOLD}${BLUE}"\n\t\t\tSTARTING THE UNITARY TESTS !\n" ${END}
	@./$<

clean:
	rm -f *.gc*
	@echo ${BOLD}${GREEN}\
	"=== Cleaning testing files\t\t\t"${ITALIC}"DONE !" ${END}

fclean: clean
	@rm -f $(TARGET_NAME)
	@rm -f functional/$(PROJECT_NAME)
	@echo ${BOLD}${GREEN}\
	"=== Cleaning binary test\t\t\t"${ITALIC}"DONE !" ${END}

re: fclean all



##	FILE GENERATOR	##

$(TARGET_NAME):
	cp ../$(PROJECT_NAME) functional/
	$(CC) -o $@ $(CFLAGS) $(SRC) $(LFLAGS) $(UNIT_TESTS) $(CRITERION)
	@echo ${BOLD}${GREEN}\
	"=== Building tests\t\t\t\t"${ITALIC}"DONE !" ${END}
