#ifndef __ECHEQUIER__
#define __ECHEQUIER__

#define UN (unsigned long long) 1 //diffèrent du 1 (int)

//enum met des entiers de 0 à 63
typedef enum _case{
    A1,B1,C1,D1,E1,F1,G1,H1,
    A2,B2,C2,D2,E2,F2,G2,H2,
    A3,B3,C3,D3,E3,F3,G3,H3,
    A4,B4,C4,D4,E4,F4,G4,H4,
    A5,B5,C5,D5,E5,F5,G5,H5,
    A6,B6,C6,D6,E6,F6,G6,H6,
    A7,B7,C7,D7,E7,F7,G7,H7,
    A8,B8,C8,D8,E8,F8,G8,H8
}Case;


typedef unsigned long long Position;

static Position tab_cases_attaquees[64];



/// @brief fonction qui renvoie si la case est occupé 
/// @param pos 
/// @param c 
/// @return 1 ou 0 selon le statut de la case
int est_case_occupee(Position pos, Case c);

/// @brief fonction qui place une dame à la position Case 
/// @param pos 
/// @param c 
/// @return 1 si tout se passe bien , 0 si jamais la pos est NULL par exemple
int placer_dame_position(Position *pos, Case c);

/// @brief fonction qui affiche la position
/// @param pos 
/// @return toujours 1 (censé renvoyé 1 ou 0 mais le seule bug possible est que le printf() plante ce qui est rare)
int afficher_position(Position pos);

/// @brief fonction qui calcule les cases attaquées par la case c
/// @param pos 
/// @param c 
/// @return 1 si tout se passe bien , 0 en cas d'echec (ex : pos == NULL)
int calculer_cases_attaquees(Position *pos, Case c);

/// @brief fonction qui retire une dame présente à la case c
/// @param pos 
/// @param c 
/// @return 1 si tout se passe bien , 0 en cas d'echec (ex : pos == NULL)
int retirer_dame(Position *pos, Case c);


/// @brief fonction qui initialise un tableau statique tab_case_attaque
void init_tab_case_attaques();


/// @brief fonction qui regarde si deux dames s'attaquent mutuellement ou pas
/// @param pos 
/// @return 1 si il n'y a pas d'attaque mutuelle , 0 sinon
int est_sans_attaque_mutuelle(Position pos);

#endif