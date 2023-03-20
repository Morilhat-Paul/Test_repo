/*
** EPITECH PROJECT, 2022
** Project
** File description:
** my_addition.c
*/

#include "../../../../include/my.h"

static long int nbr = 1;

long int my_facto(long int x)
{
    if (x == 0 || x == 1)
        return (nbr);
    nbr = x * my_facto(x - 1);
    return (nbr);
}
