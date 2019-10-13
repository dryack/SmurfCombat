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
/* SYSOP Maintenance Code: !-S-Y-S-O-P-!                          NXXGame  */
/* REMOTE Maintenance Code: !-SIX-NINE-|                           Module  */
/*                                                                         */
/***************************************************************************/







#define DOSMODEONLY
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include"smurfnxx.h"
#include"smurfnex.h"
#include"smurfgen.h"

int __NEW__noplayers;
extern int defrounds;
extern int turnsaday;

void __NEW__savegame(void){int thp;
  stream = fopen("SMURF.SGM", "w+");
     fprintf(stream, "%03i",__NEW__noplayers);
     fprintf(stream, "%05.5s",__saveversion);
  for(cyc=0;cyc<__NEW__noplayers;cyc++){if(__NEW__smurfturns[cyc]<0)__NEW__smurfturns[cyc]=0;if(__NEW__smurffights[cyc]<0)__NEW__smurffights[cyc]=0;thp=__NEW__smurfhpm[cyc];
     for(cyc2=0;cyc2<40;cyc2++)fprintf(stream, "%03i",__NEW__realname[cyc][cyc2]);
     fprintf(stream, "%010i",__NEW__realnumb[cyc]);
     for(cyc2=0;cyc2<40;cyc2++)fprintf(stream, "%03i",__NEW__smurfname[cyc][cyc2]);
     for(cyc2=0;cyc2<80;cyc2++)fprintf(stream, "%03i",__NEW__smurftext[cyc][cyc2]);
     for(cyc2=0;cyc2<40;cyc2++)fprintf(stream, "%03i",__NEW__smurfweap[cyc][cyc2]);
     for(cyc2=0;cyc2<40;cyc2++)fprintf(stream, "%03i",__NEW__smurfarmr[cyc][cyc2]);
     for(cyc2=0;cyc2<40;cyc2++)fprintf(stream, "%03i",__NEW__smurfettename[cyc][cyc2]);
     fprintf(stream, "%010i",__NEW__smurfettelevel[cyc]);
     fprintf(stream, "%010i",__NEW__smurfweapno[cyc]);
     fprintf(stream, "%010i",__NEW__smurfarmrno[cyc]);
     for(cyc3=0;cyc3<40;cyc3++)fprintf(stream, "%03i",__NEW__smurfconf[cyc][cyc3]);
     fprintf(stream, "%010i",__NEW__smurfconfno[cyc]);
for(cyc3=0;cyc3<10;cyc3++){
/*69d*/     fprintf(stream, "%010i",__NEW__smurfhost[cyc][cyc3]);}

//69a     fprintf(stream, "%010i",__NEW__smurfhost[cyc]);fprintf(stream, "%010i",__NEW__smurfhost1[cyc]);fprintf(stream, "%010i",__NEW__smurfhost2[cyc]);
     fprintf(stream, "%010i",__NEW__smurflevel[cyc]);
     fprintf(stream, "%020.0f",__NEW__smurfexper[cyc]);
     fprintf(stream, "%020.0f",__NEW__smurfmoney[cyc]);
     fprintf(stream, "%020.0f",__NEW__smurfbankd[cyc]);
     fprintf(stream, "%010i",__NEW__smurffights[cyc]);fprintf(stream, "%010i",__NEW__smurfwin[cyc]);fprintf(stream, "%010i",__NEW__smurflose[cyc]);
     fprintf(stream, "%010i",thp);fprintf(stream, "%010i",__NEW__smurfhpm[cyc]);
     fprintf(stream, "%010i",__NEW__smurfstr[cyc]);fprintf(stream, "%010i",__NEW__smurfspd[cyc]);fprintf(stream, "%010i",__NEW__smurfint[cyc]);
     fprintf(stream, "%010i",__NEW__smurfcon[cyc]);fprintf(stream, "%010i",__NEW__smurfbra[cyc]);fprintf(stream, "%010i",__NEW__smurfchr[cyc]);
     fprintf(stream, "%010i",__NEW__smurfturns[cyc]);

  /*91*/  fprintf(stream, "%03i%03i", __NEW____morale[cyc], __NEW____ettemorale[cyc]);

  for(cyc3=0;cyc3<5;cyc3++){
  /*69b*/ fprintf(stream, "%03i%03i",__NEW__smurfspcweapon[cyc][cyc3],__NEW__smurfqtyweapon[cyc][cyc3]); // 111222 - Special Weap Number / Qty
  }
  /*69c*/ fprintf(stream, "%03i",__NEW__smurfsex[cyc]); // 000/001/002 Nil/Mal/Fem

  }fclose(stream);
}





