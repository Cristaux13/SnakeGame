#ifndef INITIALISATION_H
#define INITIALISATION_H


#define CASES_LIGNES 40
#define CASES_COLONNE 60

void Initialisation();

void InitialisationSerpent(int Terrain[CASES_LIGNES][CASES_COLONNE]);

void InitialisationPomme(int Terrain[CASES_LIGNES][CASES_COLONNE], int Taille);

void InitialisationObstacle(int Terrain[CASES_LIGNES][CASES_COLONNE]);


#endif
