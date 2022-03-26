/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** Comparaison between two str
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1 , char const *s2, int nb)
{
    for (int i = 0; i < nb; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return 0;
}
