#include "fichier.h"

// Allouer et ajouter une acteur à la liste
t_acteur * ajout_acteur(t_listeActeur *liste)
{
    int i;
    t_acteur * acteur;

    // Liste pleine, on alloue rien et on retourne NULL...
    if (liste->effectif >= liste->nombre_max)
        return NULL;

    // Allouer une acteur initialisé
    acteur=(t_acteur*)malloc(1*sizeof(t_acteur));

    // Chercher un emplacement libre
    i=0;
    while (liste->tab[i]!=NULL && i<liste->nombre_max)
        i++;

    // Si on a trouvé ...
    // (normalement oui car on a vérifié n<max)
    if (i<liste->nombre_max)
    {
        // Accrocher la acteur à l'emplacement trouvé
        liste->tab[i]=acteur;
        liste->effectif++;
    }
    // Sinon c'est qu'il y a un problème de cohérence
    else
        allegro_message("Probleme liste acteur");

    return acteur;
}
