#include "fichier.h"

// Allouer et ajouter une acteur � la liste
t_acteur * ajout_acteur(t_listeActeur *liste)
{
    int i;
    t_acteur * acteur;

    // Liste pleine, on alloue rien et on retourne NULL...
    if (liste->effectif >= liste->nombre_max)
        return NULL;

    // Allouer une acteur initialis�
    acteur=(t_acteur*)malloc(1*sizeof(t_acteur));

    // Chercher un emplacement libre
    i=0;
    while (liste->tab[i]!=NULL && i<liste->nombre_max)
        i++;

    // Si on a trouv� ...
    // (normalement oui car on a v�rifi� n<max)
    if (i<liste->nombre_max)
    {
        // Accrocher la acteur � l'emplacement trouv�
        liste->tab[i]=acteur;
        liste->effectif++;
    }
    // Sinon c'est qu'il y a un probl�me de coh�rence
    else
        allegro_message("Probleme liste acteur");

    return acteur;
}
