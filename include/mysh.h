/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** minishell header file
*/

#include <stdio.h>

#ifndef MYSH_H
    #define MYSH_H

    #define ERROR 84
    #define SUCCESS 0
    #define USER_GUIDE "WELCOME TO $SH, A PERSONNALIZED SHELL!\n\
    You can use this TCSH-like command prompt in order to run commands and\n\
    access directories.\n\
        USAGE   ./mysh\n\
            $> -COMMAND LINE-\n\
        (To exit the prompt, simply type -exit- or press CTRL+D).\n\
ENJOY!\n"

    typedef struct inputs_infos {
        char *str;
        size_t len;
    } command_infos;

int run_prompt(char **env);
int check_command(char **args, char **env);
char *put_path_in_context(char **env, char *cmd);
char **get_paths_array(char *path);
int check_directory(char *path, char **env);
char **my_str_narraydup(char *const *array, int lines, int cols);

#endif
