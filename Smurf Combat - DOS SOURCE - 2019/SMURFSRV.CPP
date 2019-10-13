/*
Smurf Combat
Copyright (C) 1993, 1994, 2019 Laurence Maar
laurencemaar@gmail.com
https://www.facebook.com/laurencemaar/
https://www.linkedin.com/in/laurencemaar/
*/

/*
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

/***************************************************************************/
/*                                                                         */
/*   sss                       fff     ccc                 b               */
/*  s   s                     f   f   c   c                b               */
/*  s                         f       c                    b               */
/*   sss  mmm mmm  u   u r rr  fff    c      ooo  mmm mmm   bbb  aaa  ttt  */
/*      s m  m   m u   u rr   f       c     o   o m  m   m b   b a  a  t   */
/*  s   s m  m   m u  uu r    f       c   c o   o m  m   m b   b aaaa  t   */
/*   sss  m  m   m  uu u r    f        ccc   ooo  m  m   m  bbb  a  a  t   */
/*                                                                         */
/* SYSOP Maintenance Code: !-S-Y-S-O-P-!		        SERVICES   */
/* REMOTE Maintenance Code: !-SIX-NINE-|                          MODULE   */
/*                                                                         */
/***************************************************************************/

#include "smurfext.h"
#include <ctype.h>




void service(void){
  od_set_colour(11,0);
  od_printf("\n\n\r<<You are not powerful enough to join the Secret Service>>\n\n\r");
  pause();
}















void abilities(void){
  int r1,r2,r3,r4;
  char bbsin4[2];

  r1=smurfcon[thisuserno]/4;
  r2=smurfstr[thisuserno]/5;

  if(r1>=r2){r1=1;r2=1;}

  od_clr_scr();
  od_set_colour(L_RED,D_BLACK);  od_printf("   [ Swap Abilities ]\n\r");
  od_set_colour(D_CYAN,D_BLACK); od_printf("   Ratio: %d:%d\n\n\r",r1,r2);
  od_set_colour(D_GREEN,D_BLACK);
  od_printf(" (1) Strength     (%d)\n\r",smurfstr[thisuserno]);
  od_printf(" (2) Speed        (%d)\n\r",smurfspd[thisuserno]);
  od_printf(" (3) Intelligence (%d)\n\r",smurfint[thisuserno]);
  od_printf(" (4) Constitution (%d)\n\r",smurfcon[thisuserno]);
  od_printf(" (5) Bravery      (%d)\n\r",smurfbra[thisuserno]);
  od_printf(" (6) Charisma     (%d)\n\n\r",smurfchr[thisuserno]);

  od_set_colour(L_GREEN,D_BLACK);
  od_printf(" Increase Which: ");od_input_str(bbsin4,1,'1','6');r3=atoi(bbsin4);
  od_printf(" Decrease Which: ");od_input_str(bbsin4,1,'1','6');r4=atoi(bbsin4);

  od_set_colour(D_CYAN,D_BLACK);

  if((r4==1 && smurfstr[thisuserno]-r2<7) || (r4==2 && smurfspd[thisuserno]-r2<7) || (r4==3 && smurfint[thisuserno]-r2<7) || (r4==4 && smurfcon[thisuserno]-r2<7) || (r4==5 && smurfbra[thisuserno]-r2<7) || (r4==6 && smurfchr[thisuserno]-r2<7)){
    od_printf("\n\rNo value can go below 7\n\n\r");
    return;}

  if(r3<1 || r4<1 || r3==r4) {od_printf("\n\n\rNothing changed, laughing boy.\n\n\r");return;}

  od_printf("\n\rAre you sure? [yN]: ");
  bbsinkey=od_get_key(TRUE);
  od_set_colour(L_CYAN,D_BLACK);
  if(bbsinkey!='Y' && bbsinkey!='y'){od_printf("Nope\n\n\r");return;}
  od_printf("Yea\n\n\r");

if(r3==1)smurfstr[thisuserno]+=r1;
if(r3==2)smurfspd[thisuserno]+=r1;
if(r3==3)smurfint[thisuserno]+=r1;
if(r3==4)smurfcon[thisuserno]+=r1;
if(r3==5)smurfbra[thisuserno]+=r1;
if(r3==6)smurfchr[thisuserno]+=r1;
if(r4==1)smurfstr[thisuserno]-=r2;
if(r4==2)smurfspd[thisuserno]-=r2;
if(r4==3)smurfint[thisuserno]-=r2;
if(r4==4)smurfcon[thisuserno]-=r2;
if(r4==5)smurfbra[thisuserno]-=r2;
if(r4==6)smurfchr[thisuserno]-=r2;
}









void increasemorale(void){
__morale[thisuserno]--;
savegame();
od_set_colour(L_CYAN,D_BLACK);
od_printf("You gained morale!!!         \n\r");
}

void deductmorale(void){
__morale[thisuserno]++;
savegame();
od_printf("You lost morale!\n\r");
}

void deductettemorale(void){
__ettemorale[thisuserno]-=random(10);
savegame();
}



void __hit(int hit){
  od_set_colour(D_CYAN,D_BLACK);
  if(hit==0)od_printf("%s\n\r",__amiss[random(10)]);
  else
  od_printf("%s %i points!\n\r",__ahit[random(10)],hit);
  delay(300);
}

void __ehit(int hit, int numba){
  char *ref;
  ref=dataref3[smurfsex[numba]];
  if(numba==0)sprintf(ref,"It");
  od_set_colour(D_CYAN,D_BLACK);
  if(hit==0)od_printf("%s couldnt quite smurf you!\n\r",ref);
  else
  od_printf("He smurfed you for %i points!\n\r",hit);
  delay(300);
}













