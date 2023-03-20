/*
** EPITECH PROJECT, 2022
** Template
** File description:
** test_my_strlen.c
*/

#include <criterion/criterion.h>
#include "my.h"

Test (my_swap_nbr, basic) {
    ssize_t nbr1 = 42;
    ssize_t nbr2 = 84;
    my_swap_nbr(&nbr1, &nbr2);
    cr_assert_eq(nbr1, 84);
    cr_assert_eq(nbr2, 42);
}

Test (my_swap_str, basic) {
    char *str1 = my_strdup("Hello");
    char *str2 = my_strdup("Salut");
    my_swap_str(str1, str2);
    cr_assert_str_eq(str1, "Salut");
    cr_assert_str_eq(str2, "Hello");
    free(str1);
    free(str2);
}
