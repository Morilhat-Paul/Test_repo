/*
** EPITECH PROJECT, 2022
** Project
** File description:
** my_strstr.c
*/

#include "../../../../include/my.h"

char * my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int temp = 0;

    while (str[i] != '\0') {
        if (to_find[temp - i] == '\0')
            return (&str[i]);
        if ((str[temp] == to_find[temp - i]) ) {
            temp++;
            continue;
        }
        i++;
        temp++;
    }
    return (NULL);
}