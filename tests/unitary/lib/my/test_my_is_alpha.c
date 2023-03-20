/*
** EPITECH PROJECT, 2022
** Template
** File description:
** test_my_strlen.c
*/

#include <criterion/criterion.h>
#include "my.h"

Test (my_is_alpha, low_aplha) {
    cr_assert_eq(my_is_alpha('a'), true);
}

Test (my_is_alpha, up_aplha) {
    cr_assert_eq(my_is_alpha('A'), true);
}

Test (my_is_alpha, nbr) {
    cr_assert_eq(my_is_alpha('1'), true);
}

Test (my_is_alpha, false) {
    cr_assert_eq(my_is_alpha('\n'), false);
}
