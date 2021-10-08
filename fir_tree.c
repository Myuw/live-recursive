// /*
// ** EPITECH PROJECT, 2021
// ** fir
// ** File description:
// ** Tree
// */

#include <stdio.h>
#include <stdlib.h>

int error_gestion(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        printf("Please give me a number.\n");
        return (84);
    }
    for (int i = 0; av[1][i] != '\0'; i++)
        if (av[1][i] < '0' || av[1][i] > '9')
            return (84);
    return (0);
}

int countLine(int size)
{
    int line = 4;
    int last_col = 1;
    int reduction = 1;

    for (int i = 0; i < size; i++, line++)
    {
        last_col += 2 * (line - reduction);

        if (i % 2 == 0)
            reduction += 1;
    }

    return last_col;
}

int compteSpace(int size, int turn, int loop)
{
    int i = 3;
    int o = 0;

    for (int i = 0; i != size; i++)
        o += 4 + i;
    return (o-size*2+turn-3);
}

int print_part(int size, int turn, int loop, int constSize)
{
    if (turn <= 0)
        return (loop - 4);
    for (int i = 0; i < ((countLine(constSize)/2) - loop/2); i++)
        printf(" ");

    for (int i = 0; loop != i; i++)
        putchar('*');
    printf("\n");
    print_part(size, turn - 1, loop + 2, constSize);
}

void trunk(int size, int turn)
{
    if (size == turn)
        return;
    for (int i = 0; i != size * 3; i++)
        putchar(' ');
    for (int i = 0; i != size; i++)
        putchar('|');
    putchar('\n');
    trunk(size, turn + 1);
}

int leaf(int size, int turn, int last, int nb)
{
    if (size == 0)
        return (0);
    last = print_part(size, turn + 4, last, nb); // print les étoile
    leaf(size - 1, turn + 1, last - (turn / 2 * 2), nb); // récursif
    return (0);
}

int fir_tree(int size)
{
    leaf(size, 0, 1, size); // algo pour les feuilles
    trunk(size, 0); // algo pour le tronc
    return (0);
}

int main(int ac, char **av)
{
    if (error_gestion(ac, av) == 84)
        return (84);
    fir_tree(atoi(av[1]));
    return (0);
}