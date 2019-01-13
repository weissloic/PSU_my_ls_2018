/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/my.h"

int main(int ac, char **av)
{
    func_char_t *func_char_t = malloc(sizeof(func_char_t) * 1000);
    int i = 0;
    func_char_t->number = 0;

    my_struct(func_char_t);
    cat_my_path(func_char_t, ac, av);
    if (ac == 1) {
        my_ls_basic_oneav(ac, av, func_char_t);
        return (0);
    }
    for (i = 0; i != ac; i++)
        my_condition(func_char_t, ac, av, i);
    if (func_char_t->number == 0)
        my_ls_basic_twoav(ac, av, func_char_t);
    return (0);
}

void my_condition(func_char_t *func_char_t, int ac, char **av, int i)
{

        if (my_strcmp(av[i],"-l") == 0 && ac == 3) {
            func_char_t->number++;
            my_ls_lone_flag(ac, av, func_char_t);
        }
        else if (my_strcmp(av[i],"-l") == 0) {
            func_char_t->number++;
            my_ls_l_flag(ac, av, func_char_t);
        }
        else if (my_strcmp(av[i],"-a") == 0) {
            func_char_t->number++;
            my_ls_hidden(ac, av, func_char_t);

        }
        else if (my_strcmp(av[i],"-la") == 0) {
            func_char_t->number++;
            my_ls_la_flag(ac, av, func_char_t);

        }
}


void cat_my_path(func_char_t *func_char_t, int ac, char **av)
{
        char adding[] = "/";
        int e = 1;

    while (e != ac) {
        if (av[e][0] != '-' && av[e][0] != '\0') {
            func_char_t->stock_my_folder[func_char_t->nb_folder] = av[e];
            func_char_t->nb_folder++;
        }
        e++;
    }
        for (int pol = 0; pol < func_char_t->nb_folder; pol++)
            my_strcpy(func_char_t->stock_folder[pol], func_char_t->stock_my_folder[pol]);

        for (int test = 0; test < func_char_t->nb_folder; test++)
            my_strcat(func_char_t->stock_folder[test], adding);
}

int my_open_file(int ac, char **av, func_char_t *func_char_t, int i)
{
    func_char_t->nb_files = 0;
    func_char_t->blocks_size = 0;
    func_char_t->dir = opendir(func_char_t->stock_folder[i]);

    if (func_char_t->dir != NULL) {
        while ((func_char_t->ent = readdir (func_char_t->dir)) != NULL) {
            my_open_file_complete(ac, av, func_char_t, i);
        }
    }
}

void my_open_file_complete(int ac, char **av, func_char_t *func_char_t, int i)
{
    if (func_char_t->ent->d_name[0] != '.' && func_char_t->ent->d_name[strlen(func_char_t->ent->d_name) - 1] != '~'){
        my_strcpy(func_char_t->NameArr[func_char_t->nb_files], func_char_t->ent->d_name);
        my_strcat(func_char_t->NamePath, func_char_t->NameArr[func_char_t->nb_files]);
        stat(func_char_t->NamePath, &func_char_t->buf);
        my_strcpy(func_char_t->NamePath, func_char_t->stock_folder[i]);
        func_char_t->blocks_size += func_char_t->buf.st_blocks;
        func_char_t->nb_files++;
    }
}

int my_ls_la_flag(int ac, char **av, func_char_t *func_char_t)
{
    int k = 0;
    int i = 0;
    
    while (i != func_char_t->nb_folder) {
        my_open_file_hidden(ac, av, func_char_t, i);
        my_strcpy(func_char_t->NamePath, func_char_t->stock_folder[i]);
        my_printf("%s:\n", func_char_t->stock_my_folder[i]);
        my_printf("total %d\n", func_char_t->blocks_size / 2);
        for (k=0;k < func_char_t->nb_files;k++) {
            print_l(func_char_t, k, i);
        }
    if (i < (func_char_t->nb_folder) - 1)
        my_printf("\n");
    i++;
    }
    return (0);
}

int my_ls_l_flag(int ac, char **av, func_char_t *func_char_t)
{
    int k = 0;
    int i = 0;
    
    while (i != func_char_t->nb_folder) {
        my_open_file(ac, av, func_char_t, i);
        my_strcpy(func_char_t->NamePath, func_char_t->stock_folder[i]);


        my_printf("%s:\n", func_char_t->stock_my_folder[i]);
        my_printf("total %d\n", func_char_t->blocks_size / 2);

        for (k=0;k < func_char_t->nb_files;k++) {
            print_l(func_char_t, k, i);
        }
    if (i < (func_char_t->nb_folder) - 1)
        my_printf("\n");
    i++;
    }
    return (0);
}

int my_ls_lone_flag(int ac, char **av, func_char_t *func_char_t)
{
    int k = 0;
    int i = 0;
    
    while (i != func_char_t->nb_folder) {
        my_open_file(ac, av, func_char_t, i);
        my_strcpy(func_char_t->NamePath, func_char_t->stock_folder[i]);

        my_printf("total %d\n", func_char_t->blocks_size / 2);

        for (k=0;k < func_char_t->nb_files;k++) {
            print_l(func_char_t, k, i);
        }
    if (i < (func_char_t->nb_folder) - 1)
        my_printf("\n");
    i++;
    }
    return (0);
}

void print_l(func_char_t *func_char_t, int k, int i)
{
    my_strcat(func_char_t->NamePath, func_char_t->NameArr[k]);
    stat(func_char_t->NamePath, &func_char_t->buf);
    my_strcpy(func_char_t->NamePath, func_char_t->stock_folder[i]);
    print_my_stick_bit(func_char_t->buf);
    my_printf(". %d", func_char_t->buf.st_nlink);
    print_my_guid(func_char_t->buf);
    my_printf("%d ",func_char_t->buf.st_size);
    my_strcpy(func_char_t->stockdate[k], 4 +ctime(&func_char_t->buf.st_mtime));
    my_strncpy(func_char_t->changedate[k], func_char_t->stockdate[k], strlen(func_char_t->stockdate[k]) - 9);
    my_strncpy(func_char_t->date_final[k], func_char_t->changedate[k], strlen(func_char_t->changedate[k]));
    my_printf("%s", func_char_t->date_final[k]);
    my_printf(" %s\n", func_char_t->NameArr[k]);
}