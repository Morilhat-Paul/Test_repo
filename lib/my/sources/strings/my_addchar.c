/*
** EPITECH PROJECT, 2022
** Project
** File description:
** my_addchar.c
*/


#include "../../../../include/my.h"

#define WRONG_POSITION(position) \
    ("my_addchar: Wrong position."   \
    " The position of the char is not between 0"  \
    " and the length of the string.\n")

static bool error_handling(char *str, size_t position, char *result) {
    char *position_str = my_nbr_to_str(position);

    if ((position > my_strlen(str) + 1)) {
        my_perror(WRONG_POSITION());
        return (false);
    }

    if (result == NULL) {
        my_perror(MALLOC_ERROR("result"));
        return (false);
    }

    return (true);
}

char * my_addchar(char *str, char c, size_t position)
{
    size_t lenght = my_strlen(str);
    char *result = malloc(sizeof(char) * (lenght + 2));
    int j = 0;

    if (!error_handling(str, position, result))
        return (NULL);

    if (position == 0)
        position = lenght + 1;

    result[position - 1] = c;
    result[lenght + 1] = '\0';

    for (size_t i = 0; i < lenght; i++, j++) {
        if (i == position - 1)
            j++;
        result[j] = str[i];
    }

    return (result);
}
