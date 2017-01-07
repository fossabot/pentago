/**
 * \file main.c
 * \brief fonction principale du jeu
 * 
 * 
*/

#include "../headers/fonctionsAffichage.h"
/**
 *\fn  int main(int argc, char **argv)
 * \brief premier fonction utilisée au lancement du programme
 * 
 * \param argc nombre de chaine contenue dans argv
 * \param argv argument pour lancer le programme
 * 
 * \return 0 si le programme c'est bien exécutée
 */
int main(int argc, char **argv)
{
    SDL_Surface *ecran = NULL;
    SDL_Rect position;

    SDL_Init(SDL_INIT_VIDEO); // initialisation de la SDL
    TTF_Init();

	SDL_Color couleurNoir = {0, 0, 0};
	TTF_Font *police = NULL;
	police = TTF_OpenFont("ressources/SuperRetro.ttf", 20);

	SDL_Surface *accueil = NULL;
	accueil= IMG_Load("ressources/accueil.png");

	SDL_Rect posAccueil;
	posAccueil.x = 0;
	posAccueil.y = 0;
	//initialisation des items du menu
	SDL_Surface* tabOptionsMenu[5] = {0};
	tabOptionsMenu[0] = TTF_RenderText_Blended(police, "mode 1 joueur", couleurNoir);
	tabOptionsMenu[1] = TTF_RenderText_Blended(police, "mode 2 joueurs", couleurNoir);
	tabOptionsMenu[2] = TTF_RenderText_Blended(police, "Regles", couleurNoir);
	tabOptionsMenu[3] = TTF_RenderText_Blended(police, "A propos", couleurNoir);
	tabOptionsMenu[4] = TTF_RenderText_Blended(police, "Quitter", couleurNoir);
	
	//initialisation des positions des items du menu
	SDL_Rect posTabOptionsMenu[5]={0};
	posTabOptionsMenu[0].x = ((LARGEUR_FENETRE/2) - 100);
	posTabOptionsMenu[0].y = (HAUTEUR_FENETRE/2 - 50);

	posTabOptionsMenu[1].x = ((LARGEUR_FENETRE/2) - 113);
	posTabOptionsMenu[1].y = (posTabOptionsMenu[0].y + 50);

	posTabOptionsMenu[2].x = ((LARGEUR_FENETRE/2) - 40);
	posTabOptionsMenu[2].y = (posTabOptionsMenu[1].y + 50);

	posTabOptionsMenu[3].x = ((LARGEUR_FENETRE/2) - 57);
	posTabOptionsMenu[3].y = (posTabOptionsMenu[2].y + 50);

	posTabOptionsMenu[4].x = ((LARGEUR_FENETRE/2) - 46);
	posTabOptionsMenu[4].y = (posTabOptionsMenu[3].y + 50);


    ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Pentago", NULL);

    // Variables pour gérer le nombre d'images par secondes
    int now=0, before=0, interval=33;
    SDL_Event event;

	bool continuer=true;
	int valeurChoixMenu=RIEN;

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
                    case SDLK_RETURN:
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
        while(valeurChoixMenu!=RIEN)
        {
			switch(valeurChoixMenu)
			{
				case MODE_UN_JOUEUR:
                    valeurChoixMenu=partieUnJoueur(ecran);
						break;
				case MODE_DEUX_JOUEUR:
                    valeurChoixMenu=partieDeuxJoueurs(ecran);
						break;
				case REGLE: valeurChoixMenu=RIEN;
						afficheRegles(ecran);
						break;
                case PROPOS: valeurChoixMenu=RIEN;
                        affichePropos(ecran);
                        break;
				case QUITTER: valeurChoixMenu=RIEN;
                        continuer=false;
					break;

			}
		}

        // Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

        SDL_BlitSurface(accueil, NULL, ecran, &posAccueil);
        SDL_BlitSurface(tabOptionsMenu[0], NULL, ecran, &posTabOptionsMenu[0]);
        SDL_BlitSurface(tabOptionsMenu[1], NULL, ecran, &posTabOptionsMenu[1]);
        SDL_BlitSurface(tabOptionsMenu[2], NULL, ecran, &posTabOptionsMenu[2]);
        SDL_BlitSurface(tabOptionsMenu[3], NULL, ecran, &posTabOptionsMenu[3]);
        SDL_BlitSurface(tabOptionsMenu[4], NULL, ecran, &posTabOptionsMenu[4]);

        SDL_Flip(ecran);
    }

	SDL_FreeSurface(ecran);
	TTF_CloseFont(police);

	TTF_Quit();
	SDL_Quit;

    return EXIT_SUCCESS;
}

