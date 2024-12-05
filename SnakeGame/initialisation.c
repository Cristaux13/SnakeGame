#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "initialisation.h"

#define CYCLE 10000L
#define CASES_LIGNES 40
#define CASES_COLONNE 60
#define TAILLE_CASE 20
#define DELAI_MILLISECONDE 100


void Initialisation(){
  /*
    Avant de joueur, la fonction permet d'initialiser le graphique et de la fenêtre.
   */
  InitialiserGraphique();
  CreerFenetre(175, 80, 1240, 940);
  EcrireTexte(500, 400, "Le jeu va commencer !", 2);
  sleep(3);

  EffacerEcran(CouleurParNom("black"));
}

void InitialisationSerpent(int Terrain[CASES_LIGNES][CASES_COLONNE]){
  /*
    Initialise les données du serpent dans le terrain.
   */
  int ligne, colonne;
  int corps = 1;
  
  for(ligne = 0; ligne < CASES_LIGNES; ligne++){
    for(colonne = 0; colonne < CASES_COLONNE; colonne++){
      if(ligne == 20 && (colonne >= 15 && colonne < 25)){
	Terrain[ligne][colonne] = corps;
	corps++;
      } else {
	Terrain[ligne][colonne] = 0;
      }
    }
  }
}

void InitialisationObstacle(int Terrain[CASES_LIGNES][CASES_COLONNE]){
  /*
    Initialise les positions aléatoirement des obstacles dans le terrain et les affiches aux bonnes coordonnées
   */
  int image;
  int nb_Obstacle = 0;
  int x, coord_x;
  int y, coord_y;
  
  
  while(nb_Obstacle != 15){
    image = ChargerSprite("obstacle.png");
    x = rand()%CASES_LIGNES;
    y = rand()%CASES_COLONNE;
    
    
    if(Terrain[x][y] == 0){
      coord_x = y*TAILLE_CASE+TAILLE_CASE;
      coord_y = x*TAILLE_CASE+TAILLE_CASE;
       
      AfficherSprite(image, coord_x, coord_y);
      LibererSprite(image);
      Terrain[x][y] = -1;
      
      nb_Obstacle++;
    }
  } 
}

void InitialisationPomme(int Terrain[CASES_LIGNES][CASES_COLONNE], int Taille){
  /*
    Initialie les positions des pommes aléatoirement dans le terrain et les affiches aux bonnes coordonnées.
   */
  int image;
  int nb_pomme = 0;
  int x, coord_x;
  int y, coord_y;


  while(nb_pomme != 5){
    image = ChargerSprite("pomme.png");
    x = rand()%CASES_LIGNES;
    y = rand()%CASES_COLONNE;

    
    if(Terrain[x][y] == 0){
      coord_x = y*TAILLE_CASE+TAILLE_CASE;
      coord_y = x*TAILLE_CASE+TAILLE_CASE;
      
      AfficherSprite(image, coord_x, coord_y);

      Terrain[x][y] = -2;

      LibererSprite(image);
      nb_pomme++;
    }
  }  
}
