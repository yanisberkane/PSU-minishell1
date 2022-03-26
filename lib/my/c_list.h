/*
** EPITECH PROJECT, 2021
** My Libraries
** File description:
** c_list.h
*/

#ifndef LIST_H
    #define LIST_H

    typedef struct elem t_elem;
    struct elem {
        int nb;
        t_elem *next;
    };

    typedef struct list t_list;
    struct list {
        t_elem *first;
    };

t_list *init_list(void);
void insert_list(t_list *list, int nbr);

#endif
