/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** Turns lower case into upper case
*/

int my_strlen(char *str);

char *my_strlowcase(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return str;
}
