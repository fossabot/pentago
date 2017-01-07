# => commentaire
# Définition de variables

CFLAGS = -Wall -Wshadow -Wpointer-arith -Wcast-align -Wpadded
LIBS = `sdl-config --cflags --libs` -lSDLmain -lSDL -lSDL_image -lSDL_ttf -lm

# -Wall : Warning All pour afficher les nombreuses erreurs

SHELL_COURANT=`echo $$SHELL`

HEADERS=headers
SOURCES=sources
#BINS=bins
#----------------------------------------------------------------------------------------------

# Première  cible du fichier make
# En tappant la commande make dans le terminal cette cible est traitée

# A gauche des : c'est le nom de la cible , a droite c'est la dépendance ( cibles a traiter avant d'executer les commandes de la cible test)
# ces commandes sont écrites a la ligne suivante qui doit débuter par une tabulation

pentago: main.o partieUnJoueur.o partieDeuxJoueurs.o fonctionsAffichage.o fonctionsPlateau.o fonctionsIA.o
# La variable d'environnement doit être entre parenthèses dans la commande passée au shell.
# Les { } marchent aussi bien que les ( ), perso, je préfère utiliser {} pour les variables
# définies dans le Makefile, et les () pour les variables récupérées du shell.

# Le symbole @ précédent une commande empêche son affichage dans le terminal.
# Les magic quotes `...` permettent de récupérer le résultat de l'exécution d'une commande dans une variable.
	@SHELL_COURANT=`echo $$SHELL`; echo Vous utilisez le shell $$SHELL_COURANT
# $$SHELL équivaut à l'utilisation de $(SHELL).
# L'affectation de la variable n'est pas retenue sur plusieurs lignes, car make utilise un "sous-shell" pour chaque
# commande.
	@DOSSIER_COURANT=`pwd`;\
	echo Vous êtes dans le dossier $$DOSSIER_COURANT
# ou bien:
# 	@SHELL_COURANT=`echo $(SHELL)`; \
#	echo Vous utilisez le shell $$SHELL_COURANT

	@echo Edition de liens
	gcc ${WARNING_FLAGS} -o pentago main.o partieUnJoueur.o partieDeuxJoueurs.o fonctionsAffichage.o fonctionsPlateau.o fonctionsIA.o $(LIBS)

#----------------------------------------------------------------------------------------------
# Cette cible dépends de principal.c et makefile, donc si l'un de ces deux fichiers est modifé entre deux appels a make ,
# réexecute la commande qui suit
main.o: ${SOURCES}/main.c ${HEADERS}/constantes.h ${HEADERS}/fonctionsAffichage.h makefile
	gcc ${WARNING_FLAGS} -c ${SOURCES}/main.c

#----------------------------------------------------------------------------------------------

partieUnJoueur.o: ${SOURCES}/partieUnJoueur.c ${HEADERS}/partieUnJoueur.h ${HEADERS}/constantes.h ${HEADERS}/fonctionsPlateau.h makefile
	gcc ${WARNING_FLAGS} -c ${SOURCES}/partieUnJoueur.c

#----------------------------------------------------------------------------------------------

partieDeuxJoueurs.o: ${SOURCES}/partieDeuxJoueurs.c ${HEADERS}/partieDeuxJoueurs.h ${HEADERS}/constantes.h ${HEADERS}/fonctionsPlateau.h makefile
	gcc ${WARNING_FLAGS} -c ${SOURCES}/partieDeuxJoueurs.c

#----------------------------------------------------------------------------------------------

fonctionsAffichage.o: ${SOURCES}/fonctionsAffichage.c ${HEADERS}/fonctionsAffichage.h ${HEADERS}/constantes.h makefile
	gcc ${WARNING_FLAGS} -c ${SOURCES}/fonctionsAffichage.c

#----------------------------------------------------------------------------------------------

fonctionsPlateau.o: ${SOURCES}/fonctionsPlateau.c ${HEADERS}/fonctionsPlateau.h ${HEADERS}/constantes.h makefile
	gcc ${WARNING_FLAGS} -c ${SOURCES}/fonctionsPlateau.c

#----------------------------------------------------------------------------------------------

fonctionsIA.o: ${SOURCES}/fonctionsIA.c ${HEADERS}/fonctionsIA.h ${HEADERS}/constantes.h makefile
	gcc ${WARNING_FLAGS} -c ${SOURCES}/fonctionsIA.c

#----------------------------------------------------------------------------------------------

#cible qui nettoie le contenu du dossier courant
clean:
	rm -f *.o *~ core pentago

#----------------------------------------------------------------------------------------------
# rm remove
#-f forcé
# *.o n'importe quel fichier .o
# -~ résidus d'édition de texte
# Le fichier core est une copie du contenu de la mémoire au moment où le programme à planté
