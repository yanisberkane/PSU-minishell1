/*
** EPITECH PROJECT, 2021
** cipher
** File description:
** get_matrix.c
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/my_matrix.h"

int get_mat_lines(int nb, int col)
{
    if (nb % col != 0)
        return (nb / col + 1);
    return (nb / col);
}

matrix get_n_matrix(char *str, int col)
{
    matrix mat;
    int len = my_strlen(str);
    int ind = 0;
    int col_pos = 0;

    mat.cols = col;
    mat.lines = get_mat_lines(len, col);
    mat.table = malloc(sizeof(int *) * mat.lines);
    for (int a = 0; a < mat.lines; a++) {
        mat.table[a] = malloc(sizeof(int) * mat.cols);
        for (col_pos = 0; col_pos < mat.cols && ind < len; col_pos++) {
            mat.table[a][col_pos] = str[ind];
            ind++;
        }
    }
    for (int p = col_pos; p < mat.cols; p++) {
        mat.table[mat.lines - 1][p] = 0;
    }
    return mat;
}
