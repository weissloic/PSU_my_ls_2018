/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#include "../../include/my.h"
#include <stdarg.h>

void func_put_stroctal1(va_list ap)
{
    my_putstroctal(va_arg(ap, char *));
}