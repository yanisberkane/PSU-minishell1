/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** Dupplicates a string into a new allocated str
*/

#include <stdlib.h>
#include <unistd.h>

int my_strlen(char const *str);

int count_strs(char *const *array)
{
    int co = 0;

    for (int i = 0; array[i] != 0; i++) {
        co = co + 1;
    }
    return co;
}

char **my_str_arraydup(char *const *array)
{
    int count = count_strs(array);
    char **c_array = malloc(sizeof(char *) * (count + 1));

    if (c_array == NULL)
        return NULL;
    for (int i = 0; array[i] != NULL; i++) {
        c_array[i] = malloc(sizeof(char) * (my_strlen(array[i]) + 1));
        for (int j = 0; array[i][j] != '\0'; j++)
            c_array[i][j] = array[i][j];
        c_array[i][my_strlen(array[i])] = '\0';
    }
    c_array[count] = NULL;
    return c_array;
}
