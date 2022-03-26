/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** divides a string into words
*/

#include <stdlib.h>
#include <unistd.h>

int my_strlen(char const *str);

int my_is_sep(char c)
{
    if (c == ' ' || c == '\t')
        return 1;
    return 0;
}

int count_words_in_str(char *str)
{
    int nb = 0;
    int word_length = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (my_is_sep(str[i]) == 0)
            word_length++;
        if (my_is_sep(str[i]) && my_is_sep(str[i - 1]) == 0 && i > 0) {
            nb++;
            word_length = 0;
        }
    }
    if (word_length > 0)
        nb++;
    return (nb);
}

void get_wordlen(int *words_lens, char *str, int nb_words)
{
    int length = 0;
    int index = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (index == nb_words)
            break;
        if (my_is_sep(str[i]) == 0)
            length++;
        if (my_is_sep(str[i]) && i > 0 && my_is_sep(str[i - 1]) == 0) {
            words_lens[index] = length;
            index++;
            length = 0;
        }
    }
    if (length > 0)
        words_lens[index++] = length;
}

int check_many_seps(char *str, int ind)
{
    while (my_is_sep(str[ind]))
        ind++;
    return ind;
}

char **my_str_to_word_array(char *str)
{
    int nb_words = count_words_in_str(str);
    char **array = malloc(sizeof(char *) * (nb_words + 1));
    int words_len[nb_words];
    int ind = 0;

    if (array == NULL || str == 0)
        return NULL;
    get_wordlen(words_len, str, nb_words);
    for (int i = 0; i < nb_words; i++) {
        array[i] = malloc(sizeof(char) * (words_len[i] + 1));
        for (int j = 0; j < words_len[i]; j++) {
            ind = check_many_seps(str, ind);
            array[i][j] = str[ind];
            ind++;
        }
        array[i][words_len[i]] = '\0';
    }
    array[nb_words] = NULL;
    return array;
}
