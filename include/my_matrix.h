/*
** EPITECH PROJECT, 2021
** Library
** File description:
** my_matrix
*/

#ifndef MATRIX_H
    #define MATRIX_H

    typedef struct fmat matrix;
    struct fmat {
        float **table;
        int lines;
        int cols;
    };

matrix get_sqr_matrix(char *str);
int get_sqr_cols(int len);
matrix get_n_matrix(char *str, int col);
int get_mat_lines(int nb, int col);

#endif
