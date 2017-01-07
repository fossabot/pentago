/**
* \file constantes.h
* \brief définitions de constantes 
*
* 
* 
*  
*/

#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdbool.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include <math.h>
#include <string.h>



// Définitions des constantes du programme :
/** 
* \def LARGEUR_FENETRE
* La largeur de notre fenetre de jeu
* 
*/
#define LARGEUR_FENETRE 800


/** 
* \def HAUTEUR_FENETRE
* La hauteur de notre fenetre de jeu
* 
*/
#define HAUTEUR_FENETRE 500


/** 
* \def DIM_PLATEAU
* definition du plateau de DIM_PLATEU*DIM_PLATEAU emplacement
* 
*/
#define DIM_PLATEAU 6


/** 
* \def TAILLE_EMPLACEMENT
* definition de la taille d'un emplacement pour une bille
* 
*/
#define TAILLE_EMPLACEMENT 50


/** 
* \def RAYON_BILLE
* definition de la taille d'un compartiment pour une bille
* 
*/
#define RAYON_BILLE 17


/** 
* \def NB_COUPS_MAX
* definition du nombre de coups maximum pour un plateau de taille DIM_PLATEAU*DIM_PLATEAU
* 
*/
#define NB_COUP_MAX (DIM_PLATEAU*DIM_PLATEAU)


/** 
* \def ABS_PLATEAU
* definition d'un nouvel abscice où l'origine est le début du plateau
* 
*/
#define ABS_PLATEAU (LARGEUR_FENETRE/2 - (DIM_PLATEAU*TAILLE_EMPLACEMENT)/2)


/** 
* \def ORD_PLATEAU
* definition d'un nouvel ordonnée où l'origine est le début du plateau
* 
*/
#define ORD_PLATEAU (HAUTEUR_FENETRE/2 - (DIM_PLATEAU*TAILLE_EMPLACEMENT)/2)


/** 
* \def BAS_FENETRE
* definition du bas de la fenètre pour le menu miniature
* 
*/
#define BAS_FENETRE (HAUTEUR_FENETRE-25)

// Définitions des énumerations du programme
/**
*\enum  contenuCase
* \brief Représente le contenue d une case
*/
enum contenuCase{
	NOIR,/*!< case avec une bille noire*/
	BLANC,/*!< case avec une bille blanche*/
	VIDE/*!< case vide*/
 };

/**
* \enum  partieTableau
* \brief Représente une partie du plateau
*/
enum partiePlateau
{
	HAUT_GAUCHE,/*!< Partie située en haut à gauche du plateau*/
	HAUT_DROITE, /*!< Partie située en haut à droite du plateau*/
	BAS_GAUCHE,/*!< Partie située en bas à gauche du plateau*/
	BAS_DROITE/*!< Partie située en bas à droite du plateau*/
}; 

/**
* \enum  gagnant
* \brief Représente le gagnant
*/
enum gagnant
{
	NOIR_GAGNANT,/*!<Represente le cas où le joueur noir gagne*/
	BLANC_GAGNANT,/*!<Represente le cas où le joueur blanc gagne*/
	PERSONNE, /*!<Represente le cas où personne gagne*/
	EGALITE/*!<Represente l'égalité*/
}; 

/**
* \enum  sens
* \brief Représente le sens de la rotation
*/
enum sens
{
	SENS_HORAIRE,/*!<Represente le cas où on tourne un plateau dans le sens horaire*/
	SENS_TRIGONOMETRIQUE/*!<Represente le cas où on tourne un plateau dans le sens trigonometrique*/
}; 

/**
* \enum  menu
* \brief Représente un item du menu
*/
enum menu
{
	RIEN,/*!<Represente le cas où on reste dans le menu*/
	MODE_UN_JOUEUR,/*!<Represente le cas où on lance une partie contre l'ia*/
	MODE_DEUX_JOUEUR,/*!<Represente le cas où on lance une partie contre un autre joueur*/
	REGLE,/*!<Represente le cas où on choisit de regarder les règles du jeu*/
	PROPOS,/*!<Represente le cas ou on choisi de regarder les information sur le jeu*/
	QUITTER/*!<Represente le cas où on choisit de quitter le jeu*/
};

// Définitions de notre plateau de jeu
/**
* \typedef Plateau 
* \brief Le Plateau du jeu est un tableau à deux dimensions de DIM_PLATEAU*DIM_PLATEAU cases
*/
typedef int Plateau[DIM_PLATEAU][DIM_PLATEAU];

#endif // DEF_CONSTANTES
