/*
** EPITECH PROJECT, 2021
** my_h
** File description:
** Library header
*/

#ifndef MY_H
    #define MY_H

int my_putstr_err(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_compute_power_rec(int nb, int p);
char *isole_nbr_in_str(char const *str);
int my_strcmp(char const *s1 , char const *s2);
int my_strncmp(char const *s1 , char const *s2, int nb);
unsigned int my_put_uns_nbr(unsigned int nb);
int my_put_capstr(char const *str);
int put_base_nbr(unsigned int nb, unsigned int base, int ad, int uol);
void my_printf(char *str, ...);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char const *src, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
int my_str_isprintable(char const *str);
char **my_str_to_word_array(char *str);
char **my_str_arraydup(char *const *array);

#endif
