/*
** EPITECH PROJECT, 2022
** Template
** File description:
** my_create_array.c
*/

#include "../../../../include/my.h"

void ** my_create_array(size_t x, ...)
{
    va_list ptr;
    void **array = malloc(sizeof(void *) * (x + 1));
    va_start(ptr, x);

    for (size_t i = 0; i < x; i++)
        array[i] = va_arg(ptr, void *);
    array[x] = NULL;
    va_end(ptr);
    return (array);
}

void my_destroy_array(void **array)
{
    for (size_t i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
