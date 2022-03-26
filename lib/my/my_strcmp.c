/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** Comparaison between two str
*/

int my_strlen(char const *str);

int get_max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int my_strcmp(char const *s1 , char const *s2)
{
    int len = get_max(my_strlen(s1), my_strlen(s2));

    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return 0;
}
