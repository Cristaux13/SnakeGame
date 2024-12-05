#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "affichage.h"

#define CYCLE 10000L
#define CASES_LIGNES 40
#define CASES_COLONNE 60
#define TAILLE_CASE 20
#define DELAI_MILLISECONDE 100

void AffichageBasique(){
  /*
    Permet d'afficher le terrain vert à la bonne dimension.
   */
  int image = ChargerSprite("fleche.png");
  ChoisirCouleurDessin(CouleurParComposante(30, 200, 0));
  RemplirRectangle(20, 20, 1200, 800);

  AfficherSprite(image, 570,850);
  LibererSprite(image);
}

void AfficheTemps(int minute, int seconde){
  /*
    Permet d'afficher les minutes et secondes au bon format.
   */
  char temps[6];
  snprintf(temps, 6, "%02d:%02d", minute, seconde);

  ChoisirCouleurDessin(CouleurParNom("black"));
  RemplirRectangle(20, 870, 70, 40);
  
  ChoisirCouleurDessin(CouleurParNom("white"));
  EcrireTexte(20, 900, temps, 2);
}

void NewEmplacementSerpent(int Terrain[CASES_LIGNES][CASES_COLONNE], int Taille){
  /*
    Permet d'afficher le serpent à partir des données du terrain.
   */
  int ligne, colonne;
  int x, y;
  
  
  
  for(ligne = 0; ligne < CASES_LIGNES; ligne++){
    for(colonne = 0; colonne < CASES_COLONNE; colonne++){
      if(Terrain[ligne][colonne] >= 1 && Terrain[ligne][colonne] <= Taille){
	x = colonne*TAILLE_CASE+TAILLE_CASE;
	y = ligne*TAILLE_CASE+TAILLE_CASE;

	ChoisirCouleurDessin(CouleurParComposante(30, 200, 0));
	RemplirRectangle(x, y, 20, 20);
        
	
	ChoisirCouleurDessin(CouleurParComposante(235, 254, 0));
	RemplirRectangle(x, y, 20, 20);
        
      }
    }
  }
}
