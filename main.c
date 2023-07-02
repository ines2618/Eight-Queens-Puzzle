#include <assert.h>
#include <ncurses.h>
#include <stdio.h>

#ifndef __ECHEQUIER__
#include "echiquier.h"
#endif

#ifndef _GRAPH_
#include "graphique.h"
#endif



int main() {
    Position pos = 0;
    int lines = 0;
    int cols = 0;
    int touche;
    int nb_dames = 0;

    init_tab_case_attaques();

    initscr();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_YELLOW);
    init_pair(3, COLOR_WHITE, COLOR_BLUE);
    init_pair(4, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(5, COLOR_WHITE, COLOR_RED);

    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);
    couleur_fenetre(LINES, COLS);
    damier(pos, lines, cols);

    while (nb_dames != 8) {
        touche = getch();
        select_case(touche, &lines, &cols);
        damier(pos, lines, cols);
        nb_dames = essayer_placer_dame(&pos, touche, lines, cols, nb_dames);
        attron(COLOR_PAIR(1));
        mvprintw(LINES - 1, COLS / 2 - 10, " Nombre de dames : %d", nb_dames);
        attroff(COLOR_PAIR(1));
    }

    clear();
    couleur_fenetre(LINES,COLS);
    attron(COLOR_PAIR(1));
    mvprintw(LINES / 2, COLS / 2, "GAGNE");
    attroff(COLOR_PAIR(1));
    getch();
    endwin();
}