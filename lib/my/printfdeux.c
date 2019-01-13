/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#include "../../include/my.h"
#include <stdarg.h>

void my_putcharacter1(va_list ap)
{
    my_putchar(va_arg(ap, int));
}

void my_putstring1(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

void my_putnumber1(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void my_puthexa1(va_list ap)
{
    my_puthexa(va_arg(ap, int));
}

void my_puthexaupp1(va_list ap)
{
    my_puthexaupp(va_arg(ap, int));
}