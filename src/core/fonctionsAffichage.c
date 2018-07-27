/**
 * \file fonctionsAffichage.c
 * \brief fonctions relatives à l'affichage et aux traitement des menus
 *
*/

#include "../headers/fonctionsAffichage.h"

void afficheFin (int nom_gagnant, int nombre_coups, TTF_Font* police, SDL_Surface* texte, SDL_Color couleur, SDL_Surface *ecran)
{
	SDL_Surface* choix;
	SDL_Rect positionStatique[1];
	positionStatique[0].x=235;
	positionStatique[0].y=30;
	positionStatique[1].x=285;
	positionStatique[1].y=60;
	char message[]= "nombre de coup :";
	char*  nombre_coups_char=(char*) malloc(2*sizeof(char));
	//on covertit le nombre de coups en chaine de caractère
	snprintf(nombre_coups_char,3,"%d",nombre_coups/2+1);
	//on ajoute tout au message
	strcat( message,nombre_coups_char);

	switch(nom_gagnant)
	{




		case BLANC_GAGNANT:
		texte = TTF_RenderText_Blended(police, "Le joueur blanc a gagne", couleur);
		SDL_BlitSurface(texte, NULL, ecran, &positionStatique[0]);

			break;
		case NOIR_GAGNANT:

		texte = TTF_RenderText_Blended(police, "Le joueur noir a gagne", couleur);
		SDL_BlitSurface(texte, NULL, ecran, &positionStatique[0]);

		//texte = TTF_RenderText_Blended(police, "vous avez gagné en %d coups ", couleur);

			break;
		case EGALITE:

		texte = TTF_RenderText_Blended(police, "Egalité", couleur);
		SDL_BlitSurface(texte, NULL, ecran, &positionStatique[0]);
                break;

		}

		choix = TTF_RenderText_Blended(police, message, couleur);
		SDL_BlitSurface(choix, NULL, ecran, &positionStatique[1]);
		SDL_FreeSurface(choix);
	    SDL_FreeSurface(texte);

}

short afficheRegles (SDL_Surface *ecran)
{
	SDL_Color couleurNoir = {0, 0, 0};
	TTF_Font *police = NULL;
	police = TTF_OpenFont("ressources/SuperRetro.ttf", 20);

	SDL_Surface* regles = NULL;
	regles= IMG_Load("ressources/reglesOK.png");

	SDL_Rect posRegles;
	posRegles.x = 0;
	posRegles.y = 0;

	SDL_Surface* tabOptionsMenu[1] = {0};
	tabOptionsMenu[0] = TTF_RenderText_Blended(police, "Retour", couleurNoir);

	SDL_Rect posTabOptionsMenu[1]={0};
	posTabOptionsMenu[0].x = 600;
	posTabOptionsMenu[0].y = 450;

    // Variables pour gérer le nombre d'images par secondes
    int now=0, before=0, interval=33;
    SDL_Event event;

	// Affichage des règles :
	SDL_BlitSurface(regles, NULL, ecran, &posRegles);
	SDL_BlitSurface(tabOptionsMenu[0], NULL, ecran, &posTabOptionsMenu[0]);
	SDL_Flip(ecran);

	bool continuer=true;
	int valeurChoixMenu=0;

    while (continuer) // Boucle infinie qui gère les événements
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = false;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: // Veut arrêter le jeu
                        continuer = false;
                        break;
                }
				break;
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
				    valeurChoixMenu = choixMenu(event.button.x, event.button.y, posTabOptionsMenu);
				}
				break;
        }

		if(valeurChoixMenu==1) continuer=false;
    }

}

short affichePropos (SDL_Surface *ecran)
{
	SDL_Color couleurNoir = {0, 0, 0};
	TTF_Font *police = NULL;
	police = TTF_OpenFont("ressources/SuperRetro.ttf", 20);

	SDL_Surface* propos = NULL;
	propos= IMG_Load("ressources/propos.png");

	SDL_Rect posPropos;
	posPropos.x = 0;
	posPropos.y = 0;

	SDL_Surface* tabOptionsMenu[1] = {0};
	tabOptionsMenu[0] = TTF_RenderText_Blended(police, "Retour", couleurNoir);

	SDL_Rect posTabOptionsMenu[1]={0};
	posTabOptionsMenu[0].x = 600;
	posTabOptionsMenu[0].y = 450;

    // Variables pour gérer le nombre d'images par secondes
    int now=0, before=0, interval=33;
    SDL_Event event;

	// Affichage des règles :
	SDL_BlitSurface(propos, NULL, ecran, &posPropos);
	SDL_BlitSurface(tabOptionsMenu[0], NULL, ecran, &posTabOptionsMenu[0]);
	SDL_Flip(ecran);

	bool continuer=true;
	int valeurChoixMenu=0;

    while (continuer) // Boucle infinie qui gère les événements
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = false;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: // Veut arrêter le jeu
                        continuer = false;
                        break;
                }
				break;
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
				    valeurChoixMenu = choixMenu(event.button.x, event.button.y, posTabOptionsMenu);
				}
				break;
        }

		if(valeurChoixMenu==1) continuer=false;
    }

    return EXIT_SUCCESS;
}


