#include "fichier.h"

void menu (int *page, BITMAP *buffer, BITMAP *Menu )
{
    clear_bitmap(buffer);
    blit(Menu,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
    textprintf_ex(buffer,font,380,50,makecol(204,85,0),-1,"MENU");
    textprintf_ex(buffer,font,360,150,makecol(0,0,0),-1,"CONTINUER");
    textprintf_ex(buffer,font,350,200,makecol(0,0,0),-1,"MODE D'EMPLOI");
    textprintf_ex(buffer,font,371,250,makecol(0,0,0),-1,"AUTEURS");
    textprintf_ex(buffer,font,371,300,makecol(0,0,0),-1,"QUITTER");

    if((mouse_x<=430 && mouse_x>=362) && (mouse_y<=162 && mouse_y>=150))
    {
        textprintf_ex(buffer,font,360,150,makecol(145,145,145),-1,"CONTINUER");
    }
    if((mouse_x<=462 && mouse_x>=355) && (mouse_y<=212 && mouse_y>=200))
    {
        textprintf_ex(buffer,font,350,200,makecol(145,145,145),-1,"MODE D'EMPLOI");
    }
    if((mouse_x<=435 && mouse_x>=378) && (mouse_y<=262 && mouse_y>=250))
    {
        textprintf_ex(buffer,font,371,250,makecol(145,145,145),-1,"AUTEURS");
    }
    if((mouse_x<=435 && mouse_x>=378) && (mouse_y<=312 && mouse_y>=300))
    {
        textprintf_ex(buffer,font,371,300,makecol(145,145,145),-1,"QUITTER");
    }
    if( mouse_b&1 && (mouse_x<=430 && mouse_x>=362) && (mouse_y<=162 && mouse_y>=150))
    {
        *page=1;
        rest(5);
    }
    if( mouse_b&1 && (mouse_x<=462 && mouse_x>=355) && (mouse_y<=212 && mouse_y>=200))
    {
        *page=2;
    }
    if( mouse_b&1 && (mouse_x<=435 && mouse_x>=378) && (mouse_y<=262 && mouse_y>=250))
    {
        *page=3;
    }
    if( mouse_b&1 && (mouse_x<=435 && mouse_x>=378) && (mouse_y<=312 && mouse_y>=300))
    {
        allegro_exit();
        exit(0);
    }
}
