/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** my_put_nbr
*/
#include "../../include/my.h"
#include <stdarg.h>

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_put_nbr(-214748364);
        my_putchar('8');
        return (1);
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if ((nb >= 0) && (nb < 10)) {
        my_putchar(nb + 48);
    } else {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
    return (0);
}