/**
 * \file partieUnJoueur.h
 * \brief définitions des prototypes des fonctions utilisé pour le mode 1 joueurs
 * 
 * 
*/

#ifndef DEF_PARTIEUNJOUEUR
#define DEF_PARTIEUNJOUEUR


#include "constantes.h"


// Prototypes des fonctions de partieUnJoueur.c :
/**
 * \fn int partieUnJoueur (SDL_Surface *ecran)
 * \brief permet de jouer contre l'ordinateur
 * 
 * \param ecran affiche le jeu
 * 
 * \return un nombre qui determine les actions de fin de jeu
*/
int partieUnJoueur(SDL_Surface *ecran);

#endif // DEF_PARTIEUNJOUEUR

