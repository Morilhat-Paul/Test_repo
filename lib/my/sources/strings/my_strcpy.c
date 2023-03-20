/*
** EPITECH PROJECT, 2022
** Project
** File description:
** my_strcpy.c
*/

#include "../../../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
