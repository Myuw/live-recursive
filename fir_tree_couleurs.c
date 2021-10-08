// /*
// ** EPITECH PROJECT, 2021
// ** fir
// ** File description:
// ** Tree
// */

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>

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

void printColors(char *str)
{
    int random = rand() % 100;

    if (random <= 80) {
        init_pair(1, COLOR_GREEN, COLOR_GREEN);
        attron(COLOR_PAIR(1));
    }
    if (random >= 80 && random <= 85) {
        init_pair(2, COLOR_MAGENTA, COLOR_MAGENTA);
        attron(COLOR_PAIR(2));
    }
    if (random >= 85 && random <= 90) {
        init_pair(3, COLOR_RED, COLOR_RED);
        attron(COLOR_PAIR(3));
    }
    if (random >= 90 && random <= 95) {
        init_pair(4, COLOR_BLUE, COLOR_BLUE);
        attron(COLOR_PAIR(4));
    }
    if (random >= 95 && random <= 100) {
        init_pair(5, COLOR_WHITE, COLOR_WHITE);
        attron(COLOR_PAIR(5));
    }
    printw(str);
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    attroff(COLOR_PAIR(4));
    attroff(COLOR_PAIR(5));
}

int print_part(int size, int turn, int loop, int constSize)
{
    if (turn <= 0)
        return (loop - 4);
    for (int i = 0; i < ((countLine(constSize)/2) - loop/2); i++)
        printw(" ");

    for (int i = 0; loop != i; i++)
        printColors("*");
    refresh();

    printw("\n");
    print_part(size, turn - 1, loop + 2, constSize);
}

void trunk(int size, int turn)
{
    if (size == turn)
        return;
    for (int i = 0; i < (countLine(size) / 2) - size + 1; i++)
        printw(" ");
    init_pair(6, COLOR_YELLOW, COLOR_YELLOW);
    attron(COLOR_PAIR(6));
    for (int i = 0; i != size; i++)
        printw("|");
    attroff(COLOR_PAIR(6));
    printw("\n");
    trunk(size, turn + 1);
}

int leaf(int size, int turn, int last, int nb)
{
    if (size == 0)
        return (0);
    last = print_part(size, turn + 4, last, nb);
    leaf(size - 1, turn + 1, last - (turn / 2 * 2), nb);
    return (0);
}

int fir_tree(int size)
{
    leaf(size, 0, 1, size);
    trunk(size, 0);
    return (0);
}

int main(int ac, char **av)
{
        srand(time(NULL));
    if (error_gestion(ac, av) == 84)
        return (84);
    initscr();
    start_color();
    while (1) {
        fir_tree(atoi(av[1]));
        refresh();
        clear();
        sleep(1);
    }
    getch();
    return (0);
}