/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "getnextline.h"

//char *my_strcat(char *dest, char const *src);


int main(int ac, char **av)
{
    int i = 0;
    int j = 0;
    int e = 1;
    int stock = 0;

    func_char_t *func_char_t = malloc(sizeof(func_char_t) * 1000);
    my_struct(func_char_t);

    while (e != ac) {
        if (av[e][0] != '-' && av[e][0] != '\0') {
            func_char_t->stock_my_folder[func_char_t->nb_folder] = av[e];
            func_char_t->nb_folder++;
        }
        e++;
    }
    i = 0;
    if (ac == 1)
        my_ls_basic(ac, av, func_char_t);
    while (i != ac) {
        if (strcmp(av[i],"-l") == 0) {
            my_ls_l_flag(ac, av, func_char_t);
        }
        if (strcmp(av[i],"-a") == 0) {
            my_ls_basic_hidden(ac, av, func_char_t);
        }
        i++;
    }
    return (0);
}


int my_open_file(int ac, char **av, func_char_t *func_char_t, int i)
{

    func_char_t->nb_files = 0;
    func_char_t->blocks_size = 0;
    func_char_t->dir = opendir(func_char_t->stock_my_folder[i]);
    /*if (func_char_t->dir == NULL) {
        printf("%s\n", strerror(errno)); 
        i++;
    }*/
    if (func_char_t->dir != NULL) {
        while ((func_char_t->ent = readdir (func_char_t->dir)) != NULL) {
            if (func_char_t->ent->d_name[0] != '.' && func_char_t->ent->d_name[strlen(func_char_t->ent->d_name) - 1] != '~'){
                my_strcpy(func_char_t->NameArr[func_char_t->nb_files], func_char_t->ent->d_name);
                my_strcat(func_char_t->NamePath, func_char_t->NameArr[func_char_t->nb_files]);
                stat(func_char_t->NamePath, &func_char_t->buf);

                my_strcpy(func_char_t->NamePath, func_char_t->stock_my_folder[i]);
                func_char_t->blocks_size += func_char_t->buf.st_blocks;
                func_char_t->nb_files++;
                //i++;
            }
        }
    }
}

int my_ls_l_flag(int ac, char **av, func_char_t *func_char_t)
{

    int k = 0;
    int i = 0;

    
    while (i != func_char_t->nb_folder) {
        my_open_file(ac, av, func_char_t, i);
        my_strcpy(func_char_t->NamePath, func_char_t->stock_my_folder[i]);

        printf("%s:\n", func_char_t->stock_my_folder[i]);
        printf("total %d\n", func_char_t->blocks_size / 2);

        for (k=0;k < func_char_t->nb_files;k++) {
            my_strcat(func_char_t->NamePath, func_char_t->NameArr[k]);
            stat(func_char_t->NamePath, &func_char_t->buf);

            my_strcpy(func_char_t->NamePath, func_char_t->stock_my_folder[i]);

            print_my_stick_bit(func_char_t->buf);
            printf(". %d", func_char_t->buf.st_nlink);
            print_my_guid(func_char_t->buf);
            printf("%d ",func_char_t->buf.st_size);
            my_strcpy(func_char_t->stockdate[k], 4 +ctime(&func_char_t->buf.st_mtime));
            my_strncpy(func_char_t->changedate[k], func_char_t->stockdate[k], strlen(func_char_t->stockdate[k]) - 9);
            my_strncpy(func_char_t->date_final[k], func_char_t->changedate[k], strlen(func_char_t->changedate[k]));
            printf("%s", func_char_t->date_final[k]);
            printf(" %s\n", func_char_t->NameArr[k]);
        }
    if (i < (func_char_t->nb_folder) - 1)
        printf("\n");
    i++;
    //printf("\n");
    }
    return (0);
}