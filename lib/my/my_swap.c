/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** Swaps the content of two integers.
*/

void my_swap(int *a, int *b)
{
    int ce = 0;

    ce = *a;
    *a = *b;
    *b = ce;
}
