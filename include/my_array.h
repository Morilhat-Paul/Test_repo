/*
** EPITECH PROJECT, 2022
** Template
** File description:
** my_array.h
*/

#ifndef MY_ARRAY_H_
    #define MY_ARRAY_H_

    // void my_sort_in_array_nbr(ssize_t *array, size_t size);
    // void my_sort_in_array(void **array, int type);
    // void my_sort_in_array_str(char **array);

    /**
    ** @brief Create an array
    ** @param n Number of rows in the array without the NULL row
    ** @param ... All the variable you want in the array
    ** @return Pointer to the first case
    ** of the first line of the array
    **/
    void ** my_create_array(size_t n, ...);

    /**
    ** @brief Destroy an array
    ** @param array Pointer to the first case of the array you want to destroy
    **/
    void my_destroy_array(void **array);

    /**
    ** @brief Print an array
    ** @param array Pointer to the first row of the array you want to print
    ** @param put_line Pointer to the function needed
    ** to print the row of the array
    ** @param separator The character that will
    ** separate the rows of the table,
    ** '\0' for no separator
    **/
    void my_putarray(void *array[], void(*put_line)(void *), char separator);

    /**
    ** @brief Print n rows of an array
    ** @param array Pointer to the first row of the array you want to print
    ** @param put_line Pointer to the function needed
    ** to print the row of the array
    ** @param separator The character that will separate the rows of the table
    ** @param n The number of rows you want to print
    **/
    void my_putnarray(void *array[], void(*put_line)(void *),
                                        char separator, int n);

    #define PUT_LINE_ERROR \
"my_putarray: The pointer to the funtcion 'put_line' is NULL\n"

    #define NONE_ALPHA_NUM_SEPARATOR    \
"my_putarray: The separator is not an alphanumeric character or '\0'\n"

#endif /* MY_ARRAY_H_ */