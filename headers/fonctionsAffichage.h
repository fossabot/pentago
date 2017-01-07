/**
* \file fonctionsAffichage.h
* \brief définitions des prototypes des fonctions relatives à l'affichage et aux traitement des menus
*
* 
* 
* 
*  
*/

#ifndef DEF_FONCTIONAFFICHAGE
#define DEF_FONCTIONAFFICHAGE



#include "constantes.h"

/**
 * \fn short choixMenu(int absClic, int ordClic, SDL_Rect posTabChoixMenu[])
 * \brief détermine si le joueur clique sur un des choix du menu
 * 
 * \param absClic l'abscice du clic à traiter
 * \param ordClic l'ordonee du clic à traiter
 * \param posTabChoixMenu Le tableau des position des item à traiter
 * 
 * \return un nombre qui determnie un choix du menu
*/ 
short choixMenu(int absClic, int ordClic, SDL_Rect posTabChoixMenu[]);


/**
 * \fn void afficheRegles( SDL_Surface *ecran )
 * \brief Affiche les rêgles du jeu
 * 
 * \param ecran la surface SDL où afficher les règles
 * 
 *  \return retourne EXIT_SUCCESS pour verifier si la fonction c'est exécuté normalement
*/
short afficheRegles( SDL_Surface *ecran );


/**
 * \fn short affichePropos( SDL_Surface *ecran )
 * \brief Affiche les information sur le jeu
 * 
 * \param ecran la surface SDL où afficher les informations
 * 
 *  \return retourne EXIT_SUCCESS pour verifier si la fonction c'est exécuté normalement
*/
short affichePropos( SDL_Surface *ecran );


/**
 * \fn void afficheFin (int nom_gagnant, int nombre_coups, TTF_Font* police, SDL_Surface* texte, SDL_Color couleur, SDL_Surface *ecran)
 * \brief affiche quand une partie est terminée le 
 * nom du gagnant et le nombre de coup joué par celui ci
 * 
 * \param nom_gagnant le nom du gagnant conforme à l'énumération gagnant
 * \param nombre_coups le nombre de coups joué par un joueur
 * \param police la police qui sert à écrire les informations
 * \param texte la SDL_Surface sur laquelle on affiche les informations
 * \param couleur la couleur de la police
 * \param ecran la surface SDL où afficher la fin
 * 
 *
*/
void afficheFin (int nom_gagnant, int nombre_coups, TTF_Font* police, SDL_Surface* texte, SDL_Color couleur, SDL_Surface *ecran);


/**
 * \fn void afficheMenuMiniature(SDL_Surface* ecran, SDL_Surface* tabMenuMiniature[], SDL_Rect posTabMenuMiniature[])
 * \brief affiche le menu miniature situé en bas de la fenêtre
 * 
 * \param ecran la surface SDL où afficher le menu miniature
 * \param tabMenuMiniature[] tableau contenant les élément du menu miniature
 * \param postabMenuMiniature[] tableau contenant la position des élément du menu miniature
*/
void afficheMenuMiniature(SDL_Surface* ecran, SDL_Surface* tabMenuMiniature[], SDL_Rect posTabMenuMiniature[]);


/**
 * \fn short traiteMenuMiniature(int absClic, int ordClic,SDL_Surface *ecran,int partie)
 * \brief détermine si le joueur clique sur un des item du menu miniature
 * 
 * \param absClic l'abscice du clic à traiter
 * \param ordClic l'ordonee du clic à traiter
 * \param ecran la surface SDL où afficher les règles
 * \param partie nombre servant à savoir si on joue à 1 ou 2 joueurs
 * 
 * \return un nombre qui determine un choix du menu
*/
short traiteMenuMiniature(int absClic, int ordClic,SDL_Surface *ecran,int partie);


/**
 * \fn void initMenuMiniature(int partie,SDL_Surface* tabMenuMiniature[], TTF_Font * police,  SDL_Color couleur)
 * \brief initialise le menu miniature selon la partie joué
 * 
 * \param partie nombre servant à savoir si on joue à 1 ou 2 joueurs
 * \param tabMenuMiniature[] Surface contenant les item du menu
 * \param police la police utilisé
 * \param couleur la couleur de la police
*/
void initMenuMiniature(int partie,SDL_Surface* tabMenuMiniature[], TTF_Font * police,  SDL_Color couleur);

/**
 * \fn void afficheJoueur(SDL_Surface *ecran, int nb_coups,TTF_Font * police,  SDL_Color couleur)
 * \brief fonction affichant le joueur qui est en train de jouer 
 * 
 * \param ecran la surface SDL où afficher le joueur
 * \param nb_coups nombre qui nous sert a determiner le joueur courant selon le nombre de coups joué
 * \param police la police utilisé
 * \param couleur la couleur de la police
*/
void afficheJoueur(SDL_Surface *ecran, int nb_coups,TTF_Font * police,  SDL_Color couleur); 
#endif // DEF_FONCTIONAFFICHAGE
