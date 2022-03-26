/*
** EPITECH PROJECT, 2021
** my_put_uns_nbr
** File description:
** Return an entred unsigned nbr
*/

void my_putchar(char c);

unsigned int my_put_uns_nbr(unsigned int nb);

unsigned int put_high_uns_nbr(unsigned int nb)
{
    int div;
    int mod;

    div = nb / 10;
    my_put_uns_nbr(div);
    mod = nb % 10;
    my_put_uns_nbr(mod);
    return 0;
}

unsigned int my_put_uns_nbr(unsigned int nb)
{
    if (nb < 10) {
        my_putchar(nb + '0');
        return 0;
    } else {
        put_high_uns_nbr(nb);
        return 0;
    }
    return 0;
}
