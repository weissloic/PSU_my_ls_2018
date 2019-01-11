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
    func_char_t *func_char_t = malloc(sizeof(func_char_t) * 1000);
    my_struct(func_char_t);
    if (ac == 1)
        my_ls_basic(ac, av, func_char_t);
    while (i != ac) {
        if (strcmp(av[i],"-l") == 0) {
            //my_struct(func_char_t);
            my_ls_l_flag(ac, av, func_char_t);
        }
        if (strcmp(av[i],"-a") == 0) {
            //my_struct(func_char_t);
            my_ls_basic_hidden(ac, av, func_char_t);
        }
        i++;
    }
    //my_ls_l_flag(ac, av);
    return (0);
}

void my_struct(func_char_t *func_char_t)
{

    int nb_lines = 0;
    int malloc_date = 0;
    int malloc_t_flag = 0;
    int namearr_malloc = 0;
    int e = 0;

    func_char_t->NameArr = malloc(sizeof(char *) * 1000);
    func_char_t->NamePath = malloc(sizeof(char) * 1000);
    func_char_t->stockdate = malloc(sizeof(char *) * 1000);
    func_char_t->changedate = malloc(sizeof(char *) * 1000);
    func_char_t->date_final = malloc(sizeof(char *) * 1000);
    func_char_t->t_flag = malloc(sizeof(char *) * 1000);

    for (e = 0; e < 100; e++)
        func_char_t->stockdate[e] = malloc(sizeof(char) * 100);

    for (nb_lines = 0; nb_lines < 100; nb_lines++)
        func_char_t->changedate[nb_lines] = malloc(sizeof(char) * 100);

    for (malloc_date = 0; malloc_date < 100; malloc_date++)
        func_char_t->date_final[malloc_date] = malloc(sizeof(char) * 100);

    for (malloc_t_flag = 0; malloc_t_flag < 100; malloc_t_flag++)
        func_char_t->t_flag[malloc_t_flag] = malloc(sizeof(char) * 100);

    for (namearr_malloc = 0; namearr_malloc < 100; namearr_malloc++)
        func_char_t->NameArr[namearr_malloc] = malloc(sizeof(char) * 100);
}

int my_open_file(int ac, char **av, func_char_t *func_char_t)
{
    func_char_t->dir = opendir(av[1]);
    if (func_char_t->dir != NULL) {
        while ((func_char_t->ent = readdir (func_char_t->dir)) != NULL) {
            if (func_char_t->ent->d_name[0] != '.' && func_char_t->ent->d_name[strlen(func_char_t->ent->d_name) - 1] != '~'){
                my_strcpy(func_char_t->NameArr[func_char_t->nb_files], func_char_t->ent->d_name);
                my_strcat(func_char_t->NamePath, func_char_t->NameArr[func_char_t->nb_files]);
                stat(func_char_t->NamePath, &func_char_t->buf);
                my_strcpy(func_char_t->NamePath, av[1]);
                func_char_t->blocks_size += func_char_t->buf.st_blocks;
                func_char_t->nb_files++;
            }
        }
    }
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
                //my_strcpy(func_char_t->NamePath, av[1]);
                func_char_t->blocks_size += func_char_t->buf.st_blocks;
                func_char_t->nb_files++;
            }
        }
    }
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

int my_ls_l_flag(int ac, char **av, func_char_t *func_char_t)
{
    int k = 0;
    my_strcpy(func_char_t->NamePath, av[1]);
    my_open_file(ac, av, func_char_t);

    printf("total %d\n", func_char_t->blocks_size / 2);
    for (k=0;(k < (func_char_t->nb_files)) && (k < 1000);k++) {
        my_strcat(func_char_t->NamePath, func_char_t->NameArr[k]);
        stat(func_char_t->NamePath, &func_char_t->buf);
        my_strcpy(func_char_t->NamePath, av[1]);
        print_my_stick_bit(func_char_t->buf);
        printf(". %d", func_char_t->buf.st_nlink);
        print_my_guid(func_char_t->buf);
        printf("%d ",func_char_t->buf.st_size);
        my_strcpy(func_char_t->stockdate[k], 4 +ctime(&func_char_t->buf.st_atime));
        my_strncpy(func_char_t->changedate[k], func_char_t->stockdate[k], strlen(func_char_t->stockdate[k]) - 9);
        my_strncpy(func_char_t->date_final[k], func_char_t->changedate[k], strlen(func_char_t->changedate[k]));
        printf("%s", func_char_t->date_final[k]);
        printf(" %s\n", func_char_t->NameArr[k]);
    }
    return (0);
}

int print_my_guid(struct stat buf)
{
    struct passwd *pwd;
    struct group *grp;

    if ((pwd = getpwuid(buf.st_uid)) != NULL)
        printf(" %s ", pwd->pw_name);
    if ((grp = getgrgid(buf.st_gid)) != NULL)
        printf("%s ", grp->gr_name);
}

void print_my_stick_bit(struct stat buf)
{   
    if (S_ISCHR(buf.st_mode) == 1)
        printf("c");
    else if (S_ISDIR(buf.st_mode) == 1)
        printf("d");
    else
        printf("-");
    printf((buf.st_mode & S_IRUSR) ? "r" : "-");
    printf((buf.st_mode & S_IWUSR) ? "w" : "-");
    printf((buf.st_mode & S_IXUSR) ? "x" : "-");
    printf((buf.st_mode & S_IRGRP) ? "r" : "-");
    printf((buf.st_mode & S_IWGRP) ? "w" : "-");
    printf((buf.st_mode & S_IXGRP) ? "x" : "-");
    printf((buf.st_mode & S_IROTH) ? "r" : "-");
    printf((buf.st_mode & S_IWOTH) ? "w" : "-");
    printf((buf.st_mode & S_IXOTH) ? "x" : "-");
}

int my_ls_basic(int ac, char **av, func_char_t *func_char_t)
{
    int i = 0;
    int k = 0;

    my_open_file_basic(ac, av, func_char_t);
    //my_strcpy(func_char_t->NamePath, test);

    for (k=0;k < func_char_t->nb_files && k < 1000;k++) {
        if (k < (func_char_t->nb_files) - 1)
            printf("%s  ",func_char_t->NameArr[k]);
        else 
            printf("%s",func_char_t->NameArr[k]);
    }
    return 0;
}

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