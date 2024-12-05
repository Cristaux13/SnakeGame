#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "deplacement.h"

#define CYCLE 10000L
#define CASES_LIGNES 40
#define CASES_COLONNE 60
#define TAILLE_CASE 20
#define DELAI_MILLISECONDE 100




int deplacement(int Terrain[CASES_LIGNES][CASES_COLONNE], int direction, int Taille){
  /*
    Déplace les données du serpent dans le terrain selon la direction  données.
   */
  int ligne, colonne;
  int x, y;
  int tete_x, tete_y;
  int fin_x, fin_y;
  int TailleSerpent = Taille;

  for(ligne = 0; ligne < CASES_LIGNES; ligne++){
    for(colonne = 0; colonne < CASES_COLONNE; colonne++){
      if(Terrain[ligne][colonne] >= 1 && Terrain[ligne][colonne] <= Taille){
	if(Terrain[ligne][colonne] == 1){
	  x = colonne*TAILLE_CASE+TAILLE_CASE;
	  y = ligne*TAILLE_CASE+TAILLE_CASE;
	  ChoisirCouleurDessin(CouleurParComposante(30, 200, 0));
	  RemplirRectangle(x, y, 20, 20);

	  fin_x = ligne;
	  fin_y = colonne;
	}
	if(Terrain[ligne][colonne] == Taille){
	  tete_x = ligne;
	  tete_y = colonne;
	}
      }
    }
  }
  /* Vérifie si le déplacement est possible ou si le déplacement engendre un Game Over */
  TailleSerpent = deplacementPossible(direction, tete_x, tete_y, fin_x, fin_y, Taille, Terrain);
  
  
  return TailleSerpent;
}