void __NEW__main(void){
getdate(&d);__NEW__noplayers=4;
clrscr();
textcolor(12);
cprintf("\n   S M U R F   C O M B A T\n\n\r");
textcolor(10);
cprintf("  New Game (Re-Roll) Module\n\r");
cprintf("        %sVersion %s\n\r",__vnewsp,__vnew);
cprintf("     By Laurence Maar\n\r");
textcolor(14);
cprintf("      AutoYea in 10secs\n\n\n\r");
textcolor(9);
cprintf("Proceed [Yn]: ");textcolor(12);
  if((stream=fopen("smurf.sgm", "r+"))==NULL)tcount=999;else fclose(stream);

  do{tcount++;
  delay(10);
  }while(!kbhit() && tcount<1000);
if(tcount>999)timeoud=1;else
  proc=getch();
if(proc!='Y' && proc!='y' && timeoud!=1){cprintf("Nope\n\r");return;}
if(timeoud!=1)cprintf("Yea\n\n\r");
if(timeoud==1)cprintf("Yea (Forced)\n\n\r");
  system("DEL SMURFLOG.*");
  system("DEL SMURFBAK.0*");
  system("DEL SMURFDAT.D0E");
//  system("DEL SMURF.S*");
stream = fopen("SMURF.SGM", "w+");fclose(stream);
gotoxy(1,12);
textcolor(13);  cprintf("Reading Configuration: ");
   if((stream = fopen("SMURF.CFG", "r+"))==NULL)
   {stream = fopen("SMURF.CFG", "w+");fprintf(stream,"01000311111990");fprintf(stream,"\n\r\n\r1. Arena Rounds/Day ###\n\r2. Turns/Day ###\n\r3. Last Ran Date DDMMYYYY\n\r");fclose(stream);}
   else
     {fscanf(stream,"%3s",intext);
      defrounds=atoi(intext);
      fscanf(stream,"%3s",intext);
      turnsaday=atoi(intext);
      fscanf(stream,"%8s",olddate);
      fclose(stream);
      sound(1000);
      stream = fopen("SMURF.CFG", "w+");
      fprintf(stream,"%03i",defrounds);
      fprintf(stream,"%03i",turnsaday);
      fprintf(stream,"01011990");
      fprintf(stream,"\n\r\n\r1. Arena Rounds/Day\n\r2. Turns/Day\n\r3. Last Ran Date DDMMYYYY\n\r");
      fclose(stream);
     }nosound();

   delay(500);textcolor(14);cprintf("Success.\n\r");

textcolor(13);  cprintf("Reading Defaults: ");
   delay(500);textcolor(14);cprintf("Success.\n\r");

textcolor(13);  cprintf("Reseting Variables: ");
sleep(1);textcolor(14);cprintf("Success.\n\r");

textcolor(13);cprintf("Writing Save Game File: ");
  cprintf("...");
delay(200);
	__NEW__savegame();
  cprintf("...");
  stream = fopen("SMURF.LOG", "w+");delay(200);
  fprintf(stream, "***** Smurf Combat 1995 ***** Version 2.00 Diassi Diassis Diablo\n\n\r");
  fprintf(stream, "Error Records -- In event of program malfunction, this file may be printed\n\r");
  fprintf(stream, "and mailed to Maartian Enterprises for evaluation along with a clear account\n\r");
  fprintf(stream, "of situation and any problems.\n\n\r");
  fprintf(stream, "------------------------------------------------------------------------------\n\n\r");
  fprintf(stream, "Computer Created and Controlled Characters :)\n\r");
  fprintf(stream, "[0-CPU] #1:) GRANDPA SMURF\n\r");
  fprintf(stream, "[0-CPU] #2:) PAPA SMURF\n\r");
  fprintf(stream, "[0-CPU] #3:) SHADOW SMURF\n\r");
  fprintf(stream, "[0-CPU] #4:) REBEL SMURF\n\n\r");
  fprintf(stream, "------------------------------------------------------------------------------\n\n\r");
//  fclose(stream);
  cprintf("...");
//  stream = fopen("SMURF.LOG", "a+");delay(200);
  fprintf(stream, "Error Records :) **********\n\n\r");
  fprintf(stream, "------------------------------------------------------------------------------\n\n\r");
  fprintf(stream, "MSDOS:) [SMURF RESET] Ran re-roll program successfully!\n\r");
  fclose(stream);
  cprintf("...");
textcolor(14);cprintf("Success.\n\r");

textcolor(13);cprintf("Writing Log Files: ");delay(200);
cprintf("...");
delay(200);
cprintf("...");
stream = fopen("SMURF.HST", "w+");fprintf(stream,"255255");fclose(stream);
textcolor(14);cprintf("Success.\n\r");
}
