#ifndef FONCTIONS_GRAPHIQUE_H
#define FONCTIONS_GRAPHIQUE_H

#define CASES_LIGNES 40
#define CASES_COLONNE 60

int deplacement(int Terrain[CASES_LIGNES][CASES_COLONNE], int direction, int Taille);

void attente(int milliseconds);

int ChangeDirection(int direction);

void addPomme(int Terrain[CASES_LIGNES][CASES_COLONNE], int Taille, int direction);

int deplacementPossible(int direction, int tete_x, int tete_y, int fin_x, int fin_y, int Taille,int Terrain[CASES_LIGNES][CASES_COLONNE] );

void GameOver(int Terrain[CASES_LIGNES][CASES_COLONNE]);

#endif
