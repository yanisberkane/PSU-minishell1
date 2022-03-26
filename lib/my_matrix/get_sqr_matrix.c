/*
** EPITECH PROJECT, 2021
** My mathematics library
** File description:
** get_sqr_matrix.c
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/my_matrix.h"

int get_sqr_cols(int len)
{
    int col = my_compute_square_root(len);
    float fcol = my_compute_square_root(len);

    if (col != fcol)
        return col + 1;
    return col;
}

matrix get_sqr_matrix(char *str)
{
    matrix mtx;
    int len = my_strlen(str);
    int col_pos = 0;
    int ind = 0;

    mtx.lines = get_sqr_cols(len);
    mtx.cols = get_sqr_cols(len);
    mtx.table = malloc(sizeof(int *) * mtx.lines);
    for (int a = 0; a < mtx.lines; a++) {
        mtx.table[a] = malloc(sizeof(int) * mtx.cols);
        for (col_pos = 0; col_pos < mtx.cols && ind < len; col_pos++) {
            mtx.table[a][col_pos] = str[ind];
            ind++;
        }
    }
    for (int p = col_pos; p < mtx.cols; p++) {
        mtx.table[mtx.lines - 1][p] = 0;
    }
    return mtx;
}
