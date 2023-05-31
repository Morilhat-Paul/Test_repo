#!/bin/python3

import random

def generate_grid():
    grid = [[0] * 9 for _ in range(9)]

    def is_valid(row, col, num):
        # Vérifie si le chiffre num est valide pour la case (row, col)
        # Vérification de la ligne et de la colonne
        for i in range(9):
            if grid[row][i] == num or grid[i][col] == num:
                return False

        # Vérification du bloc 3x3
        start_row = (row // 3) * 3
        start_col = (col // 3) * 3
        for i in range(3):
            for j in range(3):
                if grid[start_row + i][start_col + j] == num:
                    return False

        return True

    def fill_grid(row, col):
        if row == 9:
            # La grille est complète
            return True

        if col == 9:
            # Déplacement à la ligne suivante
            return fill_grid(row + 1, 0)

        if grid[row][col] != 0:
            # Case déjà remplie, passer à la colonne suivante
            return fill_grid(row, col + 1)

        # Générer une liste de chiffres valides pour la case (row, col)
        valid_nums = [num for num in range(1, 10) if is_valid(row, col, num)]

        random.shuffle(valid_nums)

        for num in valid_nums:
            grid[row][col] = num
            if fill_grid(row, col + 1):
                return True

        # Aucun chiffre valide, revenir en arrière
        grid[row][col] = 0
        return False

    fill_grid(0, 0)
    return grid

def remove_digits(grid, num_digits):
    positions = [(row, col) for row in range(9) for col in range(9)]
    random.shuffle(positions)

    for pos in positions:
        row, col = pos
        if num_digits == 0:
            break
        if grid[row][col] != 0:
            grid[row][col] = 0
            num_digits -= 1

def print_grid(grid):
    for row in grid:
        print(' '.join(str(num) for num in row))

grid = generate_grid()
num_digits = 40
remove_digits(grid, num_digits)
print_grid(grid)