short choixMenu (int absClic,int ordClic, SDL_Rect posTabChoixMenu[])
{
	int choix;
	choix=RIEN;

	if( (absClic > posTabChoixMenu[0].x && absClic < posTabChoixMenu[0].x + posTabChoixMenu[0].w) &&
	(ordClic > posTabChoixMenu[0].y && ordClic < posTabChoixMenu[0].y + posTabChoixMenu[0].h ) )
	{
		choix=MODE_UN_JOUEUR;
	}
	else if( (absClic > posTabChoixMenu[1].x && absClic < posTabChoixMenu[1].x + posTabChoixMenu[1].w) &&
	(ordClic > posTabChoixMenu[1].y && ordClic < posTabChoixMenu[1].y + posTabChoixMenu[1].h ) )
	{
		choix=MODE_DEUX_JOUEUR;
	}
	else if( (absClic > posTabChoixMenu[2].x && absClic < posTabChoixMenu[2].x + posTabChoixMenu[2].w) &&
	(ordClic > posTabChoixMenu[2].y && ordClic < posTabChoixMenu[2].y + posTabChoixMenu[2].h ) )
	{
		choix=REGLE;
	}
	else if( (absClic > posTabChoixMenu[3].x && absClic < posTabChoixMenu[3].x + posTabChoixMenu[3].w) &&
	(ordClic > posTabChoixMenu[3].y && ordClic < posTabChoixMenu[3].y + posTabChoixMenu[3].h ) )
	{
		choix=PROPOS;
	}
	else if( (absClic > posTabChoixMenu[4].x && absClic < posTabChoixMenu[4].x + posTabChoixMenu[4].w) &&
	(ordClic > posTabChoixMenu[4].y && ordClic < posTabChoixMenu[4].y + posTabChoixMenu[4].h ) )
	{
		choix=QUITTER;
	}
	return(choix);
}

void afficheMenuMiniature(SDL_Surface* ecran, SDL_Surface* tabMenuMiniature[], SDL_Rect posTabMenuMiniature[])
{
	SDL_BlitSurface(tabMenuMiniature[0], NULL, ecran, &posTabMenuMiniature[0]);
	SDL_BlitSurface(tabMenuMiniature[1], NULL, ecran, &posTabMenuMiniature[1]);
	SDL_BlitSurface(tabMenuMiniature[2], NULL, ecran, &posTabMenuMiniature[2]);
	SDL_BlitSurface(tabMenuMiniature[3], NULL, ecran, &posTabMenuMiniature[3]);
}

short traiteMenuMiniature(int absClic, int ordClic,SDL_Surface *ecran,int partie)
{
	//si on est dans la zone ou il y a le menu miniature
	if( (ordClic>BAS_FENETRE)&&(ordClic<HAUTEUR_FENETRE))
	{
		if(partie==MODE_UN_JOUEUR)
		{
			//si on est sur le rejouer une partie
			if(absClic<250)
			{
				return(MODE_UN_JOUEUR);
			}
			//si on est sur le Mode deux joueurs
			if ( (absClic>250)&&(absClic<450) )
			{
				return(MODE_DEUX_JOUEUR);
			}
			//si on est sur regles
			if ( (absClic>450)&&(absClic<650) )
			{
				afficheRegles (ecran);
				return(-1);
			}
			if (absClic>650)
			{

				return(0);
            }
		}
			if(partie==MODE_DEUX_JOUEUR)
			{
				//si on est sur le mode Un joueur
				if(absClic<250)
			{
				return(MODE_UN_JOUEUR);
			}
			//si on est sur le Mode deux joueurs
			if ( (absClic>250)&&(absClic<450) )
			{
				return(MODE_DEUX_JOUEUR);
			}
			//si on est sur regles
			if ( (absClic>450)&&(absClic<650) )
			{
				afficheRegles (ecran);
				return(-1);
			}
			if (absClic>650)
			{

				return(0);
            }
			}
		}
	return(-1);
}
//fonction initialisant le menu miniature selon le mode de jeu
void initMenuMiniature(int partie,SDL_Surface* tabMenuMiniature[], TTF_Font * police,  SDL_Color couleur)
{
	if(partie== MODE_UN_JOUEUR)
	{
		tabMenuMiniature[0] = TTF_RenderText_Blended(police, "Rejouer", couleur);
		tabMenuMiniature[1] = TTF_RenderText_Blended(police, "2 joueurs", couleur);
		tabMenuMiniature[2] = TTF_RenderText_Blended(police, "Regles", couleur);
		tabMenuMiniature[3] = TTF_RenderText_Blended(police, "Quitter", couleur);
	}else{
		tabMenuMiniature[0] = TTF_RenderText_Blended(police, "1 joueur", couleur);
		tabMenuMiniature[1] = TTF_RenderText_Blended(police, "Rejouer", couleur);
		tabMenuMiniature[2] = TTF_RenderText_Blended(police, "Regles", couleur);
		tabMenuMiniature[3] = TTF_RenderText_Blended(police, "Quitter", couleur);
	}
}

void afficheJoueur(SDL_Surface *ecran, int nb_coups,TTF_Font * police,  SDL_Color couleur)
{
	SDL_Surface *joueur;
	SDL_Rect posJoueur;
	posJoueur.y=(HAUTEUR_FENETRE/2)-10;
	//si le nombre de coup est paire, les blancs jouent
	if(nb_coups%2==0)
	{
		joueur = TTF_RenderText_Blended(police, "Blanc", couleur);
		//on affiche Blanc a droite du plateau
		posJoueur.x=125;


	}else{
		joueur = TTF_RenderText_Blended(police, "Noir", couleur);
		posJoueur.x=LARGEUR_FENETRE-205;
	}

	SDL_BlitSurface (joueur,NULL,ecran,&posJoueur);
	SDL_FreeSurface(joueur);
}
