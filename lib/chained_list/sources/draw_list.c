/*
** EPITECH PROJECT, 2022
** Project
** File description:
** draw_list.c
*/

#include "../../../include/my.h"

void draw_list(element_t **list, void (*pf)(void *))
{
    int i = 0;
    if (*list == NULL) {
        my_putstr("The list is empty\n");
        return;
    }
    for (element_t *it = *list; it != NULL; it = it->next, i++) {
        (*pf)(it->data);
        my_putchar('\n');
    }
    my_putchar('\n');
}
