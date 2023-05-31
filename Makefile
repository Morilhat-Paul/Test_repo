##
## EPITECH PROJECT, 2022
## Lem_in
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

TARGET_NAME		=	template
SOURCE_DIR		=	sources
OBJECT_DIR		=	objects
LIBRARY_DIR		=	lib
HEADER_DIR		=	include
TEST_DIR		= 	tests
MAKE			=	make -s -C
RM				=	rm -rf
PRINT			=	echo

vpath %.c $(SOURCE_DIR)

## PRINTING ##

BUILD_DONE		=	${BOLD}${GREEN}"=== Building\t\t\t\t"${ITALIC}"DONE !"			${END}
BUILD_PROGRESS	=	${BOLD}${LYELLOW}"=== Building\t\t\t\t"${ITALIC}"IN PROGRESS"	${END}
CLEAN_BIN		=	${BOLD}${GREEN}"=== Cleaning binary\t\t\t\t"${ITALIC}"DONE !"	${END}
CLEAN_OBJ		=	${BOLD}${GREEN}"=== Cleaning object\t\t\t\t"${ITALIC}"DONE !" 	${END}
COMPILING		=	${BOLD}${PURPLE}"=== Compiling $<" 								$(END)



## COMPILER OPTIONS ##

CC			=	gcc
CFLAGS		=	-W -Wall -Wextra -Werror	\
				-I$(HEADER_DIR)	\
				-Wno-unused-variable	\
				-Wno-unused-parameter	\
				-Wno-unused-but-set-variable	\
				-Wno-unused-but-set-parameter	\
				-g3
LFLAGS		= 	-L $(LIBRARY_DIR) -lchained_list	\
				-L $(LIBRARY_DIR) -lmy



## 	SOURCES FILES 	##

SRC		=	main.c



## 	OBJECT FILES 	##

OBJ		=	${SRC:%.c=${OBJECT_DIR}/%.o}

${OBJECT_DIR}/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ $(CFLAGS) $(LFLAGS)
	@$(PRINT) $(COMPILING)



##		RECIPES		##

.PHONY: all re clean fclean

all: $(TARGET_NAME)

clean:
	@$(MAKE) $(LIBRARY_DIR) clean
	@$(RM) $(OBJECT_DIR)
	@$(RM) *.log
	@$(PRINT) $(CLEAN_OBJ)

fclean: clean
	@$(MAKE) $(LIBRARY_DIR) fclean
	@$(RM) $(TARGET_NAME)
	@$(PRINT) $(CLEAN_BIN)

re: fclean all

tests_run: fclean_tests
	@echo ${BOLD}${BLUE}"\n\t\t\tSTARTING THE UNITARY TESTS !\n" ${END}
	@$(MAKE) $(TEST_DIR)/ ||	\
	(echo ${BOLD}${BLUE}"\n\t\t\tEND OF UNITARY TESTS !\n" ${END} && exit 1)
	@echo ${BOLD}${BLUE}"\n\t\t\tEND OF UNITARY TESTS !\n" ${END}

tests_functional:
	@$(MAKE) $(TEST_DIR)/ functional

display_test:
	@echo ${BOLD}${BLUE}"\n\t\t\tSTARTING THE UNITARY TESTS !\n" ${END}
	@gcovr --exclude $(TEST_DIR)/unitary/ --branches --print-summary
	@gcovr --exclude $(TEST_DIR)/unitary/
	@echo ${BOLD}${BLUE}"\n\t\t\tEND OF UNITARY TESTS !\n" ${END}

tests_all: fclean_tests
	@-$(MAKE) $(TEST_DIR)/ functional
	@echo ${BOLD}${BLUE}"\n\t\t\tSTARTING THE UNITARY TESTS !\n" ${END}
	@-$(MAKE) $(TEST_DIR)/
	@gcovr --exclude $(TEST_DIR)/unitary/ --branches --print-summary
	@gcovr --exclude $(TEST_DIR)/unitary/
	@$(MAKE) $(TEST_DIR)/ clean
	@echo ${BOLD}${BLUE}"\n\t\t\tEND OF UNITARY TESTS !\n" ${END}

clean_tests:
	@$(MAKE) $(TEST_DIR)/ clean

fclean_tests:
	@$(MAKE) $(TEST_DIR)/ fclean

clean_all: fclean fclean_tests



##	FILE GENERATOR	##

$(TARGET_NAME): $(OBJ)
	@$(MAKE) $(LIBRARY_DIR)/
	@$(PRINT) $(BUILD_PROGRESS)
	@$(CC) -o $@ $(CFLAGS) $^ $(LFLAGS)
	@$(PRINT) $(BUILD_DONE)
