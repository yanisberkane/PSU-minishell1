/*
** EPITECH PROJECT, 2021
** My Libraries
** File description:
** my_str_islower.c
*/

int my_str_islower(char const *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            return 1;
    }
    return 0;
}
