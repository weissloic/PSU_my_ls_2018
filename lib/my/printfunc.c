/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#include "../../include/my.h"
#include <stdarg.h>

void my_putbinary1(va_list ap)
{
    my_putbinary(va_arg(ap, int));
}

void my_putocta1(va_list ap)
{
    my_putocta(va_arg(ap, int));
}

void my_putadress_pointer1(va_list ap)
{
    my_putadress_pointer(va_arg(ap, int));
}

void my_putpercentage1(va_list ap)
{
    my_putchar('%');
}

void my_u_put_nbr1(va_list ap)
{
    my_put_nbr2(va_arg(ap, unsigned int));
}