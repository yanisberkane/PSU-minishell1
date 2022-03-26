/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** Copies a string into another.
*/

int my_strlen(const char *str);

char *my_strcpy(char *dest, char const *src)
{
    int i;

    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i++] = '\0';
    return (dest);
}
