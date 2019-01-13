/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#include "../../include/my.h"
#include <stdarg.h>

void my_puthexa(int nb)
{
    unsigned int div;
    unsigned int size_base;
    unsigned int result;
    char *base;
    base = "0123456789abcdef";
    div = 1;
    size_base = my_strlen(base);

    while ((nb / div) >= size_base){
        div = div * size_base;
    }
    while (div > 0){
        result = (nb / div) % size_base;
        my_putchar(base[result]);
        div = div / size_base;
    }
}

void my_putocta(int nb)
{
    unsigned int div;
    unsigned int size_base;
    unsigned int result;
    char *base;
    base = "01234567";
    div = 1;
    size_base = my_strlen(base);

    while ((nb / div) >= size_base){
        div = div * size_base;
    }
    while (div > 0){
        result = (nb / div) % size_base;
        my_putchar(base[result]);
        div = div / size_base;
    }
}

void my_puthexaupp(int nb)
{
    unsigned int div;
    unsigned int size_base;
    unsigned int result;
    char *base;
    base = "0123456789ABCDEF";
    div = 1;
    size_base = my_strlen(base);

    while ((nb / div) >= size_base){
        div = div * size_base;
    }
    while (div > 0){
        result = (nb / div) % size_base;
        my_putchar(base[result]);
        div = div / size_base;
    }
}

void my_putbinary(int nb)
{
    unsigned int div;
    unsigned int size_base;
    unsigned int result;
    char *base;
    base = "01";
    div = 1;
    size_base = my_strlen(base);

    while ((nb / div) >= size_base){
        div = div * size_base;
    }
    while (div > 0){
        result = (nb / div) % size_base;
        my_putchar(base[result]);
        div = div / size_base;
    }
}