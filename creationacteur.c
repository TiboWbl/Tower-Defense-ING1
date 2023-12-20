#include "fichier.h"

// Allouer et initialiser une liste (vide) de acteur
t_listeActeur * creation_liste_acteur(int nombre_max_acteur)
{
    t_listeActeur * nouv;
    int i;

    nouv=(t_listeActeur *)malloc(1*sizeof(t_listeActeur));

    nouv->nombre_max=nombre_max_acteur;
    nouv->effectif=0;
    nouv->tab=(t_acteur **)malloc(nombre_max_acteur*sizeof(t_acteur*));

    for (i=0; i<nombre_max_acteur; i++)
        nouv->tab[i]=NULL;

    return nouv;
}
