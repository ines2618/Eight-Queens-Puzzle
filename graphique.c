#include <assert.h>
#include <ncurses.h>
#include <stdio.h>

#ifndef __ECHEQUIER__
#include "echiquier.h"
#endif

#ifndef _GRAPH_
#include "graphique.h"
#endif

void couleur_fenetre(int nb_colonnes, int nb_lignes) {
    attron(COLOR_PAIR(1));
    for (int i = 0; i < nb_lignes; i++) {
        for (int j = 0; j < nb_colonnes; j++) {
            mvprintw(j, i, " ");
        }
    }
    attroff(COLOR_PAIR(1));
}


void carre(int lines, int cols, int dim, int color) {
    attron(COLOR_PAIR(color));
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            mvprintw(cols + j, lines + 2 * i, "  ");
        }
    }
    attroff(COLOR_PAIR(color));
}





void damier(Position pos, int lines_select, int cols_select) {
    int i, j;
    int color = 0;
    int offsetX = (COLS - 8 * 6) / 2; // Calcul de l'offset horizontal
    int offsetY = (LINES - 8 * 3) / 2; // Calcul de l'offset vertical
    
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                color = 2;
            } else {
                color = 3;
            }
            
            if (i == lines_select && j == cols_select) {
                color = 4;
            }
    
            carre(offsetX + 6 * i, offsetY + 3 * j, 3, color);
            if (pos & (UN << (i + 8 * (7 - j)))) {
                attron(COLOR_PAIR(color));
                mvprintw(offsetY + 3 * j + 1, offsetX + 6 * i + 2, "D");
                refresh();
                attroff(COLOR_PAIR(color));
            }
        }
        refresh();
    }
}




void select_case(int touche, int *lines, int *cols) {
    int new_lines = *lines;
    int new_cols = *cols;

    switch (touche) {
        case KEY_LEFT:
            new_lines--;
            break;

        case KEY_RIGHT:
            new_lines++;
            break;

        case KEY_DOWN:
            new_cols++;
            break;

        case KEY_UP:
            new_cols--;
            break;
    }

    if (0 <= new_cols && new_cols < 8 && 0 <= new_lines && new_lines < 8) {
        *lines = new_lines;
        *cols = new_cols;
    }
}




int essayer_placer_dame(Position *pos, int touche, int lines_select, int cols_select, int nb_dames) {
    int offsetX = (COLS - 8 * 6) / 2; // Calcul de l'offset horizontal
    int offsetY = (LINES - 8 * 3) / 2; // Calcul de l'offset vertical
    
    int posX = offsetX + 6 * lines_select;
    int posY = offsetY + 3 * cols_select;
    
    if (touche == ' ' && !(*pos & UN << (lines_select + 8 * (7 - cols_select)))) {
        placer_dame_position(pos, lines_select + 8 * (7 - cols_select));
        if (est_sans_attaque_mutuelle(*pos)) {
            mvprintw(posY + 1, posX + 2, "D");
            return nb_dames + 1;
        }
        retirer_dame(pos, lines_select + 8 * (7 - cols_select));
        carre(posX, posY, 3, 5);
    }
    
    if (touche == ' ' && (*pos & UN << (lines_select + 8 * (7 - cols_select)))) {
        // Enlever la dame à cette position et reafficher
        retirer_dame(pos, lines_select + 8 * (7 - cols_select));
        
        carre(posX, posY, 3, 5);
        
        return nb_dames - 1;
    }
    
    return nb_dames;
}




