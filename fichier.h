#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>
#include<math.h>
#define NXMAP 25
#define NYMAP 20
#define NTUILE 500

/********************************************************************* STRUCTURES *************************************************************************/

typedef struct information
{
    int nombre_creation;
    int positionX;
    int positionY;
    int mouvementX ;
    int mouvementY ;
    int projectileX;
    int projectileY;
    int vie;
    int degats;
    int temps;
    int target;
    int compteur2;


} t_information;

typedef struct acteur
{
    BITMAP * image[100];
    BITMAP * arme;
    int nombre_sprite ;
    char nom_fichier[100][100];
    int mouvementX ;
    int mouvementY ;
    int cadence_tir;
    int compteur;
    int timing;
    double angle;
    int image_courante;
    int portee;
    int bare;
    int nombremax;
    int temps;
    int unite;
    int effectifdefense;
    int effectifattaque;
    t_information *defense[100];
    t_information *attaque[100];
} t_acteur;


typedef struct listeActeur
{
    // nombre maxi d'éléments
    // =taille du tableau de pointeurs
    int nombre_max;

    // nombre effectif de pointeurs utilisés
    // (les autres sont à NULL)key[KEY_ESC]
    int effectif;


    // le tableau de pointeurs (alloué dynamiquement)
    t_acteur **tab;

} t_listeActeur;

/********************************************************************* SOUS-PROGRAMMES *************************************************************************/

void page0(int *page, BITMAP *buffer);
void page1 (int *page, BITMAP *buffer, BITMAP *accueil);
void menu (int *page, BITMAP *buffer, BITMAP *Menu);

t_listeActeur * creation_liste_acteur(int nombre_max_acteur) ;
t_acteur * ajout_acteur(t_listeActeur *liste) ;

void mouvement_acteur(t_acteur *acteur) ;
void mouvement_liste_acteur(t_listeActeur *liste) ;

void suppression_acteur(t_listeActeur * liste, int i) ;

void affichage_acteur(BITMAP * buffer, t_acteur * acteur, int j);
void affichage_liste_acteur(BITMAP * buffer, t_listeActeur *liste) ;
void affichage (BITMAP * fond_jeu[10], t_listeActeur * liste) ;

BITMAP * ouverture_image (char nom_fichier[100]) ;
void ouverture_sprite (t_listeActeur * liste, int i) ;

void angle (int X_depart, int X_arrive, int Y_depart, int Y_arrive,double l, double* angle);

void point_and_click (BITMAP * image[40], t_listeActeur * liste, int *etat_clic);
void point_and_click2 (BITMAP * image[40], t_listeActeur * liste, int *etat_clic);
void point_and_click3 (BITMAP * image[40], t_listeActeur * liste, int *etat_clic);
void point_and_click4 (BITMAP * image[40], t_listeActeur * liste, int *etat_clic);


#endif // FICHIER_H_INCLUDED
