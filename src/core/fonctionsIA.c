/**
* \file fonctionsIA.c
* \brief fonctions relatives à l'inteligence artificielle 
*/

#include "../headers/fonctionsIA.h"

short int evaluationPlateau(Plateau P)
{
	int gain=0;
	
	if(estGagnant(P) == NOIR) return(2000);
	else if(estGagnant(P) == BLANC) return(-2000);
	else if(estGagnant(P) == EGALITE) return(0);
	else{	
		gain += calculGain(P, NOIR);
		gain = gain - calculGain(P, BLANC);
		return(gain);
	}
}

short int calculGain(Plateau P, short int couleurAnalyse){
	
	short int gain=0;
	unsigned char i=0, j=0;
	unsigned char suite=0, k=0;
	unsigned char gagnant=PERSONNE;
	
	// Suite de billes de la même couleur sur les lignes du plateau
	while(i<DIM_PLATEAU && gagnant==PERSONNE){
		
		while(j<DIM_PLATEAU && gagnant==PERSONNE){
			
			if(P[i][j]==couleurAnalyse){
			do{
				suite++;
				j++;
			} while(P[i][j]==couleurAnalyse && j<DIM_PLATEAU);
			
				if(suite>=5 && gagnant==PERSONNE) gagnant=couleurAnalyse;
				else gain+=(suite*suite);				
			}
			
			j++;
			suite=0;
		}
		i++;
		j=0;
	}
	i=0;
	
	// Suite de billes de la même couleur sur les colonnes du plateau
	while(j<DIM_PLATEAU && gagnant==PERSONNE){
		while(i<DIM_PLATEAU && gagnant==PERSONNE){
			
			if(P[i][j]==couleurAnalyse){
			do{
				suite++;
				i++;
			} while(P[i][j]==couleurAnalyse && i<DIM_PLATEAU);
			
				if(suite>=5 && gagnant==PERSONNE) gagnant=couleurAnalyse;
				else gain+=(suite*suite);				
			}
			i++;
			suite=0;
		}
		j++;
		i=0;
	}
	j=0;
	
	// Suite de billes de la même couleur sur la 1ere diagonale princiaple du plateau
		for(i=0 ; i<DIM_PLATEAU ; i++){		
			if(P[i][i]==couleurAnalyse){
			do{
				suite++;
				i++;
			} while(P[i][i]==couleurAnalyse && i<DIM_PLATEAU);
			
				if(suite>=5 && gagnant==PERSONNE) gagnant=couleurAnalyse;
				else gain+=(suite*suite);				
			}
			suite=0;
		}
	
	// Suite de billes de la même couleur sur l'autre princiaple du plateau
		for(i=0 ; i<DIM_PLATEAU ; i++){
			
			if(P[DIM_PLATEAU-1-i][i]==couleurAnalyse){
			do{
				suite++;
				i++;
			} while(P[DIM_PLATEAU-1-i][i]==couleurAnalyse && i<DIM_PLATEAU);
			
				if(suite>=5 && gagnant==PERSONNE) gagnant=couleurAnalyse;
				else gain+=(suite*suite);				
			}
			suite=0;
		}
	
	// Suite de billes de la même couleur sur la 3ème diagonale du plateau
		for(i=0 ; i<(DIM_PLATEAU-1) ; i++){
			
			if(P[i][i+1]==couleurAnalyse){
			do{
				suite++;
				i++;
			} while(P[i][i+1]==couleurAnalyse && i<(DIM_PLATEAU-1));
			
				if(suite>=5 && gagnant==PERSONNE) gagnant=couleurAnalyse;
				else gain+=(suite*suite);				
			}
			suite=0;
		}
	
	// Suite de billes de la même couleur sur la 4ème diagonale du plateau
		for(i=0 ; i<(DIM_PLATEAU-1) ; i++){
			
			if(P[i+1][i]==couleurAnalyse){
			do{
				suite++;
				i++;
			} while(P[i+1][i]==couleurAnalyse && i<(DIM_PLATEAU-1));
			
				if(suite>=5 && gagnant==PERSONNE) gagnant=couleurAnalyse;
				else gain+=(suite*suite);				
			}
			suite=0;
		}
	
	// Suite de billes de la même couleur sur la 5ème diagonale du plateau
		for(i=0 ; i<(DIM_PLATEAU-1) ; i++){
			
			if(P[DIM_PLATEAU-1-i][i+1]==couleurAnalyse){
			do{
				suite++;
				i++;
			} while(P[DIM_PLATEAU-1-i][i+1]==couleurAnalyse && i<(DIM_PLATEAU-1));
			
				if(suite>=5 && gagnant==PERSONNE) gagnant=couleurAnalyse;
				else gain+=(suite*suite);				
			}
			suite=0;
		}
	
	// Suite de billes de la même couleur sur la 5ème diagonale du plateau
		for(i=0 ; i<(DIM_PLATEAU-1) ; i++){
			
			if(P[DIM_PLATEAU-2-i][i]==couleurAnalyse){
			do{
				suite++;
				i++;
			} while(P[DIM_PLATEAU-2-i][i]==couleurAnalyse && i<(DIM_PLATEAU-1));
			
				if(suite>=5 && gagnant==PERSONNE) gagnant=couleurAnalyse;
				else gain+=(suite*suite);				
			}
			suite=0;
		}
	
	if(gagnant==couleurAnalyse) gain=2000;
	/*if(P[1][1]==couleurAnalyse) gain+=100;
	if(P[4][1]==couleurAnalyse) gain+=100;
	if(P[1][4]==couleurAnalyse) gain+=100;
	if(P[4][4]==couleurAnalyse) gain+=100;*/
	
	return(gain);

} // fin fonction calculGain

