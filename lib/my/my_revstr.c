/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** reverses a string.
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    char c;
    int i;
    int j;

    j = my_strlen(str);
    i = 0;
    while (i < (j / 2)) {
        c = str[i];
        str[i] = str[j - i - 1];
        str[j - i - 1] = c;
        i++;
    }
    return str;
}
