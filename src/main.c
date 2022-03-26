/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-1-minishell1-yanis.berkane
** File description:
** main
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char **argv, char **envp)
{
    int checker = 0;
    char **environement = envp;

    if (argc != 1) {
        if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
            my_putstr(USER_GUIDE);
            return SUCCESS;
        }
        return ERROR;
    }
    checker = run_prompt(environement);
    return checker;
}
