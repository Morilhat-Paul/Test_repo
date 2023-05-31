#!/bin/python3
##
## EPITECH PROJECT, 2022
## Test
## File description:
## create_test.py
##

from colorama import Fore
import os
import sys

TEST_DIR = "./tests/functional"
OUTPUT_FILE = "output.txt"
RESULT_FILE = "resolve_output.txt"
VARIABLE = """
    RESULT=${FOLDER}/${CAT}/${TEST}
    OUTPUT=${FOLDER}/${CAT}/${TEST}
    RESULT+="/${RESULT_FILE}"
    OUTPUT+="/${OUTPUT_FILE}"
    FLAG=0

"""
TEST = """
    if [[ $? -eq 0 ]]; then
        if diff -u "${OUTPUT}" "${RESULT}"; then
            echo -e ${PURPLE}${BOLD}"${CAT}\t"${END}${GREEN}"${TEST} test passed !"${END}
            return $PASSED
        else
            echo -e ${PURPLE}${BOLD}"${CAT}\t"${END}${LYELLOW}"${TEST} test failed ! (Output)"${END}
            return $FAILED
        fi
    else
        echo -e ${PURPLE}${BOLD}"${CAT}\t"${END}${LYELLOW}"${TEST} test failed ! (Return)"${END}
        return $FAILED
    fi
    return $PROBLEM
}
"""
HELPER = """
USAGE:
    ./create_test.py

DESCRIPTION:
    Create a functional test

"""

def create_dir(CAT: str, NAME: str):
    dir = os.path.join(TEST_DIR, CAT)
    if not os.path.exists(dir):
        os.mkdir(dir)

    dir = os.path.join(dir, NAME)
    if not os.path.exists(dir):
        os.mkdir(dir)

    TEST_FILE = open(os.path.join(dir, NAME + ".sh"), "a")
    OUTPUT = open(os.path.join(dir, OUTPUT_FILE), "w")
    RESULT = open(os.path.join(dir, RESULT_FILE), "w")

    OUTPUT.close()
    RESULT.close()

    return TEST_FILE


def write_test(CAR: str, NAME: str, TEST_FILE, ARGS: str):
    HEADER = "##\n## EPITECH PROJECT, 2022\n## test\n## File description:\n## " + NAME + ".sh" + "\n##\n"
    FUNCTION = "test_" + NAME + " () {\n\tTEST=" + NAME + VARIABLE
    COLORS = open("./colors.txt")
    RETURN_VALUE = "\n## RETURN VALUES ##\nPASSED=1\nFAILED=0\nPROBLEM=-1\n"

    TEST_FILE.write(HEADER)
    TEST_FILE.write(COLORS.read())
    TEST_FILE.write(RETURN_VALUE)
    TEST_FILE.write("\n## TEST ##\n")
    TEST_FILE.write(FUNCTION)

    if ARGS != "":
        TEST_FILE.write("\t./${NAME} " + ARGS + " &> ${OUTPUT}\n")
    else:
        TEST_FILE.write("\t./${NAME} &> ${OUTPUT}\n")

    TEST_FILE.write(TEST)

    COLORS.close()


def create_test(CAT: str, NAME: str, ARGS: str):
    TEST_FILE = create_dir(CAT, NAME)

    write_test(CAT, NAME, TEST_FILE, ARGS)

    TEST_FILE.close()


def start_creation():
    print(Fore.BLUE + "\n\n\t\tCRÉATION D'UN TEST FUNCTIONAL\n\n")
    print(Fore.RESET)

    CAT = input("Quelle est la catégorie du test ?\n")
    NAME = input("\nQuel est le nom du test ?\n")
    ARGS = input("\nAvec quel(s) argument(s) voulez-vous executer votre programme ? ('entrer' pour pas d'argument)\n")

    print("La catégorie est:")
    print(Fore.CYAN + "\"%s\"\n" % CAT)
    print(Fore.RESET + "Et le nom est:")
    print(Fore.CYAN + "\"%s\"" % NAME)
    print(Fore.RESET)

    print("Et vous souhaitez executer votre programme: ")
    if ARGS == "":
        print(Fore.CYAN + "sans arguments")
    else:
        print(Fore.CYAN + "\"%s\"" % ARGS)
    print(Fore.RESET)

    response = input("\nEst-ce exacte ? y/n\n")

    if response == "y":
        create_test(CAT, NAME, ARGS)
        print(Fore.GREEN + "\n\n\t\tTEST CRÉER !")
    else:
        print(Fore.YELLOW + "\n\n\t\tARRÊT DE LA CRÉATION DU TEST")
        exit(1)



try:

    if len(sys.argv) == 2:
        if sys.argv[1] == "-h" or sys.argv[1] == "--helper":
            print(HELPER)
        else:
            print(Fore.RED + "Wrong argument, retry with the '-h' or '--helper'")
            raise IndexError
    elif len(sys.argv) == 1:
        start_creation()
    else:
        print(Fore.RED + "Too much arguments, retry with the '-h' or '--helper'")

except (IndexError):
    exit(84)
