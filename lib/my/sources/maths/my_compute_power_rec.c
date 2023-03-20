/*
** EPITECH PROJECT, 2022
** Project
** File description:
** my_compute_power_rec.c
*/

#include "../../../../include/my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    return (nb * my_compute_power_rec(nb, p - 1));
}
