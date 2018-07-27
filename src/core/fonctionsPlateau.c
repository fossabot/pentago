/**
* \file fonctionsPlateau.c
* \brief fonctions relatives au plateau
* 
*/





#include "../headers/fonctionsPlateau.h"

void UpdateEvents(Input* in)
{
	SDL_Event event;
        in->mousebuttons[SDL_BUTTON_WHEELUP] = 0;
        in->mousebuttons[SDL_BUTTON_WHEELDOWN] = 0;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			in->key[event.key.keysym.sym]=1;
			break;
		case SDL_KEYUP:
			in->key[event.key.keysym.sym]=0;
			break;
		case SDL_MOUSEMOTION:
			in->mousex=event.motion.x;
			in->mousey=event.motion.y;
			in->mousexrel=event.motion.xrel;
			in->mouseyrel=event.motion.yrel;
			break;
		case SDL_MOUSEBUTTONDOWN:
			in->mousebuttons[event.button.button]=1;
			break;
		case SDL_MOUSEBUTTONUP:
                        if (event.button.button!=SDL_BUTTON_WHEELUP && event.button.button!=SDL_BUTTON_WHEELDOWN)
			   in->mousebuttons[event.button.button]=0;
			break;
		case SDL_QUIT:
			in->quit = 1;
			break;
		default:
			break;
		}
	}
}
void initPlateau(Plateau P)
{
	short int i,j;//short int car on a pas besoin de beaucoup de nombre

	for (i=0;i<DIM_PLATEAU;i++)
	{
		for(j=0;j<DIM_PLATEAU;j++)
		{
			P[i][j]= VIDE;
		}
	}

}

void affichePlateau(SDL_Surface *ecran,  Plateau P, SDL_Surface *tabEmplacementBille[])
{
		short int i,j;//short int car on a pas besoin de beaucoup de nombre
		int couleur;
		SDL_Rect position;

	for (i=0;i<DIM_PLATEAU;i++)
	{
		for(j=0;j<DIM_PLATEAU;j++)
		{
			position.y = (i * TAILLE_EMPLACEMENT)+ORD_PLATEAU;//definition de la position selon x
			position.x =  (j * TAILLE_EMPLACEMENT)+ABS_PLATEAU;//definition de la position selon x
			if(i>=DIM_PLATEAU/2) position.y += 5;
			if(j>=DIM_PLATEAU/2) position.x += 5;
			couleur = P[i][j];
			switch (couleur)
			{
				case NOIR:
				//On affiche une case avec une bille noire à la position de la structure
					SDL_BlitSurface(tabEmplacementBille[NOIR], NULL, ecran, &position);
				break;

				case BLANC:
					//On affiche une case avec une bille blanche à la position de la structure
					SDL_BlitSurface(tabEmplacementBille[BLANC], NULL, ecran, &position);
				break;

				case VIDE:
					//On affiche une case vide à la position de la structure
					SDL_BlitSurface(tabEmplacementBille[VIDE], NULL, ecran, &position);
				break;
			}
		}
	}
}

bool placerBille(Plateau P, int absClic, int ordClic, int nbr_coups)
{
	short int i,j,posCentreCaseX, posCentreCaseY;
	float distance;
	bool placement;
	//si on clique apres le plateau
	if(absClic>(TAILLE_EMPLACEMENT*DIM_PLATEAU) + ABS_PLATEAU
		|| ordClic>(TAILLE_EMPLACEMENT*DIM_PLATEAU)+ORD_PLATEAU
		|| absClic<ABS_PLATEAU
		|| ordClic<ORD_PLATEAU)
	{
		placement=false;
	}
	else{
		//on regarde a quelle case le clic a eu lieu grace à la division entière
		j= (absClic-ABS_PLATEAU)/TAILLE_EMPLACEMENT;
		i= (ordClic-ORD_PLATEAU)/TAILLE_EMPLACEMENT;

		//on regarde où on se  situe précisémentdans cette case
		posCentreCaseX = (j*TAILLE_EMPLACEMENT + TAILLE_EMPLACEMENT/2) + ABS_PLATEAU;
		posCentreCaseY = (i* TAILLE_EMPLACEMENT + TAILLE_EMPLACEMENT/2) + ORD_PLATEAU;

		//Si on clique sur une case non vide
		if (P[i][j] != VIDE)
		{
			placement=false;
		}
		else{

			//on calcule la distance entre le centre de la case et le clic grâce au théorème de Pythagore
			distance = sqrt((absClic - posCentreCaseX)*(absClic - posCentreCaseX) + (ordClic - posCentreCaseY)*(ordClic - posCentreCaseY));
			//si on est dans l'emplacement d'une bille
			if (distance<RAYON_BILLE)
			{
				placement = true;
				//si le nombre de coup est pair çàd les blanc jouent
				if (nbr_coups%2==0)
				{
					P[i][j]=BLANC;
				}
				else{
					P[i][j]=NOIR;

				}
			}
		}
	}
	return (placement);
} // Fin fonction placerBille

