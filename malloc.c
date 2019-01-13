/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/my.h"

void my_struct(func_char_t *func_char_t)
{
    func_char_t->NameArr = malloc(sizeof(char *) * 1000);
    func_char_t->NamePath = malloc(sizeof(char) * 1000);
    func_char_t->stockdate = malloc(sizeof(char *) * 1000);
    func_char_t->changedate = malloc(sizeof(char *) * 1000);
    func_char_t->date_final = malloc(sizeof(char *) * 1000);
    func_char_t->t_flag = malloc(sizeof(char *) * 1000);
    func_char_t->stock_my_folder = malloc(sizeof(char *) * 1000);
    func_char_t->stock_folder = malloc(sizeof(char *) * 1000);

    int nb_lines = 0;
    int e = 0;
    my_struct_two(func_char_t);

    for (e = 0; e < 100; e++)
        func_char_t->stockdate[e] = malloc(sizeof(char) * 100);

    for (nb_lines = 0; nb_lines < 100; nb_lines++)
        func_char_t->changedate[nb_lines] = malloc(sizeof(char) * 100);
}

void my_struct_two(func_char_t *func_char_t)
{
    int malloc_date = 0;
    int malloc_t_flag = 0;
    int namearr_malloc = 0;
    int stock_file = 0;
    int test = 0;

    for (malloc_date = 0; malloc_date < 100; malloc_date++)
        func_char_t->date_final[malloc_date] = malloc(sizeof(char) * 100);

    for (malloc_t_flag = 0; malloc_t_flag < 100; malloc_t_flag++)
        func_char_t->t_flag[malloc_t_flag] = malloc(sizeof(char) * 100);

    for (namearr_malloc = 0; namearr_malloc < 100; namearr_malloc++)
        func_char_t->NameArr[namearr_malloc] = malloc(sizeof(char) * 100);

    for (stock_file = 0; stock_file < 100; stock_file++)
        func_char_t->stock_my_folder[stock_file] = malloc(sizeof(char) * 100);

    for (test = 0; test < 100; test++)
        func_char_t->stock_folder[test] = malloc(sizeof(char) * 100);
}