bool plateauVide(Plateau P, int partieTableau){
	
	int debutX, debutY, milieuX, milieuY, finX, finY, i=0, j=0;
	bool plateauVide = true;
	
	switch(partieTableau){
		
		case HAUT_GAUCHE:
			debutX=0;
			debutY=0;
			finX = DIM_PLATEAU/2;
			finY = DIM_PLATEAU/2;
			break;
		
		case HAUT_DROITE:
			debutX=DIM_PLATEAU/2;
			debutY=0;
			finX = DIM_PLATEAU;
			finY = DIM_PLATEAU/2;
			break;
		
		case BAS_GAUCHE:
			debutX=0;
			debutY=DIM_PLATEAU/2;
			finX = DIM_PLATEAU/2;
			finY = DIM_PLATEAU;
			break;
		
		case BAS_DROITE:
			debutX=DIM_PLATEAU/2;
			debutY=DIM_PLATEAU/2;
			finX = DIM_PLATEAU;
			finY = DIM_PLATEAU;
			break;

	}
	
	i=debutY;
	j=debutX;
	milieuY=i+1;
	milieuX=j+1;
	
	while(i<finY && plateauVide==true){
		while(j<finX && plateauVide==true){
			if(P[i][j]!=VIDE && (i!=milieuY || j!=milieuX)) {
				plateauVide=false;
			}
			j++;
		}
		i++;
		j=debutX;
	} 
	
	return(plateauVide);
}

