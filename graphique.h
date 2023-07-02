#define _GRAPH_



/// @brief 
/// @param nb_colonnes 
/// @param nb_lignes 
void couleur_fenetre(int nb_colonnes, int nb_lignes);


/// @brief fonction qui dessine un carré
/// @param lines 
/// @param cols 
/// @param dim dimension du carré (3x3 ...)
void carre(int lines, int cols, int dim, int color);


/// @brief fonction qui affiche le damier
/// @param pos 
/// @param lines_select 
/// @param cols_select 
void damier(Position pos, int lines_select, int cols_select);


/// @brief fonction qui calcule la prochaine case en fonction des touches directionelles
/// @param touche 
/// @param lines type int * de manière à le changer directement dans la fonction
/// @param cols idem
void select_case(int touche, int *lines, int *cols);




/// @brief fonction qui place une dame à la posiiton courante du joueur
///si il n'y a pas de dame à cette position et qu'i n'y a pas d'attaque mutelle, la dame est placé
///sinon un carré rouge apparait sur la case pour signaler que la position est non valide
///si il appuie sur une case ou il y'a une dame , la dame sera retiré du terrain
/// @param pos 
/// @param touche 
/// @param lines_select 
/// @param cols_select 
/// @param nb_dames 
/// @return le nombre de dame courant
int essayer_placer_dame(Position *pos, int touche, int lines_select, int cols_select, int nb_dames);