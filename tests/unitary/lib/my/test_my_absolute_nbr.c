/*
** EPITECH PROJECT, 2022
** Template
** File description:
** test_my_strlen.c
*/

#include <criterion/criterion.h>
#include "my.h"

Test (my_absolute_nbr, positive_nbr) {
    cr_assert_eq(my_absolute_nbr(50), 50);
}

Test (my_absolute_nbr, negative_nbr) {
    cr_assert_eq(my_absolute_nbr(-50), 50);
}
