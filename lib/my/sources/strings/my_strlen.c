/*
** EPITECH PROJECT, 2022
** Project
** File description:
** my_strlen.c
*/

#include "../../../../include/my.h"

size_t my_strlen(char const *str)
{
    size_t i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
