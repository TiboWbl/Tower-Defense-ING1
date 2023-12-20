#include "fichier.h"

int main()
{
    BITMAP *image[40];
    BITMAP *Bombe[55];
    BITMAP *archer[23];
    BITMAP *tour[12];
    BITMAP *canon[26];
    BITMAP *piece[6];
    BITMAP *vie[5];
    BITMAP *sub;
    t_listeActeur * acteur;

    char nomfichier[100];
    int i=0;
    int k=0;
    int l=0;
    double d=0;
    int Page=0;
    int compteur=0;
    int x,y, b;
    int dx,dy;
    int tx,ty;
    int cptdx=0, tmpdx=1;
    int cptdy=0, tmpdy=1;
    int imgcourante=0;
    int cptimg=0, tmpimg;
    int couldep, rdep, vdep, bdep;
    int etat_clic=0 ;

    /*****************************************************INITIALISATION ALLEGRO************************************************************************/

    allegro_init();
    install_mouse();
    install_keyboard();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);

    /*********************************************************OUVERTURES BITMAP*************************************************************************/

    image[0]=create_bitmap(800,600);
    image[1]=ouverture_image("desert.bmp");
    image[2]=ouverture_image("jouer.bmp");
    image[3]=ouverture_image("parametre.bmp");
    image[4]=ouverture_image("menu.bmp");
    image[5]=ouverture_image("mine.bmp");
    image[6]=ouverture_image("cases.bmp");
    image[7]=ouverture_image("terrain.bmp");
    image[8]=ouverture_image("auteurs.bmp");
    image[9]=ouverture_image("bombe.bmp");
    image[10]=ouverture_image("bitmapfond.bmp");
    image[11]=ouverture_image("archer.bmp");
    image[12]=ouverture_image("tour.bmp");
    image[13]=ouverture_image("canon.bmp");
    image[14]=ouverture_image("barre-vie-jeu.bmp");
    sub=create_sub_bitmap(image[0],0,0,SCREEN_W,SCREEN_H);

    /*****************************************************INITIALISATION DES ACTEURS********************************************************************/

    acteur=creation_liste_acteur(50);

    /************************************************************CATAPULTE******************************************************************************/

    ajout_acteur(acteur);

    acteur->tab[0]->nombre_sprite=12 ;
    acteur->tab[0]->compteur=0 ;
    acteur->tab[0]->timing=10 ;
    acteur->tab[0]->image_courante=1 ;
    acteur->tab[0]->effectifdefense=0;
    //acteur->tab[0]->vie=1 ;

    for (i=1 ; i<=acteur->tab[0]->nombre_sprite ; i++)
    {
        sprintf(acteur->tab[0]->nom_fichier[i],"catapulte/Catapulte %d.bmp",i) ;
    }

    for (i=0 ; i<acteur->effectif ; i++)
    {
        ouverture_sprite(acteur, i) ;
    }

    /***************************************************************BOB*********************************************************************************/

    ajout_acteur(acteur);

    acteur->tab[1]->nombre_sprite=11;
    acteur->tab[1]->compteur=0 ;
    acteur->tab[1]->timing=5 ;
    acteur->tab[1]->image_courante=1;
    acteur->tab[1]->nombremax=10;
    acteur->tab[1]->unite=0;
    acteur->tab[1]->effectifattaque=0;
    for (i=0; i<100; i++)
    {
        acteur->tab[1]->attaque[i]=(t_information*)malloc(sizeof(t_information));
        acteur->tab[1]->attaque[i]->nombre_creation=0;
        acteur->tab[1]->attaque[i]->positionX=640;
        acteur->tab[1]->attaque[i]->positionY=538;
        acteur->tab[1]->attaque[i]->mouvementX=0;
        acteur->tab[1]->attaque[i]->mouvementY=2;
        acteur->tab[1]->attaque[i]->compteur2=1;
        acteur->tab[1]->attaque[i]->vie=5;
    }
    for (i=0 ; i<=acteur->tab[1]->nombre_sprite ; i++)
    {
        sprintf(acteur->tab[1]->nom_fichier[i],"bob/Soldat %i.bmp",i);
    }

    for (i=0 ; i<acteur->effectif ; i++)
    {
        ouverture_sprite(acteur, i) ;
        printf("Ouverture terminee\n") ;
    }

    /***************************************************************BOMBE*********************************************************************************/

    ajout_acteur(acteur);

    acteur->tab[2]->nombre_sprite=54 ;
    acteur->tab[2]->compteur=0 ;
    acteur->tab[2]->timing=5 ;
    acteur->tab[2]->image_courante=0 ;
    acteur->tab[2]->unite=1;
    //acteur->tab[2]->vie=1 ;
    //acteur->tab[2]->image[0]=0;

    for (i=0; i<100; i++)
    {
        acteur->tab[2]->defense[i]=(t_information*)malloc(sizeof(t_information));
        acteur->tab[2]->defense[i]->nombre_creation=0;
        acteur->tab[2]->defense[i]->compteur2=0;
    }

    for (i=0; i<10; i++)
    {
        sprintf(nomfichier,"gifbombe/frame_0%d_delay-0.03s.bmp",i);
        Bombe[i]=load_bitmap(nomfichier,NULL);
        if(!Bombe[i])
        {
            allegro_message("Echec image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    for ( i=10; i<55; i++)
    {
        sprintf(nomfichier,"gifbombe/frame_%d_delay-0.03s.bmp",i);
        Bombe[i]=load_bitmap(nomfichier,NULL);
        if(!Bombe[i])
        {
            allegro_message("Echec image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }
    i=0;

    for (i=0; i<55; i++)
    {
        acteur->tab[2]->image[i]=Bombe[i];
    }

    /*****************************************************************PIECE********************************************************************************/

    ajout_acteur(acteur);

    acteur->tab[3]->nombre_sprite=6 ;
    acteur->tab[3]->compteur=0 ;
    acteur->tab[3]->timing=5 ;
    acteur->tab[3]->image_courante=0 ;
    //acteur->tab[3]->vie=1 ;

    for (i=0; i<6; i++)
    {
        sprintf(nomfichier,"monnaie/frame_%d_delay-s.bmp",i);
        piece[i]=load_bitmap(nomfichier,NULL);
        if(!piece[i])
        {
            allegro_message("Echec image piece");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    /*****************************************************************ARCHER********************************************************************************/

    ajout_acteur(acteur);

    acteur->tab[4]->nombre_sprite=22 ;
    acteur->tab[4]->compteur=0 ;
    acteur->tab[4]->timing=5 ;
    acteur->tab[4]->image_courante=0 ;
    acteur->tab[4]->unite=0;
    acteur->tab[4]->effectifdefense=0;
    acteur->tab[4]->arme=ouverture_image("fleche.bmp");

    for (i=0; i<100; i++)
    {
        acteur->tab[4]->defense[i]=(t_information*)malloc(sizeof(t_information));
        acteur->tab[4]->defense[i]->nombre_creation=0;
        acteur->tab[4]->defense[i]->compteur2=0;
        acteur->tab[4]->defense[i]->temps=0;
        acteur->tab[4]->defense[i]->target=-1;

    }

    for (i=0; i<10; i++)
    {
        sprintf(nomfichier,"archer/frame_0%d_delay-0.01s.bmp",i);
        archer[i]=load_bitmap(nomfichier,NULL);
        if(!archer[i])
        {
            allegro_message("Echec image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    for ( i=10; i<23; i++)
    {
        sprintf(nomfichier,"archer/frame_%d_delay-0.01s.bmp",i);
        archer[i]=load_bitmap(nomfichier,NULL);
        if(!archer[i])
        {
            allegro_message("Echec image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }
    for (i=0; i<55; i++)
    {
        acteur->tab[4]->image[i]=archer[i];
    }

    /*****************************************************************TOUR********************************************************************************/

    ajout_acteur(acteur);

    acteur->tab[5]->nombre_sprite=11 ;
    acteur->tab[5]->compteur=0 ;
    acteur->tab[5]->timing=5 ;
    acteur->tab[5]->image_courante=0 ;
    acteur->tab[5]->unite=0;
    acteur->tab[5]->effectifdefense=0;

    for (i=0; i<100; i++)
    {
        acteur->tab[5]->defense[i]=(t_information*)malloc(sizeof(t_information));
        acteur->tab[5]->defense[i]->nombre_creation=0;
        acteur->tab[5]->defense[i]->compteur2=0;
    }

    for (i=0; i<10; i++)
    {
        sprintf(nomfichier,"tour/frame_0%d_delay-0.1s.bmp",i);
        tour[i]=load_bitmap(nomfichier,NULL);
        if(!tour[i])
        {
            allegro_message("Echec image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    for ( i=10; i<12; i++)
    {
        sprintf(nomfichier,"tour/frame_%d_delay-0.1s.bmp",i);
        tour[i]=load_bitmap(nomfichier,NULL);
        if(!tour[i])
        {
            allegro_message("Echec image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }
    for (i=0; i<12; i++)
    {
        acteur->tab[5]->image[i]=tour[i];
    }

    /*****************************************************************CANON********************************************************************************/

    ajout_acteur(acteur);

    acteur->tab[6]->nombre_sprite=25;
    acteur->tab[6]->compteur=0 ;
    acteur->tab[6]->timing=5 ;
    acteur->tab[6]->image_courante=0 ;
    acteur->tab[6]->unite=0;
    acteur->tab[6]->effectifdefense=0;

    for (i=0; i<100; i++)
    {
        acteur->tab[6]->defense[i]=(t_information*)malloc(sizeof(t_information));
        acteur->tab[6]->defense[i]->nombre_creation=0;
        acteur->tab[6]->defense[i]->compteur2=0;
    }

    for (i=0; i<10; i++)
    {
        sprintf(nomfichier,"canon/frame_0%d_delay-0.2s.bmp",i);
        canon[i]=load_bitmap(nomfichier,NULL);
        if(!canon[i])
        {
            allegro_message("Echec image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    for ( i=10; i<26; i++)
    {
        sprintf(nomfichier,"canon/frame_%d_delay-0.2s.bmp",i);
        canon[i]=load_bitmap(nomfichier,NULL);
        if(!canon[i])
        {
            allegro_message("Echec image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }
    for (i=0; i<26; i++)
    {
        acteur->tab[6]->image[i]=canon[i];
    }

    /****************************************************************VIE***********************************************************************************/

    ajout_acteur(acteur);

    for (i=0; i<5; i++)
    {
        sprintf(nomfichier,"barrevie/barre-vie-jeu%d.bmp",i);
        vie[i]=load_bitmap(nomfichier,NULL);
        if(!vie[i])
        {
            allegro_message("Echec image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }
    for (i=0; i<5; i++)
    {
        acteur->tab[7]->image[i]=vie[i];
    }

    /**********************************************************MISE A JOUR DES VARIABLES*******************************************************************/

    i=0;
    x=640;
    y=538;
    dx=0;
    dy=2;
    cptdy=0;
    tmpdy=1;
    imgcourante=0;
    cptimg=0;
    tmpimg=5;

    while (!key[KEY_ESC])
    {
        clear_bitmap(image[0]);

        if (Page==0)
        {
            blit(image[1],image[0],0,0,0,0,SCREEN_W,SCREEN_H);
            page0(&Page,image[0]);
        }

        if (Page==1)
        {
            page1(&Page,image[0],image[1]);
        }
        if (Page==3)
        {
            draw_sprite(image[0],image[8],0,0);
        }
        if (Page==4)
        {

            if(key[KEY_TAB])
            {
                blit(image[10],sub,0,0,0,0,SCREEN_W,SCREEN_H);
            }
            else
            {
                blit(image[7],sub,0,0,0,0,SCREEN_W,SCREEN_H);
            }

            /*****************************************AFFICHAGE EMPLACEMENT DEFENSE**********************************************************************/

            draw_sprite(image[0],image[3],710,5);
            draw_sprite(image[0],image[5],5,7);
            draw_sprite(image[0],image[6],10,475);
            textprintf_ex(image[0],font,21,487,makecol(0,0,0),-1,"PRIX :");
            draw_sprite(image[0],image[6],110,475);
            textprintf_ex(image[0],font,121,487,makecol(0,0,0),-1,"PRIX :");
            draw_sprite(image[0],image[6],210,475);
            textprintf_ex(image[0],font,221,487,makecol(0,0,0),-1,"PRIX :");
            draw_sprite(image[0],image[6],310,475);
            textprintf_ex(image[0],font,321,487,makecol(0,0,0),-1,"PRIX :");

            /*****************************************************AFFICHAGE DE LA PIECE******************************************************************/
            draw_sprite(image[0],piece[k%6],12,405);
            if (compteur%4==0)
            {
                k++;
            }
            compteur++;

            /*********************************************************POINT & CLICK**********************************************************************/

            point_and_click (image,acteur,&etat_clic);
            for (i=0; i<acteur->tab[4]->unite; i++)
            {
                draw_sprite(image[0],acteur->tab[4]->image[1],acteur->tab[4]->defense[i]->positionX+10,acteur->tab[4]->defense[i]->positionY+20);
            }


            point_and_click2 (image,acteur,&etat_clic);
            for (i=0; i<acteur->tab[2]->unite; i++)
            {
                if (acteur->tab[2]->defense[i]->vie!=0)
                {
                    draw_sprite(image[0],Bombe[acteur->tab[2]->defense[i]->compteur2%55],acteur->tab[2]->defense[i]->positionX-24,acteur->tab[2]->defense[i]->positionY-24);
                }
                if(acteur->tab[2]->defense[i]->compteur2%54==53)
                {
                    acteur->tab[2]->defense[i]->vie=0;
                }
                acteur->tab[2]->defense[i]->compteur2++;
            }
            l++;
            i=0;

            point_and_click3 (image,acteur,&etat_clic);
            for (i=0; i<acteur->tab[5]->unite; i++)
            {
                draw_sprite(image[0],acteur->tab[5]->image[1],acteur->tab[5]->defense[i]->positionX+20,acteur->tab[5]->defense[i]->positionY);
            }

            point_and_click4 (image,acteur,&etat_clic);
            for (i=0; i<acteur->tab[6]->unite; i++)
            {
                draw_sprite(image[0],acteur->tab[6]->image[1],acteur->tab[6]->defense[i]->positionX+20,acteur->tab[6]->defense[i]->positionY);
            }

            if( mouse_b&1 && (mouse_x<=780 && mouse_x>=710) && (mouse_y<=100 && mouse_y>=5))
            {
                Page=7;
            }
            i=0;

            /***************************************************TROUVER LES CIBLES***********************************************************************/

            for(int i=0; i<acteur->tab[4]->effectifdefense; i++)
            {

                if(acteur->tab[4]->defense[i]->target==-1)
                {

                    for(b=0; b<10; b++)
                    {
                        if(acteur->tab[1]->attaque[b]->vie>0)
                        {
                            d=sqrt(pow(acteur->tab[4]->defense[i]->positionY-acteur->tab[1]->attaque[b]->positionY,2)+pow(acteur->tab[1]->attaque[b]->positionX-acteur->tab[4]->defense[i]->positionX,2));

                            if(d<150)
                            {
                                printf("cible trouvee");
                                acteur->tab[4]->defense[i]->target=b;
                                b=10;
                            }
                        }
                    }
                }
                else
                {

                    d=sqrt(pow(acteur->tab[4]->defense[i]->positionY-acteur->tab[1]->attaque[b]->positionY,2)+pow(acteur->tab[1]->attaque[b]->positionX-acteur->tab[4]->defense[i]->positionX,2));

                    if((d>150)||(acteur->tab[1]->attaque[acteur->tab[4]->defense[i]->target]->vie<=1))
                    {

                        acteur->tab[4]->defense[i]->target=-1;
                        acteur->tab[4]->defense[i]->temps=0;
                        acteur->tab[4]->defense[i]->projectileY=acteur->tab[4]->defense[i]->positionX;
                        acteur->tab[4]->defense[i]->projectileX=acteur->tab[4]->defense[i]->positionY;
                    }
                }
            }


            /******************************************************TRAJECTOIRE***************************************************************************/

            for( i=0; i<acteur->tab[4]->effectifdefense; i++)
            {

                if(acteur->tab[4]->defense[i]->target!=-1)
                {

                    if(acteur->tab[4]->defense[i]->positionX>acteur->tab[1]->attaque[acteur->tab[4]->defense[i]->target]->positionX)
                    {

                        if(acteur->tab[4]->defense[i]->projectileX<acteur->tab[1]->attaque[acteur->tab[4]->defense[i]->target]->positionX)
                        {
                            acteur->tab[4]->defense[i]->projectileY=acteur->tab[4]->defense[i]->positionX;
                            acteur->tab[4]->defense[i]->projectileX=acteur->tab[4]->defense[i]->positionY;
                            acteur->tab[4]->defense[i]->temps=0;
                            acteur->tab[1]->attaque[acteur->tab[4]->defense[i]->target]->vie=acteur->tab[1]->attaque[acteur->tab[4]->defense[i]->target]->vie-1;

                        }
                    }
                    else
                    {
                        if(acteur->tab[4]->defense[i]->projectileX>acteur->tab[1]->attaque[acteur->tab[4]->defense[i]->target]->positionX)
                        {
                            acteur->tab[4]->defense[i]->projectileY=acteur->tab[4]->defense[i]->positionX;
                            acteur->tab[4]->defense[i]->projectileX=acteur->tab[4]->defense[i]->positionY;
                            acteur->tab[4]->defense[i]->temps=0;
                            acteur->tab[1]->attaque[acteur->tab[4]->defense[i]->target]->vie=acteur->tab[1]->attaque[acteur->tab[4]->defense[i]->target]->vie-1;
                        }
                    }
                    d=sqrt(pow(acteur->tab[4]->defense[i]->positionX-acteur->tab[1]->attaque[acteur->tab[4]->defense[i]->target]->positionX,2)+pow(acteur->tab[1]->attaque[acteur->tab[4]->defense[i]->target]->positionY-acteur->tab[4]->defense[i]->positionY,2));

                    acteur->tab[4]->defense[i]->projectileX=(3*(acteur->tab[1]->attaque[acteur->tab[4]->defense[i]->target]->positionX-acteur->tab[4]->defense[i]->positionX)/d)*acteur->tab[4]->defense[i]->temps+acteur->tab[4]->defense[i]->positionX;
                    acteur->tab[4]->defense[i]->projectileY=(3*(acteur->tab[1]->attaque[acteur->tab[4]->defense[i]->target]->positionY-acteur->tab[4]->defense[i]->positionY)/d)*acteur->tab[4]->defense[i]->temps+acteur->tab[4]->defense[i]->positionY;
                    angle (acteur->tab[4]->defense[i]->projectileX,acteur->tab[1]->attaque[i]->positionX,acteur->tab[4]->defense[i]->projectileY, acteur->tab[1]->attaque[i]->positionY,d, &acteur->tab[4]->angle);
                    rotate_sprite(image[0],acteur->tab[4]->arme,acteur->tab[4]->defense[i]->projectileX+20,acteur->tab[4]->defense[i]->projectileY+50,ftofix(acteur->tab[4]->angle));
                    acteur->tab[4]->defense[i]->temps++;
                }
            }

            /**************************************************CHANGEMENT SENS BOB***********************************************************************/

            if (acteur->tab[1]->unite < acteur->tab[1]->nombremax)
            {
                if (compteur%40==0)
                {
                    acteur->tab[1]->unite++;
                }
            }

            if (compteur==1000)
            {
                compteur=0;
            }

            for (i=0; i<acteur->tab[1]->unite; i++)
            {

                couldep=getpixel(image[10],acteur->tab[1]->attaque[i]->positionX+22,acteur->tab[1]->attaque[i]->positionY+22);
                rdep=getr(couldep);
                vdep=getg(couldep);
                bdep=getb(couldep);
                cptdy++;

                if (cptdy>=tmpdy)
                {
                    cptdy=0;
                    if((rdep==103)&&(vdep==0)&&(bdep==191))
                    {
                        acteur->tab[1]->attaque[i]->mouvementY=2;
                        acteur->tab[1]->attaque[i]->positionY-=acteur->tab[1]->attaque[i]->mouvementY;
                    }
                    if((rdep==254)&&(vdep==0)&&(bdep==0))
                    {
                        acteur->tab[1]->attaque[i]->mouvementX=2;
                        acteur->tab[1]->attaque[i]->mouvementY=0;
                        acteur->tab[1]->attaque[i]->positionX-=acteur->tab[1]->attaque[i]->mouvementX;
                    }
                    if((rdep==5)&&(vdep==192)&&(bdep==1))
                    {
                        acteur->tab[1]->attaque[i]->mouvementY=2;
                        acteur->tab[1]->attaque[i]->positionY+=acteur->tab[1]->attaque[i]->mouvementY;
                    }
                }

                cptimg++;
                if (cptimg>=tmpimg)
                {
                    cptimg=0;
                    acteur->tab[1]->attaque[i]->compteur2++;
                    // quand l'indice de l'image courante arrive à NIMAGE
                    // on recommence la séquence à partir de 0

                    if(((acteur->tab[1]->attaque[i]->compteur2)%11)==0)
                    {
                        acteur->tab[1]->attaque[i]->compteur2++;
                    }
                }
                if (acteur->tab[1]->attaque[i]->vie>0)
                {
                    if((acteur->tab[1]->attaque[i]->mouvementY!=0)||(acteur->tab[1]->attaque[i]->mouvementX!=0))
                    {
                        draw_sprite_h_flip(sub,acteur->tab[1]->image[(acteur->tab[1]->attaque[i]->compteur2)%11],acteur->tab[1]->attaque[i]->positionX,acteur->tab[1]->attaque[i]->positionY);
                        draw_sprite(sub,vie[acteur->tab[1]->attaque[i]->vie-1],acteur->tab[1]->attaque[i]->positionX+8,acteur->tab[1]->attaque[i]->positionY-6);
                    }
                }
            }

        }
        if(Page==7)
        {
            menu(&Page,image[0],image[4]);
        }
        blit(image[0],screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(30);
    }

    return 0;
}

END_OF_MAIN();