int estGagnant(Plateau P)
{

// plateau est un tableau à deux dimensions représentant chaque emplacement du jeu par une valeur égale à NOIR, BLANC ou VIDE.

// Cas des diagonales :
//1ère diagonale centrale

	int somme;
	somme=0;

	int i, j;
	i=0;
	j=0;

	int couleurAnalysee=0;

	int gagnant=PERSONNE;

	if( P[1][1]!=VIDE )
	{
		if( P[0][0]!=VIDE && (P[0][0]==P[1][1]))
		{
				i=0;
				couleurAnalysee=P[i][i];
		}
		else
		{
			i=1;
			couleurAnalysee=P[i][i];
		}
	}

	while( couleurAnalysee == P[i][i] && i<DIM_PLATEAU )
	{
		i++;
		somme++;
	}

	if( somme >= 5 )
	{
		if( (couleurAnalysee == BLANC && gagnant == NOIR) || (couleurAnalysee == NOIR && gagnant == BLANC ) || (gagnant == EGALITE) )
		{
			gagnant = EGALITE;
		}
		else if ( couleurAnalysee == BLANC )
		{
			gagnant = BLANC;
		}
		else
		{
			gagnant = NOIR;
		}
	}

//2ème diagonale centrale

	somme=0;
	i=0;
	j=0;
	couleurAnalysee=0;

	if( P[DIM_PLATEAU-2][1]!=VIDE )
	{
		if( P[DIM_PLATEAU-1][0]!=VIDE && (P[DIM_PLATEAU-1][0]==P[DIM_PLATEAU-2][1]))
		{
			i=0;
			couleurAnalysee=P[DIM_PLATEAU-1-i][i];
		}
		else
		{
			i=1;
			couleurAnalysee=P[DIM_PLATEAU-1-i][i];
		}
	}

	while( couleurAnalysee == P[DIM_PLATEAU-1-i][i] && i<DIM_PLATEAU )
	{
		i++;
		somme++;
	}

	if( somme >= 5 )
	{
		if((couleurAnalysee == BLANC && gagnant == NOIR) || (couleurAnalysee == NOIR && gagnant == BLANC ) || (gagnant == EGALITE))
		{
			gagnant = EGALITE;
		}
		else if( couleurAnalysee == BLANC )
		{
			gagnant = BLANC;
		}
		else
		{
			gagnant = NOIR;
		}
	}

// 3ème diagonale

	i=0;
	somme=0;
	if(P[0][1]!=VIDE)
	{

		couleurAnalysee=P[0][1];

		while(couleurAnalysee==P[i][i+1] && i<5)
		{
			i++;
			somme++;
		}

		if(somme==5)
		{
			if((couleurAnalysee == BLANC && gagnant == NOIR) || (couleurAnalysee == NOIR && gagnant == BLANC) || (gagnant == EGALITE) )
			{
				gagnant = EGALITE;
			}
			else if( couleurAnalysee == BLANC )
			{
				gagnant = BLANC;
			}
			else
			{
				gagnant = NOIR;
			}
		}
	}

// 4ème diagonale :

	i=0;
	somme=0;

	if(P[1][0]!=VIDE)
	{
		couleurAnalysee=P[1][0];

		while( couleurAnalysee == P[i+1][i] && i<5 )
		{
			i++;
			somme++;
		}


		if( somme == 5 )
		{
			if( (couleurAnalysee == BLANC && gagnant == NOIR) || (couleurAnalysee == NOIR && gagnant == BLANC) || (gagnant == EGALITE) )
			{
				gagnant = EGALITE;
			}
			else if( couleurAnalysee == BLANC )
			{
				gagnant = BLANC;
			}
			else
			{
				gagnant = NOIR;
			}
		}
	}

// 5ème diagonale :

	i=0;
	somme=0;

	if(P[DIM_PLATEAU-2][0]!=VIDE)
	{
		couleurAnalysee=P[DIM_PLATEAU-2][0];

		while( couleurAnalysee == P[DIM_PLATEAU-2-i][i] && i<5 )
		{
			i++;
			somme++;
		}

		if( somme == 5 )
		{
			if( (couleurAnalysee == BLANC && gagnant == NOIR) || (couleurAnalysee == NOIR && gagnant == BLANC) || (gagnant == EGALITE) )
			{
				gagnant = EGALITE;
			}
			else if( couleurAnalysee == BLANC )
			{
				gagnant = BLANC;
			}
			else
			{
				gagnant = NOIR;
			}
		}
	}

// 6ème diagonale :
	i=0;
	somme=0;

	if(P[DIM_PLATEAU-1][1]!=VIDE)
	{
		couleurAnalysee = P[DIM_PLATEAU-1][1];

		while( couleurAnalysee == P[DIM_PLATEAU-1-i][i+1] && i<5 )
		{
			i++;
			somme++;
		}

		if( somme == 5 )
		{
			if( (couleurAnalysee == BLANC && gagnant == NOIR) || (couleurAnalysee == NOIR && gagnant == BLANC) || (gagnant == EGALITE) )
			{
				gagnant = EGALITE;
			}
			else if( couleurAnalysee == BLANC )
			{
				gagnant = BLANC;
			}
			else
			{
				gagnant = NOIR;
			}
		}
	}

// Cas des colonnes :

	for(j=0; j<DIM_PLATEAU; j++)
	{
		somme=0;

		if( P[1][j] != VIDE )
		{
			if( P[0][j] != VIDE &&(P[0][j]==P[1][j]))
			{
				i=0;
				couleurAnalysee=P[i][j];
			}
			else
			{
				i=1;
				couleurAnalysee=P[i][j];
			}

		}

	while( couleurAnalysee == P[i][j] && i<DIM_PLATEAU )
	{
		somme++;
		i++;
	}

	if( somme >= 5 )
	{
		if( (couleurAnalysee == BLANC && gagnant == NOIR) || (couleurAnalysee == NOIR && gagnant == BLANC) || (gagnant == EGALITE) )
		{
			gagnant = EGALITE;
		}
		else if( couleurAnalysee == BLANC )
		{
			gagnant = BLANC;
		}
		else
		{
			gagnant = NOIR;
		}
	}

	}


// Cas des lignes :

	for( i=0; i<DIM_PLATEAU; i++)
	{
		somme=0;

		if( P[i][1] != VIDE )
		{
			if( P[i][0] != VIDE  && (P[i][0]==P[i][1]))
			{
				j=0;
				couleurAnalysee=P[i][j];
			}
			else
			{
				j=1;
				couleurAnalysee=P[i][j];
			}
		}

	while( couleurAnalysee == P[i][j] && j<DIM_PLATEAU )
	{
		somme++;
		j++;
	}

	if( somme >= 5 )
	{
		if( (couleurAnalysee == BLANC && gagnant == NOIR) || (couleurAnalysee == NOIR && gagnant == BLANC) || (gagnant == EGALITE) )
		{
			gagnant = EGALITE;
		}
		else if( couleurAnalysee == BLANC )
		{
			gagnant = BLANC;
		}
		else
		{
			gagnant = NOIR;
		}
	}

	}


	//On retourne la valeur de gagnant
	return(gagnant);

} // Fin fonction estGagnant