int deplacementPossible(int direction, int tete_x, int tete_y, int fin_x, int fin_y, int Taille, int Terrain[CASES_LIGNES][CASES_COLONNE]){
  /*
    Vérifie si le déplacement selon la direction données engendre un Game Over, une pomme mangée ou rien.
   */
  int TailleSerpent = Taille;
  int ligne, colonne;

   switch(direction){
   case 1:
     /* Si la tête se trouve déjà le plus haut alors Game Over */
     if(tete_x == 0){
       GameOver(Terrain);
       break;
     /* S'il s'agit d'un corps du serpent */
     } else if(Terrain[tete_x-1][tete_y] > 0){
       GameOver(Terrain);
       break;
     /* S'il s'agit d'une pomme */
     } else if(Terrain[tete_x-1][tete_y] == -2){
       for(ligne = 0; ligne < CASES_LIGNES; ligne++){
	 for(colonne = 0; colonne < CASES_COLONNE; colonne++){
	   if(Terrain[ligne][colonne] >= 1 && Terrain[ligne][colonne] <= TailleSerpent){
	     Terrain[ligne][colonne]++;
	   }
	 }
       }
       Terrain[tete_x-1][tete_y] = TailleSerpent+2;
       Terrain[fin_x-1][fin_y] = 1;
       TailleSerpent++;
       TailleSerpent++;
       addPomme(Terrain, TailleSerpent, direction);
       break;
     /* S'il s'agit d'un obstacle */
     } else if(Terrain[tete_x-1][tete_y] == -1){
       GameOver(Terrain);
       break;
     /* Rien */
     } else {
       for(ligne = 0; ligne < CASES_LIGNES; ligne++){
	 for(colonne = 0; colonne < CASES_COLONNE; colonne++){
	   if(Terrain[ligne][colonne] >= 1 && Terrain[ligne][colonne] <= TailleSerpent){
	     Terrain[ligne][colonne]--;
	   }
	 }
       }
       Terrain[tete_x-1][tete_y] = TailleSerpent;
       break;
    }
   case 2 :
     if(tete_y == 59){
       GameOver(Terrain);
       break;
     } else if(Terrain[tete_x][tete_y+1] > 0){
       GameOver(Terrain);
       break;
     } else if(Terrain[tete_x][tete_y+1] == -2){
       for(ligne = 0; ligne < CASES_LIGNES; ligne++){
	 for(colonne = 0; colonne < CASES_COLONNE; colonne++){
	   if(Terrain[ligne][colonne] >= 1 && Terrain[ligne][colonne] <= TailleSerpent){
	     Terrain[ligne][colonne]++;
	   }
	 }
       }
       Terrain[tete_x][tete_y+1] = TailleSerpent+2;
       Terrain[fin_x][fin_y+1] = 1;
       TailleSerpent++;
       TailleSerpent++;
       addPomme(Terrain, TailleSerpent, direction);
       break;
     } else if(Terrain[tete_x][tete_y+1] == -1){
       GameOver(Terrain);
       break;
     } else {
       for(ligne = 0; ligne < CASES_LIGNES; ligne++){
	 for(colonne = 0; colonne < CASES_COLONNE; colonne++){
	   if(Terrain[ligne][colonne] >= 1 && Terrain[ligne][colonne] <= TailleSerpent){
	     Terrain[ligne][colonne]--;
	   }
	 }
       }
       Terrain[tete_x][tete_y + 1] = TailleSerpent;
       break;
     }
   case 3 :
     if(tete_x == 39){
       GameOver(Terrain);
       break;
     } else if(Terrain[tete_x+1][tete_y] > 0){
       GameOver(Terrain);
       break;
     } else if(Terrain[tete_x+1][tete_y] == -2){
       for(ligne = 0; ligne < CASES_LIGNES; ligne++){
	 for(colonne = 0; colonne < CASES_COLONNE; colonne++){
	   if(Terrain[ligne][colonne] >= 1 && Terrain[ligne][colonne] <= TailleSerpent){
	     Terrain[ligne][colonne]++;
	   }
	 }
       }
       Terrain[tete_x+1][tete_y] = TailleSerpent+2;
       Terrain[fin_x+1][fin_y] = 1;
       TailleSerpent++;
       TailleSerpent++;
       addPomme(Terrain, TailleSerpent, direction);
       break;
     } else if(Terrain[tete_x+1][tete_y] == -1){
       GameOver(Terrain);
       break;
     } else{
       for(ligne = 0; ligne < CASES_LIGNES; ligne++){
	 for(colonne = 0; colonne < CASES_COLONNE; colonne++){
	   if(Terrain[ligne][colonne] >= 1 && Terrain[ligne][colonne] <= TailleSerpent){
	     Terrain[ligne][colonne]--;
	   }
	 }
       }
       Terrain[tete_x+1][tete_y] = TailleSerpent;
       break;
     }
   case 4 :
     if(tete_y == 0){
       GameOver(Terrain);
       break;
     } else if(Terrain[tete_x][tete_y-1] > 0){
       GameOver(Terrain);
       break;
     } else if(Terrain[tete_x][tete_y-1] == -2){
       for(ligne = 0; ligne < CASES_LIGNES; ligne++){
	 for(colonne = 0; colonne < CASES_COLONNE; colonne++){
	   if(Terrain[ligne][colonne] >= 1 && Terrain[ligne][colonne] <= TailleSerpent){
	     Terrain[ligne][colonne]++;
	   }
	 }
       }
       Terrain[tete_x][tete_y-1] = TailleSerpent+2;
       Terrain[fin_x][fin_y-1] = 1;
       TailleSerpent++;
       TailleSerpent++;
       addPomme(Terrain, TailleSerpent, direction);
       break;
    } else if(Terrain[tete_x][tete_y-1] == -1){
       GameOver(Terrain);
       break;
     } else {
       for(ligne = 0; ligne < CASES_LIGNES; ligne++){
	 for(colonne = 0; colonne < CASES_COLONNE; colonne++){
	   if(Terrain[ligne][colonne] >= 1 && Terrain[ligne][colonne] <= TailleSerpent){
	     Terrain[ligne][colonne]--;
	   }
	 }
       }
       Terrain[tete_x][tete_y-1] = TailleSerpent;
       break;
     }
   }
   
   return TailleSerpent;
}

void attente(int milliseconds){
  /*
    Permet d'attendre un certain temps afin que le serpent n'aille pas trop vite sans que celui-ci soit saccadé et que le joueur puisse ainsi correctement joueur
   */
  clock_t start_time = clock();
  while((clock() - start_time) * 1000 / CLOCKS_PER_SEC < milliseconds){
    /* Attente */
  }
}

