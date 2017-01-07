/**
 * \file partieUnJoueur.c
 * \brief fonctions gérant le mode 1 joueur
 * 
 * 
*/




#include "../headers/partieUnJoueur.h"
#include "../headers/fonctionsPlateau.h"

// Besoin de la surface ecran (déclarée dans le main) en paramètre d'entrée
// Rajout possible d'une valeur de retour (pour dire si on a gagné par exemple)
int partieUnJoueur(SDL_Surface* ecran)
{
    Plateau P;
    initPlateau(P);

	short int alpha = -30000;
	short int beta = 30000;

    SDL_Color couleurNoir = {0, 0, 0};
    
    // Déclaration des surfaces de type SDL
    // Penser à libérer les surfaces (SDL_FreeSurface)

    SDL_Surface *SurfaceStatique = NULL;
    TTF_Font *policeDebug = NULL;
    policeDebug = TTF_OpenFont("ressources/SuperRetro.ttf", 18);

	SDL_Surface* titre[1] = {0};
	titre[0] = TTF_RenderText_Blended(policeDebug, "mode 1 joueur", couleurNoir);

    // Une variable position pour chaque surface avec un mouvement indépendant
    // Position statique utilisée pour blit toutes les surfaces statiques
    SDL_Rect positionStatique;

	SDL_Rect postitre[1]={0};
	postitre[0].x = ((LARGEUR_FENETRE/2) - 95);
	postitre[0].y = 0;

	// Pour indiquer que l'IA est en train de jouer :
	SDL_Surface* info;
	SDL_Rect posInfo;
	posInfo.x= LARGEUR_FENETRE-205;
	posInfo.y= (HAUTEUR_FENETRE/2)-10;

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
	initMenuMiniature(MODE_UN_JOUEUR,tabMenuMiniature,policeDebug, couleurNoir);

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

	char choixligne = -1, choixcolonne = -1;

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
            if (in.key[SDLK_LEFT]){
            }
            if (in.key[SDLK_RIGHT]){
            }
            if (in.key[SDLK_q]){
			}
            if (in.key[SDLK_d]){
            }
            if (in.key[SDLK_ESCAPE]){
                partieTerminee=true;
            }
            if (in.key[SDLK_SPACE]){
            }
            if (in.mousebuttons[SDL_BUTTON_LEFT]){
				in.mousebuttons[SDL_BUTTON_LEFT] = 0;	// fait une seule fois.
				if(traiteMenuMiniature(in.mousex,in.mousey,ecran,MODE_UN_JOUEUR)!=-1)
				{
					fin = traiteMenuMiniature(in.mousex,in.mousey,ecran,MODE_UN_JOUEUR);
					partieTerminee=true;
				}else{
					if(estGagnant(P)==PERSONNE && etapeRotation==false && ongletAffiche==false &&(nombreCoups%2==0))
					{
						if(placerBille(P, in.mousex, in.mousey, nombreCoups)){
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

			if(nombreCoups%2 != 0 && etapeRotation==false && nombreCoups<=(DIM_PLATEAU*DIM_PLATEAU)){
				
				if(estGagnant(P)==PERSONNE){
					SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); // Efface l'écran
					info = TTF_RenderText_Blended(policeDebug, "Ordinateur", couleurNoir);
					SDL_BlitSurface(info, NULL, ecran, &posInfo);
					affichePlateau(ecran, P, tabTypeEmplacement);
					SDL_Flip(ecran); // Actualise l'écran
					nombreCoups++;
					//SDL_Delay(1000);

					alphaBeta(P, alpha, beta, 0);
					
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

            //on affiche le joueur courant
			afficheJoueur(ecran,nombreCoups,policeDebug,couleurNoir);

            SDL_BlitSurface(titre[0], NULL, ecran, &postitre[0]);

			//on affiche le menu miniature
			afficheMenuMiniature(ecran,tabMenuMiniature, posTabMenuMiniature);
            SDL_Flip(ecran); // Actualise l'écran

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
	
	return(fin);
} // Fin fonction partieUnJoueur
