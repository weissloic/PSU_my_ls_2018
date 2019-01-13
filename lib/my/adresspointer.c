/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#include "../../include/my.h"
#include <stdarg.h>

void my_putadress_pointer(int Adress_pointer)
{
    my_putstr("0x");
    my_puthexa(Adress_pointer);
}