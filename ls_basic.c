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
    printf("%s:\n", func_char_t->stock_my_folder[i]);
    my_open_file(ac, av, func_char_t, i);

    for (k=0;k < func_char_t->nb_files && k < 1000;k++) {
        if (k < (func_char_t->nb_files) - 1)
            my_printf("%s  ",func_char_t->NameArr[k]);
        else 
            printf("%s",func_char_t->NameArr[k]);
        }
        if (i < (func_char_t->nb_folder) - 1)
            printf("\n\n");
        else 
            printf("\n");
        i++;
    }
    return 0;
}

int my_ls_basic_twoav(int ac, char **av, func_char_t *func_char_t)
{
    int i = 0;
    int k = 0;

while (i != func_char_t->nb_folder) {
    my_open_file(ac, av, func_char_t, i);
    for (k=0;k < func_char_t->nb_files && k < 1000;k++) {
        if (k < (func_char_t->nb_files) - 1)
            printf("%s  ",func_char_t->NameArr[k]);
        else 
            printf("%s",func_char_t->NameArr[k]);
        }
        if (i < (func_char_t->nb_folder) - 1)
            printf("\n\n");
        else 
            printf("\n");
        i++;
    }
    return 0;
}

int my_ls_basic_oneav(int ac, char **av, func_char_t *func_char_t)
{
    int i = 0;
    int k = 0;

    my_open_file_basic(ac, av, func_char_t, i);

    for (k=0;k < func_char_t->nb_files && k < 1000;k++) {
        if (k < (func_char_t->nb_files) - 1)
            printf("%s  ",func_char_t->NameArr[k]);
        else 
            printf("%s",func_char_t->NameArr[k]);
        }
        if (i < (func_char_t->nb_folder) - 1)
            printf("\n\n");
        else 
            printf("\n");
    return 0;
}



int my_open_file_basic(int ac, char **av, func_char_t *func_char_t)
{
    char *current_directory = "./";
    func_char_t->dir = opendir(current_directory);
    if (func_char_t->dir != NULL) {
        while ((func_char_t->ent = readdir (func_char_t->dir)) != NULL) {
            if (func_char_t->ent->d_name[0] != '.' && func_char_t->ent->d_name[strlen(func_char_t->ent->d_name) - 1] != '~'){
                my_strcpy(func_char_t->NameArr[func_char_t->nb_files], func_char_t->ent->d_name);
                my_strcat(func_char_t->NamePath, func_char_t->NameArr[func_char_t->nb_files]);
                stat(func_char_t->NamePath, &func_char_t->buf);
                func_char_t->blocks_size += func_char_t->buf.st_blocks;
                func_char_t->nb_files++;
            }
        }
    }
}