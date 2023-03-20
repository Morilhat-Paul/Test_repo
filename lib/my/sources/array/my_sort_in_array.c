/*
** EPITECH PROJECT, 2022
** Project
** File description:
** my_sort_int_array.c
*/

#include "../../../../include/my.h"

void my_sort_in_array_str(char **array)
{
    size_t nbr = 0;

    for (size_t i = 0; array[i + 1] != NULL; i++)
        if (my_strcmp(array[i], array[i + 1]) == 1) {
            nbr++;
            my_putstr(array[i]);
            my_putchar('\t');
            my_putstr(array[i + 1]);
            my_putchar('\n');
            my_putstr("\nSWAP:\n");
            my_swap_str(&array[i], &array[i + 1]);
            my_putstr(array[i]);
            my_putchar('\t');
            my_putstr(array[i + 1]);
            my_putstr("\n\n");
        }
    if (nbr > 0)
        my_sort_in_array_str(array);
}

void my_sort_in_array_nbr(ssize_t *array, size_t size)
{
    size_t nbr = 0;

    for (size_t i = 0; i < size - 1; i++)
        if (array[i] > array[i + 1]) {
            nbr++;
            my_swap_nbr(&array[i], &array[i + 1]);
        }
    if (nbr > 0)
        my_sort_in_array_nbr(array, size);
}

void my_sort_in_array(void **array, int type)
{
    if (type == STR_ARRAY)
        my_sort_in_array_str((char **) array);
    // if (type == NBR_ARRAY)
    //     my_sort_in_array_nbr((ssize_t **) array);
}
