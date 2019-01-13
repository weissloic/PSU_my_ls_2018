/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/my.h"

int my_ls_basic(int ac, char **av, func_char_t *func_char_t)
{
    int i = 0;
    int k = 0;

    while (i != func_char_t->nb_folder) {
        my_printf("%s:\n", func_char_t->stock_my_folder[i]);
        my_open_file(ac, av, func_char_t, i);
        open_function_ls(ac, av, func_char_t, k);
        if (i < (func_char_t->nb_folder) - 1)
            my_printf("\n\n");
        else
            my_printf("\n");
        i++;
    }
    return (0);
}

int my_ls_basic_twoav(int ac, char **av, func_char_t *func_char_t)
{
    int i = 0;
    int k = 0;

    while (i != func_char_t->nb_folder) {
        my_open_file(ac, av, func_char_t, i);
        open_function_ls(ac, av, func_char_t, k);
        if (i < (func_char_t->nb_folder) - 1)
            my_printf("\n\n");
        else
            my_printf("\n");
        i++;
    }
    return (0);
}

int my_ls_basic_oneav(int ac, char **av, func_char_t *func_char_t)
{
    int i = 0;
    int k = 0;

    my_open_file_basic(ac, av, func_char_t);
    open_function_ls(ac, av, func_char_t, k);
    if (i < (func_char_t->nb_folder) - 1)
        my_printf("\n\n");
    else
        my_printf("\n");
    return (0);
}

int my_open_file_basic(int ac, char **av, func_char_t *func_char_t)
{
    char *current_directory = "./";
    func_char_t->dir = opendir(current_directory);
    if (func_char_t->dir != NULL) {
        while ((func_char_t->ent = readdir (func_char_t->dir)) != NULL) {
            my_open_file_basic_complete(ac, av, func_char_t);
        }
    }
}

void my_open_file_basic_complete(int ac, char **av, func_char_t *func_char_t)
{
    if (func_char_t->ent->d_name[0] != '.' &&
        func_char_t->ent->d_name[my_strlen(func_char_t->ent->d_name) - 1]
        != '~'){
        my_strcpy(func_char_t->NameArr[func_char_t->nb_files]
            , func_char_t->ent->d_name);
        my_strcat(func_char_t->NamePath
            , func_char_t->NameArr[func_char_t->nb_files]);
        stat(func_char_t->NamePath, &func_char_t->buf);
        func_char_t->blocks_size += func_char_t->buf.st_blocks;
        func_char_t->nb_files++;
    }
}