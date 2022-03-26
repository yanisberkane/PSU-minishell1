/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** strncat
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i;
    int j;

    i = my_strlen(dest);
    j = 0;
    while (j < nb) {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i++] = '\0';
    return dest;
}
