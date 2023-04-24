/*
** EPITECH PROJECT, 2022
** Project
** File description:
** my_putnarray.c
*/

#include "../../../../include/my.h"

#define PUT_LINE_ERROR \
"my_putarray: The pointer to the funtcion 'put_line' is NULL\n"

#define NONE_ALPHA_NUM_SEPARATOR    \
"my_putarray: The separator is not an alphanumeric character or '\0'\n"


static bool error_handling(void **array,
                void(*put_line)(void *), char separator) {
    if (array == NULL)
        return (false);

    if (put_line == NULL) {
        my_perror(PUT_LINE_ERROR);
        return (false);
    }

    if ((separator != '\0') && (!IS_ALPHA_NUM(separator))) {
        my_perror(NONE_ALPHA_NUM_SEPARATOR);
        return (false);
    }

    return (true);
}

void my_putnarray(void *array[], void(*put_line)(void *), char separator, int n)
{
    if (!error_handling(array, put_line, separator))
        return;

    for (int i = 0; (array[i] != NULL) && (i < n); i++) {
        put_line(array[i]);
        if (separator != '\0')
            my_putchar(separator);
    }
}
