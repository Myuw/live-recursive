/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


char *int_to_bin(int nbr)
{
    char *tab = malloc(sizeof(char) * 9);
    int i = 0;
    char *stock = malloc(sizeof(char) * 9);
    int a = 0;

    for(i=0; nbr > 0; i++) {
        tab[i] = nbr%2 + 48;
        nbr = nbr/2;
    }
    tab[i] = '\0';
    tab = my_revstr(tab);
    a = strlen(tab);
    i = 0;
    for (int u = a; a != 8; a++, i++)
        stock[i] = '0';
    for (a = 0; a != strlen(tab); a++, i++)
        stock[i] = tab[a];
    stock[i] = '\0';
    free(tab);
    return (stock);
}

int main(int ac, char **av)
{
    printf("%s\n", int_to_bin(atoi(av[1])));
    return (0);
}
