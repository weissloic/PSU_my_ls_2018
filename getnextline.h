/*
** EPITECH PROJECT, 2018
** 103cypher
** File description:
** description
*/


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <dirent.h>
#include <pwd.h>
#include <string.h>
#include <grp.h>
#include <errno.h>




typedef struct func_char_t {
    char **NameArr;
    char *NamePath;
    char **stockdate;
    char **changedate;
    char **date_final;
    char **t_flag;
    char **stock_my_folder;
    struct stat buf;
    struct dirent *ent;
    int nb_files;
    int nb_folder;
    DIR *dir;
    int blocks_size;
} func_char_t;
