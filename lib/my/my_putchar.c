/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** my_putchar
*/

#include <unistd.h>
#include "../../include/my.h"
#include <stdarg.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}