/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "getnextline.h"

int my_ls_basic_hidden(int ac, char **av, func_char_t *func_char_t)
{
    int i = 0;
    int k = 0;

    my_open_file_hidden(ac, av, func_char_t);
    my_strcpy(func_char_t->NamePath, av[1]);

    for (k=0;k < func_char_t->nb_files && k < 1000;k++) {
        if (k < (func_char_t->nb_files) - 1)
            printf("%s  ",func_char_t->NameArr[k]);
        else 
            printf("%s",func_char_t->NameArr[k]);
    }
    return 0;
}

int my_open_file_hidden(int ac, char **av, func_char_t *func_char_t)
{
    func_char_t->dir = opendir(av[1]);
    if (func_char_t->dir != NULL) {
        while ((func_char_t->ent = readdir (func_char_t->dir)) != NULL) {
            my_strcpy(func_char_t->NameArr[func_char_t->nb_files], func_char_t->ent->d_name);
            my_strcat(func_char_t->NamePath, func_char_t->NameArr[func_char_t->nb_files]);
            stat(func_char_t->NamePath, &func_char_t->buf);
            my_strcpy(func_char_t->NamePath, av[1]);
            func_char_t->blocks_size += func_char_t->buf.st_blocks;
            func_char_t->nb_files++;
        }
    }
}