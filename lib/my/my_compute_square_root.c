/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** returns square root of a nb.
*/

int my_compute_square_root(int nb)
{
    int sqr;
    int i;

    for (i = 1; i <= (nb / 2); i++) {
        if (i * i == nb) {
            sqr = i;
        }
    }
    return sqr;
}
