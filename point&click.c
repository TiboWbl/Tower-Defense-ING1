#include "fichier.h"

void point_and_click (BITMAP * image[40], t_listeActeur * liste, int *etat_clic)
{
    int couldep=getpixel(image[10],mouse_x,mouse_y);
    int rdep=getr(couldep);
    int vdep=getg(couldep);
    int bdep=getb(couldep);
    draw_sprite(image[0],liste->tab[4]->image[1],30,510);

    if((liste->tab[4]->defense[liste->tab[4]->unite]->nombre_creation==2)||(liste->tab[4]->defense[liste->tab[4]->unite]->nombre_creation==3))
    {
        draw_sprite(image[0],liste->tab[4]->image[1],liste->tab[4]->defense[liste->tab[4]->unite]->positionX-30,liste->tab[4]->defense[liste->tab[4]->unite]->positionY-30);
    }
    if(((mouse_b&1)!=0)&&(rdep==255)&&(vdep==121)&&(bdep==0)&&(liste->tab[4]->defense[liste->tab[4]->unite]->nombre_creation==0))
    {
        printf("ert");
        liste->tab[4]->defense[liste->tab[4]->unite]->nombre_creation=1;
        (*etat_clic)=1;
        printf("selectione\n");
        rest(20);
        while(mouse_b&1)
        {
        }
    }
    if(((*etat_clic)==1)&&(liste->tab[4]->defense[liste->tab[4]->unite]->nombre_creation > 0)&&((mouse_b&1)==0))
    {
        printf("oui\n") ;
        liste->tab[4]->defense[liste->tab[4]->unite]->positionX=mouse_x;
        liste->tab[4]->defense[liste->tab[4]->unite]->positionY=mouse_y;
        liste->tab[4]->defense[liste->tab[4]->unite]->nombre_creation=2;
        rest(10);
    }
    if (((mouse_b&1)!=0)&&(liste->tab[4]->defense[liste->tab[4]->unite]->nombre_creation==2)&&(rdep==255)&&(vdep==255)&&(bdep==255))
    {
        printf("pose\n");
        liste->tab[4]->defense[liste->tab[4]->unite]->positionX=mouse_x-40;
        liste->tab[4]->defense[liste->tab[4]->unite]->positionY=mouse_y-50;
        //liste->tab[4]->projectileX=liste->tab[4]->defense[liste->tab[4]->unite]->positionX;
        //liste->tab[4]->projectileY=liste->tab[4]->defense[liste->tab[4]->unite]->positionY+200;
        liste->tab[4]->defense[liste->tab[4]->unite]->nombre_creation=3;
        liste->tab[4]->unite++;
        liste->tab[4]->effectifdefense++;
        (*etat_clic)=0;
        printf("%d",liste->tab[4]->unite);
        while((mouse_b&1)!=0)
        {
        }

    }


}

void point_and_click2 (BITMAP * image[40], t_listeActeur * liste, int *etat_clic)
{
    int couldep=getpixel(image[10],mouse_x,mouse_y);
    int rdep=getr(couldep);
    int vdep=getg(couldep);
    int bdep=getb(couldep);
    draw_sprite(image[0],liste->tab[2]->image[1],100,485);

    if((liste->tab[2]->defense[liste->tab[2]->unite]->nombre_creation==2)||(liste->tab[2]->defense[liste->tab[2]->unite]->nombre_creation==3))
    {
        draw_sprite(image[0],liste->tab[2]->image[1],liste->tab[2]->defense[liste->tab[2]->unite]->positionX-24,liste->tab[2]->defense[liste->tab[2]->unite]->positionY-24);
    }
    if(((mouse_b&1)!=0)&&(rdep==191)&&(vdep==1)&&(bdep==153)&&(liste->tab[2]->defense[liste->tab[2]->unite]->nombre_creation==0))
    {
        liste->tab[2]->defense[liste->tab[2]->unite]->nombre_creation=1;
        (*etat_clic)=1;
        printf("selectione\n");
        rest(20);
        while(mouse_b&1)
        {
        }
    }
    if(((*etat_clic)==1)&&(liste->tab[2]->defense[liste->tab[2]->unite]->nombre_creation > 0)&&((mouse_b&1)==0))
    {
        printf("oui\n") ;
        liste->tab[2]->defense[liste->tab[2]->unite]->positionX=mouse_x-40;
        liste->tab[2]->defense[liste->tab[2]->unite]->positionY=mouse_y-50;
        liste->tab[2]->defense[liste->tab[2]->unite]->nombre_creation=2;
        rest(10);
    }
    if (((mouse_b&1)!=0)&&(liste->tab[2]->defense[liste->tab[2]->unite]->nombre_creation==2)&&(rdep!=255)&&(vdep!=255)&&(bdep!=255))
    {
        printf("pose\n");
        liste->tab[2]->defense[liste->tab[2]->unite]->positionX=mouse_x-40;
        liste->tab[2]->defense[liste->tab[2]->unite]->positionY=mouse_y-50;
        liste->tab[2]->defense[liste->tab[2]->unite]->nombre_creation=3;
        liste->tab[2]->unite++;
        (*etat_clic)=0;
        printf("%d",liste->tab[2]->unite);
        while((mouse_b&1)!=0)
        {
        }

    }
}

