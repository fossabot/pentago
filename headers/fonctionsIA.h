/**
* \file fonctionsIA.h
* \brief définitions des prototypes des fonctions relatives à l'inteligence artificielle 
*/

#ifndef DEF_FONCTIONIA
#define DEF_FONCTIONIA



#include "constantes.h"
/**
 * \fn short int evaluationPlateau(Plateau P)
 * \brief fonction evaluant si le plateau est plus ou moin favorable à l'ordi
 * 
 * \param P le plateau à évaluer
 * 
 * \return un nombre qui représente le gain 
 * 
*/
short int evaluationPlateau(Plateau P);


/**
 * \fn short int alphaBeta(Plateau P, short int alpha, short int beta, short int nombre_coups)
 * \brief fonction recherchant le meilleur coup possible pour l'ordinateur
 * en optimisant les passages dans l'arbre récursif
 * 
 * \param P le plateau à évaluer
 * \param alpha sert à la coupure dans les noeud max
 * \param beta sert à la coupure dans les noeud min
 * \param nombre_coups pour la profondeur de l'arbre
 * 
 * \return retourne le meilleur coup possible pour l'ordi
*/
short int alphaBeta(Plateau P, short int alpha, short int beta, short int profondeur);


/**
 * short int calculGain(Plateau P, short int couleurAnalyse)
 * \brief analyse le plateau pour une couleur
 * 
 * \param P le plateau à évaluer
 * \param couleurAnalyse represente la couleur à analyser
*/
short int calculGain(Plateau P, short int couleurAnalyse);

/**
 * \fn bool plateauVide(Plateau P, int partieTableau)
 * \brief determine si une partie de plateau est vide ou non
 * 
 * \param P le plateau à évaluer
 * \param partieTableau nombre representant la partie du tablea
 * 
*/

typedef struct Coup {
	int ligne;
	int colonne;
} Coup;

bool plateauVide(Plateau P, int partieTableau);
void meilleurCoup(Plateau P, short int couleurAnalyse, Coup *meilleur);

#endif // DEF_FONCTIONIA
