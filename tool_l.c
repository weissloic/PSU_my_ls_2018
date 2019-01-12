/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "getnextline.h"

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