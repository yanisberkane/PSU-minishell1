/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-1-minishell1-yanis.berkane
** File description:
** check_bin_path.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

char *get_brute_path(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp("PATH=", env[i], 5) == 0)
            return env[i];
    }
    return 0;
}

char *put_path_in_context(char **env, char *cmd)
{
    char *brute_paths = get_brute_path(env);
    char **paths = get_paths_array(brute_paths);
    char *complete_path = NULL;
    struct stat infos;

    for (int i = 0; paths[i] != NULL; i++) {
        complete_path = malloc(my_strlen(paths[i]) + my_strlen(cmd) + 2);
        my_strcpy(complete_path, paths[i]);
        complete_path[my_strlen(paths[i])] = '/';
        complete_path[my_strlen(paths[i]) + 1] = '\0';
        complete_path = my_strcat(complete_path, cmd);
        if (stat(complete_path, &infos) != -1)
            return complete_path;
        free(complete_path);
    }
    return cmd;
}
