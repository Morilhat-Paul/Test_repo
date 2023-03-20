/*
** EPITECH PROJECT, 2022
** Project
** File description:
** my_addchar.c
*/


#include "../../../../include/my.h"

char * my_addchar(char *str, char c, int position)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = 0;

    result[my_strlen(str)] = c;
    for (; str[i] != '\0'; i++)
        result[i] = str[i];
    result[my_strlen(str) + 1] = '\0';
    return (result);
}
