/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** get_list
*/

#include "../../include/c_list.h"
#include "../../include/my.h"
#include <unistd.h>
#include <stdlib.h>

void insert_list(t_list *list, int nbr)
{
    t_elem *n_elem = malloc(sizeof(*n_elem));

    if (list == NULL || n_elem == NULL)
        return;
    n_elem->nb = nbr;
    n_elem->next = list->first;
    list->first = n_elem;
}

t_list *init_list(void)
{
    t_list *list = malloc(sizeof(*list));
    t_elem *elem = malloc(sizeof(*elem));

    if (list == NULL || elem == NULL)
        return 0;
    elem->nb = 0;
    elem->next = NULL;
    list->first = elem;
    return list;
}
