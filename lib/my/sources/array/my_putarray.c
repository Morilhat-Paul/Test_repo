/*
** EPITECH PROJECT, 2022
** Project
** File description:
** my_putarray.c
*/

#include "../../../../include/my.h"

void my_putarray(void *array[], int type)
{
    if (type == NBR_ARRAY)
        for (int i = 0; array[i] != NULL; i++) {
            my_putnbr((ssize_t) array[i]);
            my_putchar('\n');
        }

    if (type == STR_ARRAY)
        for (int i = 0; array[i] != NULL; i++) {
            my_putstr((char *) array[i]);
            my_putchar('\n');
        }
}
