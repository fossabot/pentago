/**
* \file fonctionsPlateau.h
* \brief définitions des prototypes des fonctions relative au plateau
* 
*/

#ifndef DEF_FONCTIONSPLATEAU
#define DEF_FONCTIONSPLATEAU


#include "constantes.h"


/**
 * \struct Input
 * \brief sert à gerer les entréer saisis par le joueur
*/
typedef struct
{
	 // SDLK_LAST : constante SDL qui contient valeur+1 de la plus haute valeur de touche de SDL
	 // taile du tableau suffisante pour stocker toutes les touches possibles (environ 100)
	char key[SDLK_LAST];/*!<Tableau qui contiendra l'état des touches du clavier (touches enfoncées ou non)*/
	int mousex;/*!<abscice de la souris*/
	int mousey;/*!<ordonne de la souris*/
	int mousexrel;/*!<abscice relative de la souris, variation depuis la derniere frame*/
	int mouseyrel;/*!<ordnee relative de la souris,variation depuis la derniere frame*/
	char mousebuttons[8];/*!<clic de la souris enfoncé ou non*/
    char quit;/*!< est a 1 si un event de type quit a été généré*/
} Input;


/**
 * \fn void UpdateEvents(Input* in)
 * \brief gestion des events selon les entrées saisis
 * 
 * \param in les entrées saisis
*/
void UpdateEvents(Input* in);

/**
 * \fn void initPlateau(Plateau P)
 * \brief initialisation du plateau de cases vides
 * 
 * \param P le plateau à initialiser
 * 
*/
void initPlateau(Plateau P);


/**
 * \fn void affichePlateau(SDL_Surface *ecran, Plateau P, SDL_Surface *tabEmplacementBille[])
 * \brief affichage du plateau dans la fenetre
 * 
 * \param ecran la surface SDL où afficher le plateau
 * \param P le plateau à afficher
 * \param tabEmplacementBille[] tableau contenant les coordonnées de chaque bille
 * 
*/
void affichePlateau(SDL_Surface *ecran, Plateau P, SDL_Surface *tabEmplacementBille[]);


/**
 * \fn bool placerBille(Plateau P, int absClic, int ordClic, int nombre_coups)
 * \brief placement d'une bille sur un plateau
 * 
 * \param P le plateau uitilisé
 * \param absClic abscice de la souris
 * \param ordClic ordonne de la souris
 * \param nombre_coups nombre qui sert a determiner si on place une bille noire ou blanche
 * 
 * \return vrais si une bille a été placée
*/
bool placerBille(Plateau P, int absClic, int ordClic, int nombre_coups);


/**
 * \fn bool determinerRotation(int absClic, int ordClic, SDL_Rect tabPosFlecheRotation[], int *sens, int *partieTableau)
 * \brief determiner quelle rotation il faut faire
 * 
 * \param absClic abscice de la souris
 * \param ordClic ordonne de la souris
 * \param tabPosFlecheRotation[] pour savoir la position des flèches a l'écran
 * \param sens le sens de rotation a effectuer
 * \param partieTableau sur quelle partie du plateau on effectue la rotation
 * 
 * \return vrais si on doit faire une rotation çàd si on a cliquer sur une flêche
*/
bool determinerRotation(int absClic, int ordClic, SDL_Rect tabPosFlecheRotation[], int *sens, int *partieTableau);


/**
 * \fn void rotation(int Plateau[][DIM_PLATEAU], int sens, int partieTableau)
 * \brief effectue une rotation sur un partie du plateau
 * 
 * \param Plateau le plateau utilisé
 * \param sens le sens de la rotation
 * \param partieTableau la partie du plateau ou la rotation est effectuée
 * 
*/
void rotation(int Plateau[][DIM_PLATEAU], int sens, int partieTableau);


/**
 * \fn int estGagnant(int Plateau[][DIM_PLATEAU])
 * \brief determine si il y a un gagnant ou pas sur un plateau
 * 
 * \param le plateau analysé
 * 
 * \return un nombre qui représente le gagnant
*/
int estGagnant(int Plateau[][DIM_PLATEAU]);


#endif // DEF_FONCTIONSPLATEAU
