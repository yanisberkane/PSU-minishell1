/*
** EPITECH PROJECT, 2021
** put_base_nbr
** File description:
** Displays the base conversion of an int
*/

void my_putchar(char c);

int put_base_nbr(unsigned int nb, unsigned int base, int ad, int uol);

int my_putstr(char const *str);

char conv_dec_to_up_hex(int res)
{
    switch (res) {
    case 10:
        return 'A';
    case 11:
        return 'B';
    case 12:
        return 'C';
    case 13:
        return 'D';
    case 14:
        return 'E';
    case 15:
        return 'F';
    }
    return 0;
}

char conv_dec_to_low_hex(int res)
{
    switch (res) {
    case 10:
        return 'a';
    case 11:
        return 'b';
    case 12:
        return 'c';
    case 13:
        return 'd';
    case 14:
        return 'e';
    case 15:
        return 'f';
    }
    return 0;
}

int put_high_base_nbr(unsigned int nb, unsigned int base, int uol)
{
    int div;
    int mod;

    div = nb / base;
    put_base_nbr(div, base, 0, uol);
    mod = nb % base;
    put_base_nbr(mod, base, 0, uol);
    return 0;
}

int put_base_nbr(unsigned int nb, unsigned int base, int ad, int uol)
{
    if (ad)
        my_putstr("0x");
    if (nb < base) {
        if (nb > 9 && uol == 1) {
            my_putchar(conv_dec_to_up_hex(nb));
            return 0;
        }
        if (nb > 9 && uol == 0) {
            my_putchar(conv_dec_to_low_hex(nb));
            return 0;
        }
        my_putchar(nb + '0');
        return 0;
    } else {
        put_high_base_nbr(nb, base, uol);
        return 0;
    }
    return 0;
}
