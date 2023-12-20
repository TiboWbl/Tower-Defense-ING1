#include "fichier.h"

BITMAP * ouverture_image (char nom_fichier[100])
{
    BITMAP * image ;
    image = load_bitmap(nom_fichier,NULL);

    if (image==NULL)
    {
        allegro_message("Erreur image %s",nom_fichier);
        exit(EXIT_FAILURE);
    }
    return image ;
}

void ouverture_sprite (t_listeActeur * liste, int i)
{
    int k ;
    for (k=1 ; k<=liste->tab[i]->nombre_sprite ; k++)
    {
        liste->tab[i]->image[k] = load_bitmap(liste->tab[i]->nom_fichier[k],NULL);

        if (liste->tab[i]->image[k]==NULL)
        {
            allegro_message("Erreur image %s",liste->tab[i]->nom_fichier[k]);
            exit(EXIT_FAILURE);
        }
    }
}
