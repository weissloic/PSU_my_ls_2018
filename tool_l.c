/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/my.h"

int print_my_guid(struct stat buf)
{
    struct passwd *pwd;
    struct group *grp;

    if ((pwd = getpwuid(buf.st_uid)) != NULL)
        my_printf(" %s ", pwd->pw_name);
    if ((grp = getgrgid(buf.st_gid)) != NULL)
        my_printf("%s ", grp->gr_name);
}

void print_my_stick_bit(struct stat buf)
{
    my_printf((S_ISDIR(buf.st_mode)) ? "d" : "-");
    my_printf((buf.st_mode & S_IRUSR) ? "r" : "-");
    my_printf((buf.st_mode & S_IWUSR) ? "w" : "-");
    my_printf((buf.st_mode & S_IXUSR) ? "x" : "-");
    my_printf((buf.st_mode & S_IRGRP) ? "r" : "-");
    my_printf((buf.st_mode & S_IWGRP) ? "w" : "-");
    my_printf((buf.st_mode & S_IXGRP) ? "x" : "-");
    my_printf((buf.st_mode & S_IROTH) ? "r" : "-");
    my_printf((buf.st_mode & S_IWOTH) ? "w" : "-");
    my_printf((buf.st_mode & S_IXOTH) ? "x" : "-");
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0')) {
        i++;
    }
    return (s1[i] - s2[i]);
}