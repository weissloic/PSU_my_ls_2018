/*
** EPITECH PROJECT, 2018
** 103cypher
** File description:
** description
*/


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <dirent.h>
#include <pwd.h>
#include <string.h>
#include <grp.h>
#include <errno.h>




typedef struct func_char_t {
    char **NameArr;
    char *NamePath;
    char **stockdate;
    char **changedate;
    char **date_final;
    char **t_flag;
    char **stock_my_folder;
    char **stock_folder;
    struct stat buf;
    struct dirent *ent;
    int nb_files;
    int nb_folder;
    int number;
    DIR *dir;
    int blocks_size;
} func_char_t;

int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_printf(char *s, ...);
void my_isflagfunction(int i, char *s, va_list ap);
void my_iswritefunction(int i, int u,  char *s, va_list ap);
void my_getocta(char *s);
void my_puthexa(int);
void my_puthexaupp(int);
void my_putbinary(int);
void my_putocta(int);
void my_putadress_pointer(int);
void my_putpercentage(char);
void my_put_nbr2(unsigned int nb);
void my_putstroctal(char *);
void my_putcharacter1(va_list ap);
void my_putstring1(va_list ap);
void my_putnumber1(va_list ap);
void my_puthexa1(va_list ap);
void my_puthexaupp1(va_list ap);
void my_putocta1(va_list ap);
void my_putbinary1(va_list ap);
void my_putadress_pointer1(va_list ap);
void my_putpercentage1(va_list ap);
void my_u_put_nbr1(va_list ap);
void func_put_stroctal1(va_list ap);
void open_function_ls(int ac, char **av, func_char_t *func_char_t, int k);
void open_file_hidden_complete(int ac, char **av,
    func_char_t *func_char_t, int i);
int my_open_file_hidden(int ac, char **av, func_char_t *func_char_t, int i);
int my_ls_hidden(int ac, char **av, func_char_t *func_char_t);
void my_open_file_basic_complete(int ac, char **av, func_char_t *func_char_t);
int my_open_file_basic(int ac, char **av, func_char_t *func_char_t);
int my_ls_basic_oneav(int ac, char **av, func_char_t *func_char_t);
int my_ls_basic_twoav(int ac, char **av, func_char_t *func_char_t);
int my_ls_basic(int ac, char **av, func_char_t *func_char_t);
void my_struct(func_char_t *func_char_t);
void my_struct_two(func_char_t *func_char_t);
int my_ls_la_flag(int ac, char **av, func_char_t *func_char_t);
int my_ls_l_flag(int ac, char **av, func_char_t *func_char_t);
int my_ls_lone_flag(int ac, char **av, func_char_t *func_char_t);
void print_l(func_char_t *func_char_t, int k, int i);
void my_open_file_complete(int ac, char **av, func_char_t *func_char_t, int i);
char *my_strcat(char *dest, char const *src);

char *my_strncpy(char *dest, char *src, int n);
int my_open_file(int ac, char **av, func_char_t *func_char_t, int i);
void cat_my_path(func_char_t *func_char_t, int ac, char **av);
void my_two_condition(func_char_t *func_char_t, int ac, char **av, int i);
void my_condition(func_char_t *func_char_t, int ac, char **av, int i);
int my_strcmp(char *s1, char *s2);
void print_my_stick_bit(struct stat buf);
int print_my_guid(struct stat buf);

static void (*point_func[12])(va_list ap) = {
    &my_putcharacter1,
    &my_putstring1,
    &my_putnumber1,
    &my_puthexa1,
    &my_puthexaupp1,
    &my_putocta1,
    &my_putbinary1,
    &my_putadress_pointer1,
    &my_putpercentage1,
    &my_u_put_nbr1,
    &func_put_stroctal1,
    &my_putnumber1
};
