/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-1-minishell1-yanis.berkane
** File description:
** check_command
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        my_printf("%s\n", env[i]);
    return 0;
}

int check_env_existance(char **env, char *arg)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(arg, env[i], my_strlen(arg)) == 0)
            return i;
    }
    return -1;
}

int set_env(char **envp, char **args)
{
    int coherence_in_env = 0;

    if (args[1] == NULL || args[2] == NULL)
        return print_env(envp);
    coherence_in_env = check_env_existance(envp, args[1]);
    if (coherence_in_env == -1) {
        return 0;
    } else if (my_strlen(args[1]) <= my_strlen(envp[coherence_in_env])) {
        for (int i = my_strlen(args[1]) + 2; i < my_strlen(args[2]); i++)
            envp[coherence_in_env][i] = args[2][i];
        args[2][my_strlen(args[2])] = '\0';
    }
    return 0;
}

int check_command(char **args, char **env)
{
    char **dup_env = my_str_arraydup(env);

    if (my_strcmp(args[0], "unsetenv") == 0) {
        dup_env = my_str_arraydup(env);
        return 0;
    }
    if (my_strcmp(args[0], "cd") == 0)
        return check_directory(args[1], env);
    if (my_strcmp(args[0], "env") == 0)
        return print_env(dup_env);
    if (my_strcmp(args[0], "setenv") == 0)
        return set_env(dup_env, args);
    if (my_strcmp(args[0], "exit") == 0)
        exit(0);
    return 7;
}
