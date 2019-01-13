/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#include "../../include/my.h"
#include <stdarg.h>

void my_getocta(char *s)
{
    if (*s < 7)
        my_putstr("\\00");
    else if (*s > 7 && *s < 32)
        my_putstr("\\0");
    else if (*s >= 127)
        my_putstr("\\");
}

void my_putstroctal(char *s)
{
    while (*s){
        if (*s < 32 || *s >= 127){
            my_getocta(s);
            my_putocta(*s);
        }
        else
            my_putchar(*s);
        s++;
    }
}