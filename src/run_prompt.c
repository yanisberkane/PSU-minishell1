/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-1-minishell1-yanis.berkane
** File description:
** run_prompt
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

void run_execve(char *pathed_cmd, char **args, char **env)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid != 0) {
        wait(&status);
    } else {
        if (execve(pathed_cmd, args, env) == -1) {
            my_putstr_err(args[0]);
            my_putstr_err(": Command not found.\n");
            exit(2);
        }
        exit(0);
    }
}

void get_command_context(command_infos *cmd, char **env)
{
    char **args = my_str_to_word_array(cmd->str);
    char *bin_path = NULL;

    if (check_command(args, env) == 7) {
        bin_path = put_path_in_context(env, args[0]);
        run_execve(bin_path, args, env);
    }
    return;
}

void check_signal(int signal)
{
    if (signal == SIGINT)
        my_putstr("\n$> ");
    return;
}

int run_prompt(char **envp)
{
    size_t end_ind = 0;
    command_infos cmd;
    char *brute_str = NULL;
    size_t exit_prompt = -1;
    char **env = envp;
    while (end_ind != exit_prompt) {
        signal(SIGINT, check_signal);
        if (isatty(0) == 1)
            my_putstr("$> ");
        end_ind = getline(&brute_str, &cmd.len, stdin);
        if (end_ind == exit_prompt)
            break;
        if (brute_str != NULL) {
            cmd.str = strtok(brute_str, "\n");
            get_command_context(&cmd, env);
        }
    }
    if (isatty(0) == 1)
        my_putstr("exit\n");
    return SUCCESS;
}
