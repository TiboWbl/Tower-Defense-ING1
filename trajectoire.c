#include "fichier.h"

// Traitement et affichage de la trajectoire des projectiles

void angle (int X_depart, int X_arrive, int Y_depart, int Y_arrive,double l, double* angle)
{
    if(Y_arrive>Y_depart)
    {
        *angle=-(acos((X_depart-X_arrive)/l))*180/3.14*0.7;
    }
    else
    {
        *angle=(acos((X_depart-X_arrive)/l))*180/3.14*0.7;
    }
}

void projectile (t_listeActeur * acteur, int indice)
{
    int i, b ;
    double d;
    /***************************************************TROUVER LES CIBLES***********************************************************************/

    for(i=0; i<acteur->tab[indice]->effectifdefense; i++)
    {

        if(acteur->tab[indice]->defense[i]->target==-1)
        {

            for(b=0; b<acteur->tab[indice]->effectifdefense; b++)
            {
                if(acteur->tab[1]->attaque[b]->vie>0)
                {

                    d=sqrt(pow(acteur->tab[indice]->defense[i]->positionY-acteur->tab[1]->attaque[b]->positionY,2)+pow(acteur->tab[1]->attaque[b]->positionX-acteur->tab[indice]->defense[i]->positionX,2));
                    //d=sqrt(pow(acteur->tab[indice]->defense[i]->positionY-acteur->tab[1]->attaque[b]->positionY,2)+pow(acteur->tab[1]->attaque[b]->positionX-acteur->tab[indice]->defense[i]->positionX,2));

                    if(d<150)
                    {
                        printf("cible trouvee\n");
                        acteur->tab[indice]->defense[i]->target=b;
                        b=10;
                    }

                }
            }
        }
        else
        {

            d=sqrt(pow(acteur->tab[indice]->defense[i]->positionX-acteur->tab[indice]->attaque[acteur->tab[indice]->defense[i]->target]->positionX,2)+pow(acteur->tab[indice]->attaque[acteur->tab[indice]->defense[i]->target]->positionY-acteur->tab[indice]->defense[i]->positionY,2));

            if((d>150)||(acteur->tab[1]->attaque[acteur->tab[4]->defense[i]->target]->vie<=1))
            {
                acteur->tab[indice]->defense[i]->target=-1;
                acteur->tab[indice]->defense[i]->temps=0;
                acteur->tab[indice]->defense[i]->projectileX=acteur->tab[indice]->defense[i]->positionY;
                acteur->tab[indice]->defense[i]->projectileY=acteur->tab[indice]->defense[i]->positionX;

            }
        }


    }





    /******************************************************TRAJECTOIRE***************************************************************************/

    for( i=0; i<acteur->tab[indice]->effectifdefense; i++)
    {

        if(acteur->tab[indice]->defense[i]->target!=-1)
        {

            if(acteur->tab[indice]->defense[i]->positionX>acteur->tab[1]->attaque[acteur->tab[indice]->defense[i]->target]->positionX)
            {

                if(acteur->tab[indice]->defense[i]->projectileX<acteur->tab[1]->attaque[acteur->tab[indice]->defense[i]->target]->positionX)
                {
                    acteur->tab[indice]->defense[i]->projectileY=acteur->tab[indice]->defense[i]->positionX;
                    acteur->tab[indice]->defense[i]->projectileX=acteur->tab[indice]->defense[i]->positionY;
                    acteur->tab[indice]->defense[i]->temps=0;
                    acteur->tab[1]->attaque[acteur->tab[4]->defense[i]->target]->vie--;


                }
            }
            else
            {
                if(acteur->tab[indice]->defense[i]->projectileX>acteur->tab[1]->attaque[acteur->tab[indice]->defense[i]->target]->positionX)
                {
                    acteur->tab[indice]->defense[i]->projectileY=acteur->tab[indice]->defense[i]->positionX;
                    acteur->tab[indice]->defense[i]->projectileX=acteur->tab[indice]->defense[i]->positionY;
                    acteur->tab[indice]->defense[i]->temps=0;
                    acteur->tab[1]->attaque[acteur->tab[4]->defense[i]->target]->vie--;
                }
            }
            d=sqrt(pow(acteur->tab[indice]->defense[i]->positionY-acteur->tab[1]->attaque[acteur->tab[indice]->defense[i]->target]->positionY,2)+pow(acteur->tab[1]->attaque[acteur->tab[indice]->defense[i]->target]->positionX-acteur->tab[indice]->defense[i]->positionX,2));
            acteur->tab[indice]->defense[i]->projectileX=(10*(acteur->tab[1]->attaque[acteur->tab[indice]->defense[i]->target]->positionX-acteur->tab[indice]->defense[i]->positionX)/d)*acteur->tab[indice]->defense[i]->temps+acteur->tab[indice]->defense[i]->positionX;
            acteur->tab[indice]->defense[i]->projectileY=(10*(acteur->tab[1]->attaque[acteur->tab[indice]->defense[i]->target]->positionY-acteur->tab[indice]->defense[i]->positionY)/d)*acteur->tab[indice]->defense[i]->temps+acteur->tab[indice]->defense[i]->positionY;
            angle (acteur->tab[indice]->defense[i]->projectileX+20,acteur->tab[1]->attaque[i]->positionX,acteur->tab[indice]->defense[i]->projectileY+50, acteur->tab[1]->attaque[i]->positionY,d, &acteur->tab[indice]->angle);
            //draw_sprite(image[0],acteur->tab[indice]->arme,acteur->tab[indice]->defense[i]->projectileX,acteur->tab[indice]->defense[i]->projectileY);
        }
    }
}