void point_and_click3 (BITMAP * image[40], t_listeActeur * liste, int *etat_clic)
{
    int couldep=getpixel(image[10],mouse_x,mouse_y);
    int rdep=getr(couldep);
    int vdep=getg(couldep);
    int bdep=getb(couldep);
    draw_sprite(image[0],liste->tab[5]->image[1],240,502);

    if((liste->tab[5]->defense[liste->tab[5]->unite]->nombre_creation==2)||(liste->tab[5]->defense[liste->tab[5]->unite]->nombre_creation==3))
    {
        draw_sprite(image[0],liste->tab[5]->image[1],liste->tab[5]->defense[liste->tab[5]->unite]->positionX,liste->tab[5]->defense[liste->tab[5]->unite]->positionY);
    }
    if(((mouse_b&1)!=0)&&(rdep==149)&&(vdep==0)&&(bdep==192)&&(liste->tab[5]->defense[liste->tab[5]->unite]->nombre_creation==0))
    {
        liste->tab[5]->defense[liste->tab[5]->unite]->nombre_creation=1;
        (*etat_clic)=1;
        printf("selectione\n");
        rest(20);
        while(mouse_b&1)
        {
        }
    }
    if(((*etat_clic)==1)&&(liste->tab[5]->defense[liste->tab[5]->unite]->nombre_creation > 0)&&((mouse_b&1)==0))
    {
        printf("oui\n") ;
        liste->tab[5]->defense[liste->tab[5]->unite]->positionX=mouse_x-20;
        liste->tab[5]->defense[liste->tab[5]->unite]->positionY=mouse_y-50;
        liste->tab[5]->defense[liste->tab[5]->unite]->nombre_creation=2;
        rest(10);
    }
    if (((mouse_b&1)!=0)&&(liste->tab[5]->defense[liste->tab[5]->unite]->nombre_creation==2)&&(rdep==255)&&(vdep==255)&&(bdep==255))
    {
        printf("pose\n");
        liste->tab[5]->defense[liste->tab[5]->unite]->positionX=mouse_x-40;
        liste->tab[5]->defense[liste->tab[5]->unite]->positionY=mouse_y-50;
        liste->tab[5]->defense[liste->tab[5]->unite]->nombre_creation=3;
        liste->tab[5]->unite++;
        liste->tab[5]->effectifdefense++;
        (*etat_clic)=0;
        printf("%d",liste->tab[5]->unite);
        while((mouse_b&1)!=0)
        {
        }

    }
}

void point_and_click4 (BITMAP * image[40], t_listeActeur * liste, int *etat_clic)
{
    int couldep=getpixel(image[10],mouse_x,mouse_y);
    int rdep=getr(couldep);
    int vdep=getg(couldep);
    int bdep=getb(couldep);
    draw_sprite(image[0],liste->tab[6]->image[1],335,496);

    if((liste->tab[6]->defense[liste->tab[6]->unite]->nombre_creation==2)||(liste->tab[6]->defense[liste->tab[6]->unite]->nombre_creation==3))
    {
        draw_sprite(image[0],liste->tab[6]->image[1],liste->tab[6]->defense[liste->tab[6]->unite]->positionX,liste->tab[6]->defense[liste->tab[6]->unite]->positionY);
    }
    if(((mouse_b&1)!=0)&&(rdep==6)&&(vdep==0)&&(bdep==254)&&(liste->tab[6]->defense[liste->tab[6]->unite]->nombre_creation==0))
    {
        liste->tab[6]->defense[liste->tab[6]->unite]->nombre_creation=1;
        (*etat_clic)=1;
        printf("selectione\n");
        rest(20);
        while(mouse_b&1)
        {
        }
    }
    if(((*etat_clic)==1)&&(liste->tab[6]->defense[liste->tab[6]->unite]->nombre_creation > 0)&&((mouse_b&1)==0))
    {
        printf("oui\n") ;
        liste->tab[6]->defense[liste->tab[6]->unite]->positionX=mouse_x-20;
        liste->tab[6]->defense[liste->tab[6]->unite]->positionY=mouse_y-50;
        liste->tab[6]->defense[liste->tab[6]->unite]->nombre_creation=2;
        rest(10);
    }
    if (((mouse_b&1)!=0)&&(liste->tab[6]->defense[liste->tab[6]->unite]->nombre_creation==2)&&(rdep==255)&&(vdep==255)&&(bdep==255))
    {
        printf("pose\n");
        liste->tab[6]->defense[liste->tab[6]->unite]->positionX=mouse_x-40;
        liste->tab[6]->defense[liste->tab[6]->unite]->positionY=mouse_y-50;
        liste->tab[6]->defense[liste->tab[6]->unite]->nombre_creation=3;
        liste->tab[6]->unite++;
        liste->tab[6]->effectifdefense++;
        (*etat_clic)=0;
        printf("%d",liste->tab[6]->unite);
        while((mouse_b&1)!=0)
        {
        }

    }
}
