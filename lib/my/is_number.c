/*
** EPITECH PROJECT, 2021
** is_number
** File description:
** returns 0 if all of str is a digit, 1 if it's not
*/

int my_strlen(char const *str);

int is_number(char *nb)
{
    for (int i = 0; i < my_strlen(nb); i++) {
        if ((nb[i] < '0' || nb[i] > '9') && nb[i] != '-' && nb[i] != '.') {
            return 1;
        }
    }
    return 0;
}
