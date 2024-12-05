#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "affichage.h"
#include "deplacement.h"
#include "initialisation.h"

#define CYCLE 10000L
#define CASES_LIGNES 40
#define CASES_COLONNE 60
#define TAILLE_CASE 20
#define DELAI_MILLISECONDE 100

int main(void){
  /* Boucle infinie pour le jeu */
  int boucle_on = 1;

  /* Données pour le temps */
  unsigned long int suivant;
  int temps[2] = {0, 0}, seconde_actuel, old_seconde;

  /*
    Données pour le terrain :
    1...TailleSerpent équivaut aux valeurs ou est situé le serpent
    -1 Un obstacle
    -2 Une pomme
  */
  int Terrain[CASES_LIGNES][CASES_COLONNE];

  /* Données pour le serpent */
  int Taille = 10, corps = 1, direction = 2;
  int score = 0;

  srand(time(NULL));

  /* Lancement du jeu */
  Initialisation();
  AffichageBasique();

  /* Initialisation des données du terrain */
  InitialisationSerpent(Terrain);
  InitialisationPomme(Terrain, Taille);
  InitialisationObstacle(Terrain);

  suivant = Microsecondes()+CYCLE;
  old_seconde = (suivant/100000)%10;

  while(boucle_on){


    /* Calcul du temps */
    if(Microsecondes() > suivant){
      suivant = Microsecondes()+CYCLE;
      seconde_actuel = (suivant/1000000)%10;
      if(seconde_actuel != old_seconde){
	old_seconde = seconde_actuel;
	if((temps[1] + 1) == 60){
	  temps[0]++;
 	  temps[1] = 0;
	} else {
	  temps[1]++;
	}
	/* Affiche Temps */
	AfficheTemps(temps[0], temps[1]);
      }
    }
    
    /* Déplacement du serpent dans les données */
    Taille = deplacement(Terrain, direction, Taille);
    
    /* Affichage du serpent avec les données */
    NewEmplacementSerpent(Terrain, Taille);
   
    

    attente(DELAI_MILLISECONDE);

    /* Si nouvelle direction, alors changement de la direction */
    direction = ChangeDirection(direction);
  }
  return EXIT_SUCCESS;
}

