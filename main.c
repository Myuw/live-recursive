/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arg.h"

char *my_revstr(char *str)
{
    char c = '\0';
    int len = strlen(str);

    for (int i = 0; i < (len / 2); i = i + 1) {
        c = str[i];
        str[i] = str[(len - 1) - i];
        str[(len - i) - 1] = c;
    }
    return (str);
}

char *int_to_bin(arg_t *arg)
{
    char *tab = malloc(sizeof(char) * 9);
    char *stock = malloc(sizeof(char) * 9);
    int i = 0;
    int a = 0;

    for (i = 0; arg->rule > 0; i++) {
        tab[i] = arg->rule % 2 + 48;
        arg->rule = arg->rule / 2;
    }
    tab[i] = '\0';
    tab = my_revstr(tab);
    a = strlen(tab);
    i = 0;
    for (; a != 8; a++, i++)
        stock[i] = '0';
    for (a = 0; a != strlen(tab); a++, i++)
        stock[i] = tab[a];
    stock[i] = '\0';
    free(tab);
    return (stock);
}

void set_arg(arg_t *arg, char **av)
{
    arg->rule = atoi(av[1]);
    arg->line = atoi(av[2]);
}

void my_free(char **tab, arg_t *arg, char *stock)
{
    for (int i = 0; i < arg->line; i++)
        free(tab[i]);
    free(tab);
    free(arg);
    free(stock);
}

char **set_tab(char **tab, arg_t *arg)
{
    tab = malloc(sizeof(char *) * (arg->line + 1));
    if (tab == NULL)
        return NULL;
    for (int i = 0; i < arg->line; i++) {
        tab[i] = malloc(sizeof(char) * (80 + 1));
        if (tab[i] == NULL)
            return NULL;
        for (int j = 0; j < 80; j++)
            tab[i][j] = '*';
        tab[i][80] = '\n';
    }
    tab[arg->line] = NULL;
    return tab;
}

void print_tab(char **tab, arg_t *arg)
{
    for (int i = 0; i < arg->line; i++)
        printf("%s", tab[i]);
}

int main(int ac, char **av)
{
    arg_t *arg = malloc(sizeof(arg_t));
    char **tab = NULL;
    char *stock = NULL;

    if (arg == NULL || ac != 3) {
        fprintf(stderr, "Give me 2 arg please (rule and nb of lines)\n");
        return 0;
    }
    set_arg(arg, av);
    tab = set_tab(tab, arg);
    stock = int_to_bin(arg);
    printf("%s\n", stock);
    print_tab(tab, arg);
    my_free(tab, arg, stock);
    return (0);
}
