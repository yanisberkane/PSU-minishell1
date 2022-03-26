/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** My own printf function
*/

#include <stdarg.h>
#include <unistd.h>

int my_putstr(char const *str);

unsigned int my_put_uns_nbr(unsigned int nb);

int my_putchar(char c);

int put_base_nbr(unsigned int nb, unsigned int base, int ad, int uol);

int my_put_capstr(char const *str);

int my_isflag(char c)
{
    char flags [] = "sdiubcoSxXp";

    for (int j = 0; flags[j] != '\0'; j++) {
        if (c == flags[j]) {
            return 1;
        }
    }
    return 0;
}

int put_more_in_str(char *str, int i, va_list args)
{
    if (str[i + 1] == 's')
        return my_putstr(va_arg(args, char *));
    return 0;
}

int put_in_str(char *str, int i, va_list args)
{
    put_more_in_str(str, i, args);
    if (str[i + 1] == 'd' || str[i + 1] == 'i')
        return put_base_nbr(va_arg(args, unsigned int), 10, 0, 0);
    if (str[i + 1] == 'u')
        return my_put_uns_nbr(va_arg(args, unsigned int));
    if (str[i + 1] == 'b')
        return put_base_nbr(va_arg(args, unsigned int), 2, 0, 0);
    if (str[i + 1] == 'c' || str[i + 1] == 'C')
        return my_putchar(va_arg(args, int));
    if (str[i + 1] == 'o')
        return put_base_nbr(va_arg(args, unsigned int), 8, 0, 0);
    if (str[i + 1] == 'S')
        return my_put_capstr(va_arg(args, char *));
    if (str[i + 1] == 'x')
        return put_base_nbr(va_arg(args, unsigned int), 16, 0, 0);
    if (str[i + 1] == 'X')
        return put_base_nbr(va_arg(args, unsigned int), 16, 0, 1);
    if (str[i + 1] == 'p')
        return put_base_nbr(va_arg(args, unsigned int), 16, 1, 0);
    return 0;
}

void my_printf(char *str, ...)
{
    va_list args;

    va_start(args, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && my_isflag(str[i + 1])) {
            put_in_str(str, i, args);
            i++;
            continue;
        }
        if (str[i] == '%' && str[i + 1] == '%')
            i++;
        write(1, &str[i], 1);
    }
    va_end(args);
}
