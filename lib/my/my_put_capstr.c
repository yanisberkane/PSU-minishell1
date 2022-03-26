/*
** EPITECH PROJECT, 2021
** my_put_capstr
** File description:
** print string with non-printable chars managing
*/

#include <unistd.h>
#include <stdio.h>

void my_putchar(char c);

int my_putstr(char const *str);

int put_base_nbr(unsigned int nb, unsigned int base, int ad, int uol);

void put_zeros_before(int unascii)
{
    int div = unascii;
    int ct = 0;

    while (div != 0) {
        div = div / 10;
        ct++;
    }
    if (ct == 1)
        my_putstr("00");
    if (ct == 2)
        my_putchar('0');
    if (ct > 3)
        return;
}

int my_put_capstr(char const *str)
{
    char bs = 92;
    int unascii;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] == 127) {
            write(1, &bs, 1);
            unascii = str[i];
            put_zeros_before(unascii);
            put_base_nbr(unascii, 8, 0, 0);
            i++;
        }
        write(1, &str[i], 1);
    }
    return 0;
}
