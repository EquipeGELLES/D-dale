

#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
 
#include <ctype.h>
#pragma hdrstop
#include <tchar.h>
#pragma argsused
 
#define TOP     72      //numéros associés avec les touches fléchées 
#define GAUCHE  75 //
#define DROIT    77
#define BAS     80
#define ESC        27
#define ENTER      13



int backcolor=0;
int dir = 0;
int x=39,y=22;
int interieurx,interieury;
char tecla;
 
long int points = 0;
int vie = 3;

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
      0x007,
      0x00F,
     
       0x00D
     };
 
void gotoxy(int x, int y)  // fonction qui positionne le curseur sur la coordonnée (x,y)
{
    HANDLE hCon;
    COORD dwPos;
 
    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

char map[50][100] = {
     "                                                               ",
     "                    AXXXXXXXXXXXXXXXXXXXB AXXXXXXXXXXXXXXXXXXXB",
     "                    Y___________________Y Y___________________Y",
     "                    Y_AXXXXXB_AXXXXXXXB_Y Y_AXXXXXXXB_AXXXXXB_Y",
     "                    Y_Y     Y_Y       Y_Y Y_Y       Y_Y     Y_Y",
     "                    Y_DXXXXXC_DXXXXXXXC_DXC_DXXXXXXXC_DXXXXXC_Y",
     "                    Y________|_________|___|_________|________Y",
     "                    Y_AXXXXXB_AXB_AXXXXXXXXXXXXXB_AXB_AXXXXXB_Y",
     "                    Y_DXXXXXC_Y Y_DXXXXB   AXXXXC_Y Y_DXXXXXC_Y",
     "                    Y_________Y Y______Y   Y______Y Y_________Y",
     "                    DXXXXXXXB_Y DXXXXB_Y   Y_AXXXXC Y_AXXXXXXXC",
     "                            Y_Y AXXXXC_DXXXC_DXXXXB Y_Y        ",
     "                            Y_Y Y_________________Y Y_Y        ",
     "                    XXXXXXXXC_DXC_AXXXXXX XXXXXXB_DXC_DXXXXXXXX",
     "                    _________|____Y      *      Y____|_________",
     "                    XXXXXXXXB_AXB_DXXXXXXXXXXXXXC_AXB_AXXXXXXXX",
     "                            Y_Y Y_________________Y Y_Y        ",
     "                            Y_Y Y_AXXXXXXXXXXXXXB_Y Y_Y        ",
     "                    AXXXXXXXC_DXC_DXXXXB   AXXXXC_DXC_DXXXXXXXB",
     "                    Y________|_________Y   Y_________|________Y",
     "                    Y_AXXXXXB_AXXXXXXB_Y   Y_AXXXXXXB_AXXXXXB_Y",
     "                    Y_DXXXB Y_DXXXXXXC_DXXXC_DXXXXXXC_Y AXXXC_Y",
     "                    Y_____Y Y_________|_____|_________Y Y_____Y",
     "                    DXXXB_Y Y_AXB_AXXXXXXXXXXXXXB_AXB_Y Y_AXXXC",
     "                    AXXXC_DXC_Y Y_DXXXXB   AXXXXC_Y Y_DXC_DXXXB",
     "                    Y_________Y Y______Y   Y______Y Y_________Y",
     "                    Y_AXXXXXXXC DXXXXB_Y   Y_AXXXXC DXXXXXXXB_Y",
     "                    Y_DXXXXXXXXXXXXXXC_DXXXC_DXXXXXXXXXXXXXXC_Y",
     "                    Y_________________|_____|_________________Y",
     "                    DXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXC",
};
 
 
void pint_map()//Fonction qui  peint le bord de l'écran de jeux
{
     for(int i = 0 ; i < 78 ; i++){
         for(int j = 0 ; j < 30 ; j++){
               gotoxy(i,j);
 
               if(map[j][i] == 'X') {setCColor(color[0]);printf("%c",205);}
               if(map[j][i] == '_') {setCColor(color[7]); printf("%c",3);}
               else if(map[j][i] == 'Y') {setCColor(color[0]);printf("%c",186);}
               else if(map[j][i] == 'A') {setCColor(color[0]);printf("%c",201);}
               else if(map[j][i] == 'B') {setCColor(color[0]);printf("%c",187);}
               else if(map[j][i] == 'C') {setCColor(color[0]);printf("%c",188);}
               else if(map[j][i] == 'D') {setCColor(color[0]);printf("%c",200);}
 
 
         }
     }
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


class fontome{
      int fdir;
      int _x, _y;
      int col;
public:
      fontome(int x , int y , int color); // constructeur
      void dessin_fontome() const;
      void supp_fontome() const;
      void move_fontome();
      void choc_pacman();
};
fontome::fontome(int x , int y, int color){
      _x = x;
      _y = y;
      col = color;
      fdir = rand()%4;
}
void fontome::dessin_fontome() const{
 
     setCColor(color[col]);
     gotoxy(_x,_y); printf("%c",1);
}
void fontome::supp_fontome() const{
 
     gotoxy(_x,_y); printf(" ");
}
void fontome::choc_pacman(){
     if(y == _y && x == _x || (fdir == 0 && dir == 1 || fdir == 1 && dir == 0
     ||fdir == 2 && dir == 3 || fdir == 3 && dir == 2 )&&(_y == interieury && _x == interieurx)){
 
 
      x = 39;
      y = 22;
      dir = 4;
      vie--;
 
     }
 
 
}
 



void fontome::move_fontome(){
     supp_fontome();
     choc_pacman();
     int bolx=_x,boly=_y;
 
     if(map[_y][_x] == '|'){
             fdir = rand()%4;
     }
     if(map[_y][_x] == '*'){
             fdir = 0;
     }
 
     if(fdir == 2){
          if(map[_y][_x+1] != 'X' && map[_y][_x+1] != 'A' && map[_y][_x+1] != 'Y' &&
          map[_y][_x+1] != 'B' && map[_y][_x+1] != 'C' && map[_y][_x+1] != 'D')         _x++;
          else fdir = rand()%4;
     }
     if(fdir == 3){
          if(map[_y][_x-1] != 'X' && map[_y][_x-1] != 'A' && map[_y][_x-1] != 'Y' &&
          map[_y][_x-1] != 'B' && map[_y][_x-1] != 'C' && map[_y][_x-1] != 'D')          _x--;
          else fdir = rand()%4;
     }
     if(fdir == 0){
          if(map[_y-1][_x] != 'X' && map[_y-1][_x] != 'A' && map[_y-1][_x] != 'Y' &&
          map[_y-1][_x] != 'B' && map[_y-1][_x] != 'C' && map[_y-1][_x] != 'D')           _y--;
          else fdir = rand()%4;
     }
     if(fdir == 1){
          if(map[_y+1][_x] != 'X' && map[_y+1][_x] != 'A' && map[_y+1][_x] != 'Y' &&
      map[_y+1][_x] != 'B' && map[_y+1][_x] != 'C' && map[_y+1][_x] != 'D')                _y++;
          else fdir = rand()%4;
     }
 
     if(map[boly][bolx] == '_') {setCColor(color[7]); gotoxy(bolx,boly);printf("%c",3);}
 
     // rutina atajo
     if(_x <= 17) _x = 61;
        else if(_x >= 62) _x = 18;
     dessin_fontome();
}
 
 



   
  int main() { 
   
   
      
      fontome A(41,14,2);
   fontome B(43,14,3);
   fontome C(40,14,4);
   fontome D(39,14,5);
   pint_map();
      while(vie > 0 && points < 1950){
      duree();
      //borrar_pacman(x,y);
      interieurx = x; interieury = y;
 
 
      clear();
 
      if(dir == 0 && map[y-1][x] != 'X' && map[y-1][x] != 'A' && map[y-1][x] != 'Y' &&
      map[y-1][x] != 'B' && map[y-1][x] != 'C' && map[y-1][x] != 'D')                       y--;
 
 
      else if(dir == 1 && map[y+1][x] != 'X' && map[y+1][x] != 'A' && map[y+1][x] != 'Y' &&
      map[y+1][x] != 'B' && map[y+1][x] != 'C' && map[y+1][x] != 'D')                       y++;
 
 
      
     Sleep(70);
      
 
      B.choc_pacman();
      C.choc_pacman();
      D.choc_pacman();
      A.choc_pacman();
 
      //A.move_fontome();
      interieurx = x; interieury = y;
      clear();
 
 
      if(dir == 2 && map[y][x+1] != 'X' && map[y][x+1] != 'A' && map[y][x+1] != 'Y' &&
      map[y][x+1] != 'B' && map[y][x+1] != 'C' && map[y][x+1] != 'D')                       x++;
 
 
      else if(dir == 3 && map[y][x-1] != 'X' && map[y][x-1] != 'A' && map[y][x-1] != 'Y' &&
      map[y][x-1] != 'B' && map[y][x-1] != 'C' && map[y][x-1] != 'D')                         x--;
 
      A.move_fontome();
      B.move_fontome();
      C.move_fontome();
      D.move_fontome();
    
      Sleep(70);
 
     
 
 
   }
 
       system("pause>NULL");
   return 0; }
