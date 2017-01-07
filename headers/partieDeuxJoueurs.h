/**
 * \file partieDeuxJoueurs.h
 * \brief définitions des prototypes des fonctions utilisé pour le mode 2 joueurs
 * 
 * 
*/

#ifndef DEF_PARTIEDEUXJOUEURS
#define DEF_PARTIEDEUXJOUEURS



#include "constantes.h"

// Prototypes des fonctions de partieDeuxJoueurs.c :

/**
 * \fn int partieDeuxJoueurs (SDL_Surface *ecran)
 * \brief permet de jouer contre un joueur
 * 
 * \param ecran affiche le jeu
 * 
 * \return un nombre qui determine les actions de fin de jeu
*/
int partieDeuxJoueurs (SDL_Surface *ecran);

#endif // DEF_PARTIEDEUXJOUEURS

