#ifndef __ECHEQUIER__
#include "echiquier.h"
#endif

#include <stdio.h>


int est_case_occupee(Position pos, Case c){
    return pos & (UN << c);
}


int placer_dame_position(Position *pos, Case c){
    if(!pos){
        return 0;
    }
    *pos |= (UN << c);
    return 1;
}


int retirer_dame(Position *pos, Case c){
    if(!pos){
        return 0;
    }
    *pos &= ~(UN << c);
    return 1;
}



int afficher_position(Position pos){
    for(int j = 56 ; j >= 0 ; j -= 8){
        for(int i = 0 ; i < 8 ; i++){
            if( pos & (UN << (i+j) )){
                printf("+ ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
    return 1;
}



int calculer_cases_attaquees(Position *pos, Case c){
    if (pos == NULL)
        return 0;
    // même ligne
    *pos = 0;
    int equ,j,i;
    for (i = 0; i <= 7; i++) {
        
        if (i != c % 8) {
            
            placer_dame_position(pos, i + c - (c % 8));
            equ = i - (c % 8);
            if (i + c - (c % 8) + 8 * equ >= 0 && i + c - (c % 8) + 8 * equ <= 63)//diangonale
                placer_dame_position(pos, i + c - (c % 8) + 8 * equ);

            
            if (i + c - (c % 8) - 8 * equ >= 0 && i + c - (c % 8) - 8 * equ <= 63)//diagonale
                placer_dame_position(pos, i + c - (c % 8) - 8 * equ);
        }
    }

    // même collone
    for (j = c % 8; j < 64; j += 8)
        if (j != c)
            placer_dame_position(pos, j);

    return 1;
}





void init_tab_case_attaques(){
    for(int i = A1 ; i <= H8 ; i++){
        calculer_cases_attaquees(&(tab_cases_attaquees[i]),i);
    }
}



int est_sans_attaque_mutuelle(Position pos) {
    Position case_attaquees = 0;
    for (int i = 0; i <= 63; i++) {
        if (pos & (UN << i)) {
            case_attaquees |= tab_cases_attaquees[i];
        }
    }
    return !(pos & case_attaquees);
}