bool determinerRotation(int absClic, int ordClic, SDL_Rect tabPosFlecheRotation[], int *sens, int *partieTableau){

	int i=0;
	bool flecheSelectionnee=false;

	do{
		if((absClic > tabPosFlecheRotation[i].x && absClic < tabPosFlecheRotation[i].x + tabPosFlecheRotation[i].w) &&
		(ordClic > tabPosFlecheRotation[i].y && ordClic < tabPosFlecheRotation[i].y + tabPosFlecheRotation[i].h ) )
		{
			flecheSelectionnee=true;
		}

		else{
			i++;
		}
	} while((flecheSelectionnee == false) && (i<8));

	switch(i){
		case 0:
			*sens = SENS_TRIGONOMETRIQUE;
			*partieTableau=HAUT_DROITE;
			break;

		case 1:
			*sens = SENS_HORAIRE;
			*partieTableau=HAUT_DROITE;
			break;

		case 2:
			*sens = SENS_TRIGONOMETRIQUE;
			*partieTableau=BAS_DROITE;
			break;

		case 3:
			*sens = SENS_HORAIRE;
			*partieTableau=BAS_DROITE;
			break;

		case 4:
			*sens = SENS_TRIGONOMETRIQUE;
			*partieTableau=BAS_GAUCHE;
			break;

		case 5:
			*sens = SENS_HORAIRE;
			*partieTableau=BAS_GAUCHE;
			break;

		case 6:
			*sens = SENS_TRIGONOMETRIQUE;
			*partieTableau=HAUT_GAUCHE;
			break;

		case 7:
			*sens = SENS_HORAIRE;
			*partieTableau=HAUT_GAUCHE;
			break;
	}

	return(flecheSelectionnee);
} // Fin fonction determinerRotation

