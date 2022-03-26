/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-1-minishell1-yanis.berkane
** File description:
** check_directory
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
#include <dirent.h>
#include <fcntl.h>

char *get_pwd_path(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp("PWD=", env[i], 4) == 0)
            return env[i];
    }
    return 0;
}

char *get_home_path(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp("HOME=", env[i], 5) == 0)
            return env[i];
    }
    return 0;
}

int check_cd_errors(char *path)
{
    if (opendir(path) == NULL && open(path, O_RDONLY) != -1) {
        my_putstr_err(path);
        my_putstr_err(": Not a directory.\n");
        return 0;
    }
    if (!chdir(path) == 0) {
        my_putstr_err(path);
        my_putstr_err(": No such file or directory.\n");
        return 0;
    }
    return 0;
}

int check_directory(char *path, char **env)
{
    char *arg_path = NULL;

    if (path == NULL) {
        arg_path = get_home_path(env) + 5;
        chdir(arg_path);
        return 1;
    }
    if (my_strcmp(path, "~") == 0) {
        arg_path = get_home_path(env) + 5;
        chdir(arg_path);
        return 1;
    }
    if (my_strcmp(path, "-") == 0) {
        arg_path = get_pwd_path(env) + 4;
        my_printf("%s\n", arg_path);
        return 0;
    }
    return check_cd_errors(path);
}