short int alphaBeta(Plateau P, short int alpha, short int beta, short int profondeur){
// première itération de la fonction : profondeur = 1 , alpha = -200, beta = 200
// short int compteurFeuilles=0, feuillesRestantes=0, coupsPlus=0;
	
	short int m=0, t=0; // valeurs gain
	unsigned char i=0, j=0; // pour parcourir le plateau
	unsigned char f=0, g=0; // pour sauvegarder le meilleur coup possible
	unsigned char nombreEmplacementsVides=0;
	
	Coup leMeilleurCoupPossible;
	leMeilleurCoupPossible.ligne=-1;
	leMeilleurCoupPossible.colonne=-1;

	// Variables pour la gestion de rotation
	unsigned char k=0, sensRotation=0, sensOppose=0, partieTableau=0; // pour parcourir les rotations	
	unsigned char sensCoupFinal=0, partieTableauCoupFinal=0, ligneCoupFinal=0, colonneCoupFinal=0; // pour sauvegarder le meilleur coup possible
		
	// nombre d'emplacements vides sur le plateau
	for(i=0 ; i<DIM_PLATEAU ; i++){
		for(j=0 ; j<DIM_PLATEAU ; j++){
			if(P[i][j]==VIDE){
				nombreEmplacementsVides++;
				f=i; // si il reste un seul emplacement libre, il faudra jouer aux positions de f et g
				g=j;
			}
		}
	}
	
	// profondeur>= 4 car si profondeur>=3 : IA trop facile !
	// traitement de l'IA plus faible pour les premiers coups moins importants
	if(nombreEmplacementsVides>30 && profondeur>=3){
		return(evaluationPlateau(P));
	}
	
	else if(profondeur>=3 || nombreEmplacementsVides==0 || (estGagnant(P)!=PERSONNE)) {
		return(evaluationPlateau(P));
	}
	
	else{
		f=0, g=0;
		profondeur++;
		
		// si on est dans un noeud max (c'est au joueur noir de jouer)
		if(profondeur%2 != 0){ 

			m = alpha;
	
			// on simule le meilleur coups pour optimiser la coupe alpha beta
			meilleurCoup(P, NOIR, &leMeilleurCoupPossible);
			if(leMeilleurCoupPossible.ligne!=-1 && leMeilleurCoupPossible.colonne!=-1){
				P[leMeilleurCoupPossible.ligne][leMeilleurCoupPossible.colonne]=NOIR;
				
				k=0;
				while(k<8){

					if(k%2==0){
						sensRotation = SENS_HORAIRE;
						sensOppose = SENS_TRIGONOMETRIQUE;
					} else{
						sensRotation = SENS_TRIGONOMETRIQUE;
						sensOppose = SENS_HORAIRE;
					}
							
					if(k==0 || k==1) partieTableau = HAUT_DROITE;
					if(k==2 || k==3) partieTableau = BAS_DROITE;
					if(k==4 || k==5) partieTableau = BAS_GAUCHE;
					if(k==6 || k==7) partieTableau = HAUT_GAUCHE;
							
					rotation(P, sensRotation, partieTableau);

					t=alphaBeta(P,m,beta,profondeur);
					rotation(P, sensOppose, partieTableau);
					P[leMeilleurCoupPossible.ligne][leMeilleurCoupPossible.colonne]=VIDE;

					if(t>m){
						m=t;
						if(profondeur==1){
							f=leMeilleurCoupPossible.ligne;
							g=leMeilleurCoupPossible.colonne;
							sensCoupFinal=sensRotation;
							partieTableauCoupFinal=partieTableau;
						}
					}
					if(m>=beta && profondeur!=2){
							return(m);
					}
				
				k++;
				} // fin while

			}

			// deux boucles for pour parcourir le tableau
			for(i=0 ; i<DIM_PLATEAU ; i++){
				for(j=0 ; j<DIM_PLATEAU ; j++){
									
					// si case vide, on simule un coup
					if(P[i][j]==VIDE){
					
						// gestion des rotations
						for(k=0 ; k<8 ; k++){
						
							P[i][j]=NOIR;

							if(k%2==0){
								 sensRotation = SENS_HORAIRE;
								 sensOppose = SENS_TRIGONOMETRIQUE;
							} else{
								sensRotation = SENS_TRIGONOMETRIQUE;
								sensOppose = SENS_HORAIRE;
							}
							
							if(k==0 || k==1) partieTableau = HAUT_DROITE;
							if(k==2 || k==3) partieTableau = BAS_DROITE;
							if(k==4 || k==5) partieTableau = BAS_GAUCHE;
							if(k==6 || k==7) partieTableau = HAUT_GAUCHE;
									
						
							rotation(P, sensRotation, partieTableau);

				// rappel de la fonction alphabeta avec les nouvelles valeurs de paramètres, notamment profondeur qui a été incrémenté
								t = alphaBeta(P, m, beta, profondeur);
									
								// on annule le coup simulé			
								rotation(P, sensOppose, partieTableau);
								P[i][j]=VIDE;
									
								if(t>m){
									m=t;
									if(profondeur==1){
										// on mémorise le meilleur coup potentiel
										f=i;
										g=j;
										sensCoupFinal=sensRotation;
										partieTableauCoupFinal=partieTableau;
									}
								}
								if(m>=beta){
									 return(m);
								}
						} // fin while / for rotation
					} // fin if
				} // fin pour
			} // fin pour
			
			// après la remontée récursive, on joue le meilleur coups mémorisé
			if(profondeur==1){
 				P[f][g]=NOIR;
				rotation(P, sensCoupFinal, partieTableauCoupFinal);
			}
				
			return(m);
			
		}
		
		// si on est dans un noeud min
		else{ 
			
			m = beta;

			meilleurCoup(P, BLANC, &leMeilleurCoupPossible);
			if(leMeilleurCoupPossible.ligne!=-1 && leMeilleurCoupPossible.colonne!=-1){
				
				P[leMeilleurCoupPossible.ligne][leMeilleurCoupPossible.colonne]=BLANC;
				
				// gestion des rotations
				k=0;
				while(k<8){

					if(k%2==0){
						 sensRotation = SENS_HORAIRE;
						 sensOppose = SENS_TRIGONOMETRIQUE;
					} else{
						sensRotation = SENS_TRIGONOMETRIQUE;
						sensOppose = SENS_HORAIRE;
					}
							
					if(k==0 || k==1) partieTableau = HAUT_DROITE;
					if(k==2 || k==3) partieTableau = BAS_DROITE;
					if(k==4 || k==5) partieTableau = BAS_GAUCHE;
					if(k==6 || k==7) partieTableau = HAUT_GAUCHE;
							
					rotation(P, sensRotation, partieTableau);

					t=alphaBeta(P,alpha,m,profondeur);
					rotation(P,sensOppose, partieTableau);
					P[leMeilleurCoupPossible.ligne][leMeilleurCoupPossible.colonne]=VIDE;

					if(t<m) m=t;
					if(m<=alpha && profondeur!=2) return(m);
				
				k++;
				} // fin while

			}

			for(i=0 ; i<DIM_PLATEAU ; i++){
				for(j=0 ; j<DIM_PLATEAU ; j++){
					
					if(P[i][j]==VIDE){
						
						
						// gestion des rotations
						k=0;
						while(k<8){

							P[i][j]=BLANC;

							if(k%2==0){
								 sensRotation = SENS_HORAIRE;
								 sensOppose = SENS_TRIGONOMETRIQUE;
							} else{
								sensRotation = SENS_TRIGONOMETRIQUE;
								sensOppose = SENS_HORAIRE;
							}
							
							if(k==0 || k==1) partieTableau = HAUT_DROITE;
							if(k==2 || k==3) partieTableau = BAS_DROITE;
							if(k==4 || k==5) partieTableau = BAS_GAUCHE;
							if(k==6 || k==7) partieTableau = HAUT_GAUCHE;
							
							rotation(P, sensRotation, partieTableau);
		
							t = alphaBeta(P, alpha, m, profondeur);
							rotation(P,sensOppose, partieTableau);
							P[i][j]=VIDE;
								
							if(t<m) m=t;
							if(m<=alpha) return(m);
						k++;
						} // fin while
					} // fin if
				}// fin pour
			}// fin pour
			return(m);
		}
					
	}

} // fin fonction alphaBeta


