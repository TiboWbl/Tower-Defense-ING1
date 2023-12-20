#include "fichier.h"

void page0(int *page, BITMAP *buffer)
{
    textprintf_ex(buffer,font,350,70,makecol(0,0,0),-1,"MENU PRINCIPAL");
    textprintf_ex(buffer,font,384,150,makecol(115,8,0),-1,"JOUER");
    textprintf_ex(buffer,font,355,200,makecol(115,8,0),-1,"MODE D'EMPLOI");
    textprintf_ex(buffer,font,378,250,makecol(115,8,0),-1,"AUTEURS");
    textprintf_ex(buffer,font,378,300,makecol(115,8,0),-1,"QUITTER");
    if((mouse_x<=424 && mouse_x>=380) && (mouse_y<=162 && mouse_y>=150))
    {
        textprintf_ex(buffer,font,384,150,makecol(145,145,145),-1,"JOUER");
    }
    if((mouse_x<=462 && mouse_x>=355) && (mouse_y<=212 && mouse_y>=200))
    {
        textprintf_ex(buffer,font,355,200,makecol(145,145,145),-1,"MODE D'EMPLOI");
    }
    if((mouse_x<=435 && mouse_x>=378) && (mouse_y<=262 && mouse_y>=250))
    {
        textprintf_ex(buffer,font,378,250,makecol(145,145,145),-1,"AUTEURS");
    }
    if((mouse_x<=435 && mouse_x>=378) && (mouse_y<=312 && mouse_y>=300))
    {
        textprintf_ex(buffer,font,378,300,makecol(145,145,145),-1,"QUITTER");
    }
    if( mouse_b&1 && (mouse_x<=424 && mouse_x>=380) && (mouse_y<=162 && mouse_y>=150))
    {
        *page=1;
        rest(200);
    }
    else if( mouse_b&1 && (mouse_x<=462 && mouse_x>=355) && (mouse_y<=212 && mouse_y>=200))
    {
        *page=2;
    }
    else if( mouse_b&1 && (mouse_x<=462 && mouse_x>=355) && (mouse_y<=262 && mouse_y>=250))
    {
        *page=3;
    }
    else if( mouse_b&1 && (mouse_x<=462 && mouse_x>=355) && (mouse_y<=312 && mouse_y>=300))
    {
        allegro_exit();
        exit(0);
    }
}

void page1 (int *page, BITMAP *buffer, BITMAP *accueil)
{
    blit(accueil,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
    textprintf_ex(buffer,font,290,50,makecol(0,0,0),-1,"VEUILLEZ CHOISIR LE MODE DE JEU");
    textprintf_ex(buffer,font,375,150,makecol(115,8,0),-1,"NIVEAU 1");
    textprintf_ex(buffer,font,375,200,makecol(115,8,0),-1,"NIVEAU 2");
    textprintf_ex(buffer,font,375,250,makecol(115,8,0),-1,"NIVEAU 3");

    if((mouse_x<=440 && mouse_x>=375) && (mouse_y<=162 && mouse_y>=150))
    {
        textprintf_ex(buffer,font,375,150,makecol(145,145,145),-1,"NIVEAU 1");
    }
    if((mouse_x<=440 && mouse_x>=375) && (mouse_y<=212 && mouse_y>=200))
    {
        textprintf_ex(buffer,font,375,200,makecol(145,145,145),-1,"NIVEAU 2");
    }
    if((mouse_x<=440 && mouse_x>=375) && (mouse_y<=262 && mouse_y>=250))
    {
        textprintf_ex(buffer,font,375,250,makecol(145,145,145),-1,"NIVEAU 3");
    }
    if( mouse_b&1 && (mouse_x<=630 && mouse_x>=375) && (mouse_y<=162 && mouse_y>=150))
    {
        *page=4;
    }
    if( mouse_b&1 && (mouse_x<=440 && mouse_x>=375) && (mouse_y<=212 && mouse_y>=200))
    {
        *page=5;
    }
    if( mouse_b&1 && (mouse_x<=440 && mouse_x>=375) && (mouse_y<=262 && mouse_y>=250))
    {
        *page=6;
    }
}

void affichage (BITMAP * fond_jeu[10], t_listeActeur * liste)
{

    //for (liste->tab[0]->projectileX=liste->tab[0]->positionX ; liste->tab[0]->projectileX<=liste->tab[1]->positionX ; liste->tab[0]->projectileX++)
    //{
    clear_bitmap(fond_jeu[0]) ;
    blit(fond_jeu[1],fond_jeu[0],0,0,0,0,fond_jeu[1]->w,fond_jeu[1]->h) ;
    point_and_click(fond_jeu, liste,2) ;
    affichage_liste_acteur(fond_jeu[0], liste) ;
//        liste->tab[0]->projectileY = trajectoire_projectile(liste, liste->tab[0]->projectileX) ;
    //liste->tab[0]->projectileY=floor(liste->tab[0]->projectileY+0.5) ;
    //masked_blit(liste->tab[0]->arme,fond_jeu[0],0,0,liste->tab[0]->projectileX,liste->tab[0]->projectileY,liste->tab[0]->arme->w,liste->tab[0]->arme->h) ;
    blit(fond_jeu[0],screen,0,0,0,0,fond_jeu[0]->w,fond_jeu[0]->h) ;
    rest(10) ;
    //}
}

// Afficher sur la bitmap buffer l'ensemble des defenses
void affichage_liste_acteur(BITMAP * buffer, t_listeActeur *liste)
{
    int i;
    int j;
    for (i=0; i<liste->effectif; i++)
    {
        if (liste->tab[i]!=NULL)
        {
            for(j=0; j<liste->tab[i]->nombremax; j++)
                affichage_acteur(buffer,liste->tab[i],j);
        }
    }
}

// Afficher une acteur sur la bitmap buffer
void affichage_acteur(BITMAP * buffer, t_acteur * acteur, int j)
{
//    acteur->compteur++ ;
    if (acteur->compteur>=acteur->timing)
    {
        acteur->compteur=0;
        acteur->image_courante++;
    }
    if (acteur->image_courante > acteur->nombre_sprite)
    {
        acteur->image_courante=1;
    }

    draw_sprite(buffer,acteur->image[acteur->image_courante],acteur->defense[j]->positionX,acteur->defense[j]->positionY) ;
    rest(10) ;
}
