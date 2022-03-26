/*
** EPITECH PROJECT, 2021
** my_str_isprintable
** File description:
** Checks if the string is printable in ASCII
*/

int my_strlen(char *str);

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] == 127)
            return 1;
    }
    return 0;
}
