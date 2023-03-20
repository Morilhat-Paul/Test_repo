/*
** EPITECH PROJECT, 2022
** sources
** File description:
** main.c
*/

#include "../include/project.h"

bool is_helper(char *arg)
{
    if ((arg[0] == '-') && (arg[1] == 'h') && (arg[2] == '\0'))
        return (true);
    return (false);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        if (is_helper(argv[1])) {
            my_putstr(HELPER);
            return (0);
        }
    return (0);
}
