/*
** EPITECH PROJECT, 2022
** Project
** File description:
** my_putnarray.c
*/

#include "../../../../include/my.h"

void my_putnarray(void *array[], size_t n, int type)
{
    if (n <= 0)
        return;

    if (type == 0)
        for (size_t i = 0; i < n; i++)
            my_putnbr((ssize_t) array[i]);

    if (type == 1)
        for (size_t i = 0; i < n; i++)
            my_putstr(array[i]);
}
