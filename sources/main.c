/*
** EPITECH PROJECT, 2022
** sources
** File description:
** main.c
*/

#include <stdlib.h>
#include "my.h"

#define GENERATE_GRID system("python3 sudoku.py > sudoku.txt");
#define OPEN_GRID sudoku_file = fopen("sudoku.txt", "r");
#define GRID_SIZE 9 * 9

int main(int argc, char **argv)
{
//     FILE *sudoku_file = NULL;
//     char sudoku_grid[GRID_SIZE];

//     GENERATE_GRID
//     OPEN_GRID
//     fread(&sudoku_grid[0], sizeof(char), GRID_SIZE, sudoku_file);
//     fclose(sudoku_file);    char **array = malloc(sizeof(char *) * 3);

    return (0);
}
