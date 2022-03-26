/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** Returns 1 if it's a prime nb. 0 if not
*/

int my_is_prime(int nb)
{
    int i;

    if (nb == 0 || nb == 1)
        return 0;
    for (i = 2; i < nb; i++) {
        if (nb % i == 0) {
            return 0;
        } else {
            return 1;
        }
    }
    return -1;
}