//fonction effectuant une rotation d'une partie du plateau selon un sens (+ ou - 90°)
void rotation(Plateau P, int sens,int partie_plateau)
{

	short int debutX,debutY,finX,finY;
	int i=0, j=0;
	Plateau P2;//plateau intermediaire facilitant la rotation

	switch(partie_plateau)
	{
		case HAUT_GAUCHE:
			debutX=0;
			debutY=0;
			finX=(DIM_PLATEAU/2)-1;
			finY=(DIM_PLATEAU/2)-1;
		break;

		case HAUT_DROITE:
			debutX=(DIM_PLATEAU/2);
			debutY=0;
			finX=DIM_PLATEAU-1;
			finY=(DIM_PLATEAU/2)-1;
		break;

		case BAS_GAUCHE:
			debutX=0;
			debutY=(DIM_PLATEAU/2);
			finX=(DIM_PLATEAU/2)-1;
			finY=DIM_PLATEAU-1;
		break;

		case BAS_DROITE:
			debutX=(DIM_PLATEAU/2);
			debutY=(DIM_PLATEAU/2);
			finX=DIM_PLATEAU-1;
			finY=DIM_PLATEAU-1;
		break;

	}

	for(i=0;i<(DIM_PLATEAU/2);i++)
	{
		for(j=0;j<(DIM_PLATEAU/2);j++)
		{
			//si on tourne a -90°
			if (sens==SENS_TRIGONOMETRIQUE)
			{
				//la dernière colonne du plateau sera la première ligne de p2 et ainsi de suite
				P2[i+debutY][j+debutX]=P[j+debutY][finX-i];

			}
			else{
				//sinon si on tourne a +90°
				//la dernière ligne du plateau sera la première colonne de p2 et ainsi de suite
				P2[i+debutY][j+debutX]=P[finY-j][i+debutX];
			}
		}
	}

		//on recopie notre nouveau plateau
		for(i=debutY;i<=finY;i++)
		{
			for(j=debutX;j<=finX;j++)
			{
				P[i][j]=P2[i][j];
			}
		}
} // finFonctionRotation


