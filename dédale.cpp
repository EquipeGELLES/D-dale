#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
 
#include <ctype.h>
#pragma hdrstop
#include <tchar.h>
#pragma argsused
 
#define ARRIBA     72 //pas     //numéros associés avec les touches fléchées
#define IZQUIERDA  75//pas
#define DERECHA    77//pas
#define ABAJO      80//pas
#define ESC        27
#define ENTER      13



int backcolor=0;
int x=39,y=22; 
long int point = 0;
int vie = 3;

void setCColor( int color)
{
        static HANDLE Console;
 
        Console = GetStdHandle( STD_OUTPUT_HANDLE );
 
        SetConsoleTextAttribute( Console, color | (backcolor * 0x20 + 0x100) );
}

int color[2] = {
      0x010, //la coleur  bleu
      0x00E, // la coleur jaune
     };
 
void gotoxy(int x, int y)  // fonction qui positionne le curseur sur la coordonnée (x,y)
{
    HANDLE Con;
    COORD Pos;
 
    Pos.X = x;
    Pos.Y = y;
    Con = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(Con,Pos);
}

char map[50][100] = {
     "                                                      ",
     "                  AXXXXXXXXXXXXXXXXXXXB AXXXXXXXXXXXXXXXXXXXB",
     "                  Y___________________Y Y___________________Y",
     "                  Y_AXXXXXB_AXXXXXXXB_Y Y_AXXXXXXXB_AXXXXXB_Y",
     "                  Y_Y     Y_Y       Y_Y Y_Y       Y_Y     Y_Y",
     "                  Y_DXXXXXC_DXXXXXXXC_DXC_DXXXXXXXC_DXXXXXC_Y",
     "                  Y________|_________|___|_________|________Y",
     "                  Y_AXXXXXB_AXB_AXXXXXXXXXXXXXB_AXB_AXXXXXB_Y",
     "                  Y_DXXXXXC_Y Y_DXXXXB   AXXXXC_Y Y_DXXXXXC_Y",
     "                  Y_________Y Y______Y   Y______Y Y_________Y",
     "                  DXXXXXXXB_Y DXXXXB_Y   Y_AXXXXC Y_AXXXXXXXC",
     "                          Y_Y AXXXXC_DXXXC_DXXXXB Y_Y        ",
     "                          Y_Y Y_________________Y Y_Y        ",
     "                  XXXXXXXXC_DXC_AXXXXXX XXXXXXB_DXC_DXXXXXXXX",
     "                  _________|____Y      *      Y____|_________",
     "                  XXXXXXXXB_AXB_DXXXXXXXXXXXXXC_AXB_AXXXXXXXX",
     "                          Y_Y Y_________________Y Y_Y        ",
     "                          Y_Y Y_AXXXXXXXXXXXXXB_Y Y_Y        ",
     "                  AXXXXXXXC_DXC_DXXXXB   AXXXXC_DXC_DXXXXXXXB",
     "                  Y________|_________Y   Y_________|________Y",
     "                  Y_AXXXXXB_AXXXXXXB_Y   Y_AXXXXXXB_AXXXXXB_Y",
     "                  Y_DXXXB Y_DXXXXXXC_DXXXC_DXXXXXXC_Y AXXXC_Y",
     "                  Y_____Y Y_________|_____|_________Y Y_____Y",
     "                  DXXXB_Y Y_AXB_AXXXXXXXXXXXXXB_AXB_Y Y_AXXXC",
     "                  AXXXC_DXC_Y Y_DXXXXB   AXXXXC_Y Y_DXC_DXXXB",
     "                  Y_________Y Y______Y   Y______Y Y_________Y",
     "                  Y_AXXXXXXXC DXXXXB_Y   Y_AXXXXC DXXXXXXXB_Y",
     "                  Y_DXXXXXXXXXXXXXXC_DXXXC_DXXXXXXXXXXXXXXC_Y",
     "                  Y_________________|_____|_________________Y",
     "                  DXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXC",
};
 
 
void pint_map()//Fonction qui  peint le bord de l'écran de jeux
{
     for(int i = 0 ; i < 78 ; i++){
         for(int j = 0 ; j < 30 ; j++){
               gotoxy(i,j);
 
               if(map[j][i] == 'X') {setCColor(color[0]);printf("%c",205);}
        
               else if(map[j][i] == 'Y') {setCColor(color[0]);printf("%c",186);}
               else if(map[j][i] == 'A') {setCColor(color[0]);printf("%c",201);}
               else if(map[j][i] == 'B') {setCColor(color[0]);printf("%c",187);}
               else if(map[j][i] == 'C') {setCColor(color[0]);printf("%c",188);}
               else if(map[j][i] == 'D') {setCColor(color[0]);printf("%c",200);}
 
 
         }
     }
}

void ecrire(){
     
 setCColor(color[1]);
   gotoxy(5,4); printf(" SCORE : ");
   gotoxy(5,6); printf("    ");
   setCColor(color[1]);
   gotoxy(5,6); printf("%ld",point);
 
   setCColor(color[1]);
   gotoxy(5,25); printf(" LA Vie :");
   for(int i = 0 ; i <= vie ; i++){
       gotoxy(5,i+27);
       printf(" ");
 
   }
   

 
 
}


int main(){

pint_map();
ecrire();


 
system("pause>NULL");
   return 0;
   getch();}
