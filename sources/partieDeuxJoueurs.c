/**
 * \file partieDeuxJoueurs.c
 * \brief fonctions gérant le mode 2 joueurs
 * 
 * 
*/




#include "../headers/partieDeuxJoueurs.h"
#include "../headers/fonctionsPlateau.h"

// Besoin de la surface ecran (déclarée dans le main) en paramètre d'entrée
int partieDeuxJoueurs(SDL_Surface* ecran)
{
    Plateau P;
    initPlateau(P);
    // DEBUG
    SDL_Color couleurNoir = {0, 0, 0};
    SDL_Surface *SurfaceStatique = NULL;
    TTF_Font *policeDebug = NULL;
    policeDebug = TTF_OpenFont("ressources/SuperRetro.ttf", 18);

	SDL_Surface* titre[1] = {0};
	titre[0] = TTF_RenderText_Blended(policeDebug, "mode 2 joueurs", couleurNoir);

	SDL_Rect postitre[1]={0};
	postitre[0].x = ((LARGEUR_FENETRE/2) - 97);
	postitre[0].y = 0;

	// FIN DEBUG

	SDL_Surface* tabTypeEmplacement[3] = {NULL};
	tabTypeEmplacement[BLANC]= IMG_Load("ressources/billeblanche.jpg");
	tabTypeEmplacement[NOIR]= IMG_Load("ressources/billenoire.jpg");
	tabTypeEmplacement[VIDE]= IMG_Load("ressources/vide.jpg");

	SDL_Surface* tabFlecheRotation[8] = {NULL};
	tabFlecheRotation[0]= IMG_Load("ressources/fleche0.png");
	tabFlecheRotation[1]= IMG_Load("ressources/fleche1.jpg");
	tabFlecheRotation[2]= IMG_Load("ressources/fleche2.jpg");
	tabFlecheRotation[3]= IMG_Load("ressources/fleche3.jpg");
	tabFlecheRotation[4]= IMG_Load("ressources/fleche4.jpg");
	tabFlecheRotation[5]= IMG_Load("ressources/fleche5.jpg");
	tabFlecheRotation[6]= IMG_Load("ressources/fleche6.jpg");
	tabFlecheRotation[7]= IMG_Load("ressources/fleche7.jpg");


	SDL_Rect tabPosFlecheRotation[8];
	tabPosFlecheRotation[0].x = (ABS_PLATEAU + (DIM_PLATEAU*TAILLE_EMPLACEMENT)) - 24;
	tabPosFlecheRotation[0].y = (ORD_PLATEAU - TAILLE_EMPLACEMENT) + 10;

	tabPosFlecheRotation[1].x = (ABS_PLATEAU + (DIM_PLATEAU*TAILLE_EMPLACEMENT) + TAILLE_EMPLACEMENT/2) - 7;
	tabPosFlecheRotation[1].y = (ORD_PLATEAU - TAILLE_EMPLACEMENT/2) + 19;

	tabPosFlecheRotation[2].x = tabPosFlecheRotation[1].x;
	tabPosFlecheRotation[2].y = (ORD_PLATEAU + (DIM_PLATEAU*TAILLE_EMPLACEMENT)) - 23;

	tabPosFlecheRotation[3].x = tabPosFlecheRotation[0].x;
	tabPosFlecheRotation[3].y = (ORD_PLATEAU + (DIM_PLATEAU*TAILLE_EMPLACEMENT) + TAILLE_EMPLACEMENT/2) - 5;

	tabPosFlecheRotation[4].x = (ABS_PLATEAU) - 2;
	tabPosFlecheRotation[4].y = tabPosFlecheRotation[3].y;

	tabPosFlecheRotation[5].x = (ABS_PLATEAU - TAILLE_EMPLACEMENT/2) - 13;
	tabPosFlecheRotation[5].y = tabPosFlecheRotation[2].y;

	tabPosFlecheRotation[6].x = tabPosFlecheRotation[5].x;
	tabPosFlecheRotation[6].y = tabPosFlecheRotation[1].y;

	tabPosFlecheRotation[7].x = tabPosFlecheRotation[4].x;
	tabPosFlecheRotation[7].y = tabPosFlecheRotation[0].y;



	//init du menu du bas
	SDL_Surface* tabMenuMiniature[4] = {0};

	initMenuMiniature(MODE_DEUX_JOUEUR,tabMenuMiniature,policeDebug, couleurNoir);

	//position du menu du bas
	SDL_Rect posTabMenuMiniature[4]={0};
	posTabMenuMiniature[0].x = 50;
	posTabMenuMiniature[0].y = BAS_FENETRE;

	posTabMenuMiniature[1].x = posTabMenuMiniature[0].x + 200;
	posTabMenuMiniature[1].y = posTabMenuMiniature[0].y;

	posTabMenuMiniature[2].x =posTabMenuMiniature[1].x + 200;
	posTabMenuMiniature[2].y = posTabMenuMiniature[0].y;

	posTabMenuMiniature[3].x =posTabMenuMiniature[2].x + 200;
	posTabMenuMiniature[3].y = posTabMenuMiniature[0].y;

    // Variables pour gérer le nombre d'images par secondes
    int now=0, before=0, interval=30;
    int tempsDebutpartie = SDL_GetTicks(); // pour ne pas prendre en compte le temps passé dans le menu d'accueil
    Input in;

	bool partieTerminee = false; // Pour la boucle infinie gérant les événements
	bool ongletAffiche = false, etapeRotation = false;

	int nombreCoups=0;
	int sens=0;
	int partieTableau=0;
	int i=0;
	int fin;
	int gagnant = PERSONNE;
	char * joueur = NULL;





    int x=0, y=0;

    memset(&in,0,sizeof(in));

    // Boucle infinie qui gère les événements
    //(s'arrête si appuie sur echap)
    while(!partieTerminee)
    {
        now = SDL_GetTicks();
        if(now-before > interval){ // Régulation de l'exectution du programme

            before=now;

            // Gestion des événements
            UpdateEvents(&in);
            if (in.key[SDLK_LEFT])
            {

            }
            if (in.key[SDLK_RIGHT]){
            }
            if (in.key[SDLK_q]){
			}
            if (in.key[SDLK_d]){
            }
            if (in.key[SDLK_BACKSPACE]){
				return(2);
			}
            if (in.key[SDLK_ESCAPE]){
                return(0);
            }
            if (in.key[SDLK_SPACE]){
            }
            if (in.mousebuttons[SDL_BUTTON_LEFT]){
				in.mousebuttons[SDL_BUTTON_LEFT] = 0;	// fait une seule fois.




				//on regarde si le clic est pas dans le menu miniature
				if(traiteMenuMiniature(in.mousex,in.mousey,ecran,MODE_DEUX_JOUEUR)!=-1)
				{
					fin = traiteMenuMiniature(in.mousex,in.mousey,ecran,MODE_DEUX_JOUEUR);
					partieTerminee=true;
				}else{

						if(ongletAffiche)
						{ // ET LE CLIC SE SITUE SUR FERMER ONGLET
							//ongletAffiche=false;
						}

						else if(etapeRotation==false && ongletAffiche==false)
						{
							if(placerBille(P, in.mousex, in.mousey, nombreCoups)){



								// DEBUG : LIGNE DU DESSOUS COMMENTEE POUR DESACTIVER ETAPE ROTATION ET ACCELERER LES PARTIES TEST
								etapeRotation=true;
							}
						}

						else
						{
							if(determinerRotation(in.mousex, in.mousey, tabPosFlecheRotation, &sens, &partieTableau)==true && ongletAffiche==false){

								rotation(P, sens, partieTableau);
								etapeRotation=false;
								nombreCoups++;
							}
						}
						

				}
			
			}


            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); // Efface l'écran

		if(!ongletAffiche){

				affichePlateau(ecran, P, tabTypeEmplacement);

			if(etapeRotation){
				for(i=0 ; i<8 ; i++){
					SDL_BlitSurface(tabFlecheRotation[i], NULL, ecran, &tabPosFlecheRotation[i]);
				}
			}

			gagnant = estGagnant(P);
			if(gagnant != PERSONNE)
			{
				etapeRotation=false;
				afficheFin(gagnant, nombreCoups, policeDebug, SurfaceStatique, couleurNoir, ecran);
			}
		}

		else{
			// afficher onglet menu
		}



            //on affiche le joueur courant
			afficheJoueur(ecran,nombreCoups,policeDebug,couleurNoir);

            SDL_BlitSurface(titre[0], NULL, ecran, &postitre[0]);
			//on affiche le menu miniature
			afficheMenuMiniature(ecran,tabMenuMiniature, posTabMenuMiniature);
			 // Actualise l'écran
            SDL_Flip(ecran);
        } // Fin du if(now-before > interval)

        else SDL_Delay(interval-(now-before)); // Mise en attente du programme (régulation)
     // Fin boucle infinie qui gère les événements

	}

    // Libération des surfaces chargées
    SDL_FreeSurface(SurfaceStatique);
	SDL_FreeSurface(titre[0]);
	for(i=0; i<3 ; i++){
		SDL_FreeSurface(tabTypeEmplacement[i]);
	}
	for(i=0; i<8 ; i++){
		SDL_FreeSurface(tabFlecheRotation[i]);
	}
	for(i=0; i<4 ; i++){
		SDL_FreeSurface(tabMenuMiniature[i]);
	}

	return(fin);
} // Fin fonction partieDeuxJoueurs