void meilleurCoup(Plateau P, short int couleurAnalyse, Coup *meilleur){
	
	unsigned char i=0, j=0;
	unsigned char suite=0, k=0;
	bool bestMoove=false; // devient vrai si on trouve un placement qui fait gagner la partie
	unsigned char best=0;
	
	// Meilleur placement sur une ligne du plateau
	while(i<DIM_PLATEAU && bestMoove==false){
		
		while(j<DIM_PLATEAU && bestMoove==false){
			
			if(P[i][j]==couleurAnalyse){
			do{
				suite++;
				j++;
			} while(P[i][j]==couleurAnalyse && j<DIM_PLATEAU);
			
				if(suite>best && j<DIM_PLATEAU){
					if(P[i][j]==VIDE){
						meilleur->ligne=i;
						meilleur->colonne = j;
						best=suite;
						if(best==4) bestMoove=true;
					}
				}
			}
			
			j++;
			suite=0;
		}
		i++;
		j=0;
	}
	i=0;
	
	
	// Meilleur placement sur une colonne du plateau
	while(j<DIM_PLATEAU && bestMoove==false){
		while(i<DIM_PLATEAU && bestMoove==false){
			
			if(P[i][j]==couleurAnalyse){
			do{
				suite++;
				i++;
			} while(P[i][j]==couleurAnalyse && i<DIM_PLATEAU);
			
				if(suite>best && i<DIM_PLATEAU){
					if(P[i][j]==VIDE){
						 meilleur->ligne=i;
						 meilleur->colonne=j;
						 best=suite;
						 if(best==4) bestMoove=true;
					 }
				}
			}
			i++;
			suite=0;
		}
		j++;
		i=0;
	}
	
	j=0;

	// Meilleur placement sur la 1ere grande diagonale du plateau
		for(i=0 ; i<DIM_PLATEAU ; i++){		
			if(P[i][i]==couleurAnalyse){
			do{
				suite++;
				i++;
			} while(P[i][i]==couleurAnalyse && i<DIM_PLATEAU);
				if(suite>best && i<DIM_PLATEAU){
					if(P[i][i]==VIDE){
						meilleur->ligne=i;
						meilleur->colonne=i;
						best=suite;
						if(best==4) bestMoove=true;
					}
				}
			}
			suite=0;
		}
	
	// Meilleur placement sur l'autre grande diagonale du plateau
		for(i=0 ; i<DIM_PLATEAU ; i++){
			
			if(P[DIM_PLATEAU-1-i][i]==couleurAnalyse){
			do{
				suite++;
				i++;
			} while(P[DIM_PLATEAU-1-i][i]==couleurAnalyse && i<DIM_PLATEAU);
				if(suite>best && i<DIM_PLATEAU){
					if(P[DIM_PLATEAU-1-i][i]==VIDE){
						meilleur->ligne=(DIM_PLATEAU-1-i);
						meilleur->colonne=i;
						best=suite;
						if(best==4) bestMoove=true;
					}
				}
			}
			suite=0;
		}
	
	// Meilleur placement sur la 3ème diagonale du plateau
		for(i=0 ; i<(DIM_PLATEAU-1) ; i++){
			
			if(P[i][i+1]==couleurAnalyse){
			do{
				suite++;
				i++;
			} while(P[i][i+1]==couleurAnalyse && i<(DIM_PLATEAU-1));
				if(suite>best && i<(DIM_PLATEAU-1)){
					if(P[i][i+1]==VIDE){
						meilleur->ligne=i;
						meilleur->colonne=(i+1);
						best=suite;
						if(best==4) bestMoove=true;
					}
				}
			suite=0;
			}
		}
	
	// Meilleur placement sur la 4ème diagonale du plateau
		for(i=0 ; i<(DIM_PLATEAU-1) ; i++){
			
			if(P[i+1][i]==couleurAnalyse){
				do{
					suite++;
					i++;
				} while(P[i+1][i]==couleurAnalyse && i<(DIM_PLATEAU-1));
				
				if(suite>best && i<(DIM_PLATEAU-1)){
					if(P[i+1][i]==VIDE){
						meilleur->ligne=(i+1);
						meilleur->colonne=i;
						best=suite;
						if(best==4) bestMoove=true;
					}
				}
			}
			suite=0;
		}
	
	// Meilleur placement sur la 5ème diagonale du plateau
		for(i=0 ; i<(DIM_PLATEAU-1) ; i++){
			
			if(P[DIM_PLATEAU-1-i][i+1]==couleurAnalyse){
				do{
					suite++;
					i++;
				} while(P[DIM_PLATEAU-1-i][i+1]==couleurAnalyse && i<(DIM_PLATEAU-1));
				
				if(suite>best && i<(DIM_PLATEAU-1)){
					if(P[DIM_PLATEAU-1-i][i+1]==VIDE){
						meilleur->ligne=(DIM_PLATEAU-1-i);
						meilleur->colonne=(i+1);
						best=suite;
						if(best==4) bestMoove=true;
					}
				}
			}
			suite=0;
		}
	
	// Meilleur placement sur la 5ème diagonale du plateau
		for(i=0 ; i<(DIM_PLATEAU-1) ; i++){
			
			if(P[DIM_PLATEAU-2-i][i]==couleurAnalyse){
				do{
					suite++;
					i++;
				} while(P[DIM_PLATEAU-2-i][i]==couleurAnalyse && i<(DIM_PLATEAU-1));
				
				if(suite>best && i<(DIM_PLATEAU-1)){
					if(P[DIM_PLATEAU-2-i][i]==VIDE){
						meilleur->ligne=(DIM_PLATEAU-2-i);
						meilleur->colonne=i;
						best=suite;
						if(best==4) bestMoove=true;
					}
				}
			}
			suite=0;
		}
		
} // fin fonction meilleurCoup

