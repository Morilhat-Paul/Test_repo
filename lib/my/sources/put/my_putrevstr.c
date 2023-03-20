/*
** EPITECH PROJECT, 2022
** Project
** File description:
** my_revstr.c
*/

#include "../../../../include/my.h"

void my_putrevstr(char *str)
{
    for (int i = my_strlen(str) - 1; i >= 0; i--)
        my_putchar(str[i]);
}
