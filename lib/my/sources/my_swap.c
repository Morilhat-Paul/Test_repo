/*
** EPITECH PROJECT, 2022
** Project
** File description:
** my_swap.c
*/

#include "../../../include/my.h"

void my_swap_nbr(ssize_t *a, ssize_t *b)
{
    ssize_t temp = *a;
    *a = *b;
    *b = temp;
}
