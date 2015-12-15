#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

#include <ctype.h>
#pragma hdrstop
#include <tchar.h>
#pragma argsused
 
#define TOP     72      //numéros associés avec les touches fléchées haut
#define GAUCHE  75 //
#define DROIT    77
#define BAS     80
#define ESC        27
#define ENTER      13

int backcolor=0;
int dir = 0;
int x=39,y=22;
int anteriorpx,anteriorpy;
char tecla;
 
long int points =-1;
int vie = 3;


void gotoxy(int x, int y)  // fonction qui positionne le curseur sur la coordonnée (x,y)
{
    HANDLE hCon;
    COORD dwPos;
 
    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}


void setCColor( int color)
{
        static HANDLE hConsole;
 
        hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
 
        SetConsoleTextAttribute( hConsole, color | (backcolor * 0x20 + 0x100) );
}

int color[8] = {
      0x010, //
      0x00E, // jaune
      0x00C, // rouge
      0x002,
      0x00B,
      0x005,
      0x00F,
      0x00D
 
     };



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
               if(map[j][i] == '_') {setCColor(color[7]); printf("%c",4);}
               else if(map[j][i] == 'Y') {setCColor(color[0]);printf("%c",186);}
               else if(map[j][i] == 'A') {setCColor(color[0]);printf("%c",201);}
               else if(map[j][i] == 'B') {setCColor(color[0]);printf("%c",187);}
               else if(map[j][i] == 'C') {setCColor(color[0]);printf("%c",188);}
               else if(map[j][i] == 'D') {setCColor(color[0]);printf("%c",200);}
 
 
         }
     }
}

void pacman(int x , int y){
     setCColor(color[1]);
     gotoxy(x,y); printf("%c",2);
}
 
void dessin_pacman(int x, int y){
     gotoxy(x,y); printf(" ");
     if(map[y][x] == '_'){ map[y][x] = ' '; points += 1;}
}

void clear(){
    if(kbhit()){
      tecla = getch();
      switch(tecla){
      case TOP:
         dir = 0;
         break;
 
      case BAS:
         dir = 1;
         break;
 
      case DROIT:
         dir = 2;
         break;
 
      case GAUCHE:
         dir = 3;
         break;
 
      }// FIN SWITCH
 
   }// FIN DE IF
 
}

void duree(){
     
 setCColor(color[1]);
   gotoxy(5,4); printf(" SCORE : ");
   gotoxy(5,6); printf("    ");
   setCColor(color[1]);
   gotoxy(5,6); printf("%ld",points);
 
   setCColor(color[1]);
   gotoxy(5,25); printf(" VIE :");
   for(int i = 0 ; i <= vie ; i++){
       gotoxy(5,i+27);
       printf(" ");
 
   }
 
 
}
 

 int main(){
     
     dessin_pacman(x,y);
     Sleep(55);
     pacman(x,y);
     pint_map();
     clear();
     duree();
 if(x < 17) {
        dessin_pacman(x,y);
        x = 61;
      }
      else if(x > 62){
        dessin_pacman(x,y);
        x= 18;
      }
      
      
     system("pause>NULL");
     return 0; 
    // getch();
     }
