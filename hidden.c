/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/my.h"

int my_ls_hidden(int ac, char **av, func_char_t *func_char_t)
{
    int i = 0;
    int k = 0;

    while (i != func_char_t->nb_folder) {
        my_open_file_hidden(ac, av, func_char_t, i);
        open_function_ls(ac, av, func_char_t, k);
        if (i < (func_char_t->nb_folder) - 1)
            my_printf("\n\n");
        else
            my_printf("\n");
        i++;
    }
    return 0;
}

int my_open_file_hidden(int ac, char **av, func_char_t *func_char_t, int i)
{
    func_char_t->nb_files = 0;
    func_char_t->blocks_size = 0;
    func_char_t->dir = opendir(func_char_t->stock_folder[i]);

    if (func_char_t->dir != NULL) {
        while ((func_char_t->ent = readdir (func_char_t->dir)) != NULL) {
            open_file_hidden_complete(ac, av, func_char_t, i);
        }
    }
}

void open_file_hidden_complete(int ac, char **av,
    func_char_t *func_char_t, int i)
{
    my_strcpy(func_char_t->NameArr[func_char_t->nb_files]
        , func_char_t->ent->d_name);
    my_strcat(func_char_t->NamePath
        , func_char_t->NameArr[func_char_t->nb_files]);
    stat(func_char_t->NamePath, &func_char_t->buf);
    my_strcpy(func_char_t->NamePath, func_char_t->stock_folder[i]);
    func_char_t->blocks_size += func_char_t->buf.st_blocks;
    func_char_t->nb_files++;
}

void open_function_ls(int ac, char **av, func_char_t *func_char_t, int k)
{
    for (k = 0;k < func_char_t->nb_files;k++) {
        if (k < (func_char_t->nb_files) - 1)
            my_printf("%s  ", func_char_t->NameArr[k]);
        else
            my_printf("%s", func_char_t->NameArr[k]);
        }
}