int ChangeDirection(int direction){
  /*
    Si une touche de déplacement est tapée, la direction change. La fonction renvoie la nouvelle direction :  1 pour en haut, 2 à droite, 3 en bas et 4 à gauche
   */
  int image = ChargerSprite("fleche.png");
  int t = direction;
  int pause = 0;
  
  
  if(ToucheEnAttente()){
    int touche = Touche();
    switch (touche){
    case XK_Right:
      if(t != 4){
	t = 2;
      }
      break;
    case XK_Down :
      if(t != 1){
	t = 3;
      }
      break;
    case XK_Left :
      if(t != 2){
	t = 4;
      }
      break;
    case XK_Up :
      if(t != 3){
	t = 1;
      }
      break;
    case XK_Escape :
      FermerGraphique();
      exit(EXIT_SUCCESS);
      break;
    case XK_space :
      pause = 1;
      ChoisirCouleurDessin(CouleurParNom("black"));
      RemplirRectangle(570, 850, 200, 70);
      
      ChoisirCouleurDessin(CouleurParNom("white"));
      EcrireTexte(600, 900, "PAUSE", 2);
      while(pause){
	touche = Touche();
	if(touche == XK_space){
	  ChoisirCouleurDessin(CouleurParNom("black"));
	  RemplirRectangle(600, 870, 110, 40);
	  AfficherSprite(image, 570,850);
	  pause = 0;
	}
	if(touche == XK_Escape){
	  FermerGraphique();
	  pause = 0;
	  exit(EXIT_SUCCESS);
	}
	
      }
      break;
    }
  }
  LibererSprite(image);
  return t;
}

void addPomme(int Terrain[CASES_LIGNES][CASES_COLONNE], int Taille, int direction){
  /*
    Si le serpent touche une pomme, la fonction permet d'en charger une nouvelle.
   */
  int x, y;
  int coord_x, coord_y;
  int add = 1;
  char score[8];
  int ligne, colonne, tete_x, tete_y;
  int image;


  while(add){
    x = rand()%CASES_LIGNES;
    y = rand()%CASES_COLONNE;

     if(Terrain[x][y] >= 1){
       /* Rien */
     } else if(Terrain[x][y] == -1){
       /* Rien */
     } else if(Terrain[x][y] == -2){
       /* Rien */
     } else {
       image = ChargerSprite("pomme.png");
       coord_x = y*TAILLE_CASE+TAILLE_CASE;
       coord_y = x*TAILLE_CASE+TAILLE_CASE;
       
       AfficherSprite(image, coord_x, coord_y);
       LibererSprite(image);
       
       Terrain[x][y] = -2;
       
       snprintf(score, 8, "%07d", ((Taille*5)-(10*5))/2);
       
       ChoisirCouleurDessin(CouleurParNom("black"));
       RemplirRectangle(1100, 870, 110, 40);
       
       ChoisirCouleurDessin(CouleurParNom("white"));
       EcrireTexte(1100, 900, score, 2);
       
       
       add = 0;
     }
  }
}

void GameOver(int Terrain[CASES_LIGNES][CASES_COLONNE]){
  /*
    Si le serpent touche un obstacle, lui-même ou une bordure, le jeu s'arrête et la fonction affiche un game over
   */
  int x, y;
  int coord_x, coord_y;
  int ligne, colonne;
  int loose = 1;

  for(ligne = 0; ligne < CASES_LIGNES; ligne++){
    for(colonne = 0; colonne < CASES_COLONNE; colonne++){
      coord_x = colonne*TAILLE_CASE+TAILLE_CASE;
      coord_y = ligne*TAILLE_CASE+TAILLE_CASE;

      ChoisirCouleurDessin(CouleurParNom("red"));
      RemplirRectangle(coord_x, coord_y, 20, 20);				    
    }
  }

  ChoisirCouleurDessin(CouleurParNom("green"));
  EcrireTexte(550, 425, "GAME OVER", 2);

  ChoisirCouleurDessin(CouleurParNom("black"));
  RemplirRectangle(570, 850, 200, 70);

  ChoisirCouleurDessin(CouleurParNom("white"));
  EcrireTexte( 400, 900, "Quitter : ECHAP", 2);
  
  while(loose){
    if(ToucheEnAttente()){
      int touche = Touche();
      switch (touche){
      case XK_Escape :
	FermerGraphique();
	exit(EXIT_SUCCESS);
      }
    }
  }
  
}
