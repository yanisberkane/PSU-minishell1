/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** divides a string into words
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int my_is_two_pts(char c)
{
    if (c == ':')
        return 1;
    return 0;
}

int count_paths_in_str(char *str)
{
    int nb = 0;
    int path_length = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (my_is_two_pts(str[i]) == 0)
            path_length++;
        if (my_is_two_pts(str[i]) && my_is_two_pts(str[i - 1]) == 0 && i > 0) {
            nb++;
            path_length = 0;
        }
    }
    if (path_length > 0)
        nb++;
    return (nb);
}

void get_pathlen(int *paths_lens, char *str, int nb_paths)
{
    int length = 0;
    int index = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (index == nb_paths)
            break;
        if (my_is_two_pts(str[i]) == 0)
            length++;
        if (my_is_two_pts(str[i]) && i > 0 && my_is_two_pts(str[i - 1]) == 0) {
            paths_lens[index] = length;
            index++;
            length = 0;
        }
    }
    if (length > 0)
        paths_lens[index++] = length;
}

int check_many_two_points(char *str, int ind)
{
    while (my_is_two_pts(str[ind]))
        ind++;
    return ind;
}

char **get_paths_array(char *path)
{
    char *str = path + 5;
    int nb_paths = count_paths_in_str(str);
    char **array = malloc(sizeof(char *) * (nb_paths + 1));
    int paths_len[nb_paths];
    int ind = 0;

    if (array == NULL)
        return NULL;
    get_pathlen(paths_len, str, nb_paths);
    for (int i = 0; i < nb_paths; i++) {
        array[i] = malloc(sizeof(char) * (paths_len[i] + 1));
        for (int j = 0; j < paths_len[i]; j++) {
            ind = check_many_two_points(str, ind);
            array[i][j] = str[ind];
            ind++;
        }
        array[i][paths_len[i]] = '\0';
    }
    array[nb_paths] = NULL;
    return array;
}
