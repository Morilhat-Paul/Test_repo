/*
** EPITECH PROJECT, 2022
** Project
** File description:
** my_negative_nb.c
*/

#include "../../../../include/my.h"

size_t my_absolute_nbr(ssize_t nb)
{
    if (nb < 0)
        return (nb * -1);
    return (nb);
}
