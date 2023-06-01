/*
** EPITECH PROJECT, 2022
** Template
** File description:
** is_helper.c
*/

#include "project.h"

bool is_helper(char *arg)
{
    if ((my_strcmp(arg, "-h") == 0) || (my_strcmp(arg, "--helper") == 0))
        return (true);
    return (false);
}
dkonczdk