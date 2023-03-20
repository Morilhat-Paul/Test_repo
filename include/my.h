/*
** EPITECH PROJECT, 2022
** include
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include "my_struct.h"
    #include "my_chained_list.h"
    #include <math.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <sys/types.h>

    #define STR_ARRAY 0
    #define NBR_ARRAY 1

    /* All functions of my lib */

    char * my_addchar(char *str, char c, int position);
    int my_binary_to_decimal(char *binary);
    int my_compute_power_rec (int nb, int p);
    int my_compute_square_root(int nb);
    int my_find_prime_sup(int nb);
    size_t my_get_size_file(char const *file);
    size_t my_getnbr(char const *str);
    bool my_is_alpha(char letter);
    bool my_is_prime (int nb);
    bool my_isneg(int nbr);
    int my_nbrcmp(ssize_t nb1, ssize_t nb2);
    size_t my_absolute_nbr(ssize_t nb);
    void my_perror(char *str);
    void my_putarray(void *array[], int type);
    void my_putchar(char c);
    void my_putnarray(void *array[], size_t n, int type);
    void my_putnbr(ssize_t nb);
    void my_putrevstr(char *str);
    void my_putstr(char const *str);
    int my_read_file(const char *file, char **buffer);
    void my_revstr(char *str);
    void my_show_params(int ac, char const **av);
    void my_sort_in_array(void **array, int type);
    void my_sort_in_array_str(char **array);
    void my_sort_in_array_nbr(ssize_t *array, size_t size);
    char ** my_str_to_word_array (char *str);
    char * my_strcat(char *dest, char const *src);
    int my_strcmp(char const *str1, char const *str2);
    char * my_strcpy(char *dest, char const *src);
    char * my_strdup(char const *src);
    size_t my_strlen(char const *str);
    char * my_strncat(char *dest, char const *src, int nb);
    int my_strncmp(char const *s1, char const *s2, int n);
    char * my_strncpy(char *dest, char const *src, int n);
    char * my_strstr(char *str, char const *to_find);
    char * my_strupcase(char *str);
    void my_swap_nbr(ssize_t *a, ssize_t *b);
    ssize_t my_addition(int n, ...);
    ssize_t my_multiplication(int n, ...);
    long int my_facto(long int x);
    void ** my_create_array(size_t x, ...);
    void my_destroy_array(void **array);

#endif /* MY_H_ */
