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

#define DOSMODEONLY
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include"smurfnew.h"
#include"smurfgen.h"
#include"smurfver.h"
#include"smurfsav.h"

void main(void){
getdate(&d);noplayers=4;
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
stream = fopen("SMURF.SGM", "w+");
textcolor(13);  cprintf("Checking Configuration: ");
   if((stream = fopen("SMURF.CFG", "r+"))==NULL)
   {stream = fopen("SMURF.CFG", "w+");fprintf(stream,"01000311111990");fprintf(stream,"\n\r\n\r1. Arena Rounds/Day ###\n\r2. Turns/Day ###\n\r3. Last Ran Date DDMMYYYY\n\r");fclose(stream);}
   else
   {fscanf(stream,"%3s",intext);defrounds=atoi(intext);fscanf(stream,"%3s",intext);turnsaday=atoi(intext);fscanf(stream,"%8s",olddate);fclose(stream);
   stream = fopen("SMURF.CFG", "w+");fprintf(stream,"%03i",defrounds);fprintf(stream,"%03i",turnsaday);fprintf(stream,"01011990");fprintf(stream,"\n\r\n\r1. Arena Rounds/Day\n\r2. Turns/Day\n\r3. Last Ran Date DDMMYYYY\n\r");fclose(stream);}

   delay(500);textcolor(14);cprintf("Success.\n\r");
textcolor(13);  cprintf("Reseting Variables: ");sleep(1);textcolor(14);cprintf("Success.\n\r");
textcolor(13);  cprintf("Writing Computer Players: ");
	savegame();
textcolor(14);cprintf("Success.\n\r");
textcolor(13);cprintf("Saving Save Game File: ");
delay(200);
textcolor(14);cprintf("Success.\n\r");
textcolor(13);cprintf("Writing Name Listing: ");
  stream = fopen("SMURF.SCL", "w+");delay(200);
  fprintf(stream, "NAME LISTING:)\n\r");
  fprintf(stream, "[0-CPU] #1:) GRANDPA SMURF\n\r");
  fprintf(stream, "[0-CPU] #2:) PAPA SMURF\n\r");
  fprintf(stream, "[0-CPU] #3:) SHADOW SMURF\n\r");
  fprintf(stream, "[0-CPU] #4:) REBEL SMURF\n\r");
  fclose(stream);
textcolor(14);cprintf("Success.\n\r");
textcolor(13);cprintf("Writing Error Log File: ");
  stream = fopen("SMURF.SEL", "w+");delay(200);
  fprintf(stream, "ERROR RECORDS:)\n\r");
  fprintf(stream, "LOCALDOS:) ***Ran Re-Roll program\n\r");
  fclose(stream);
textcolor(14);cprintf("Success.\n\r");
textcolor(13);cprintf("Writing Player Logon Log File: ");
  stream = fopen("SMURF.SGL", "w+");delay(200);
  fclose(stream);
textcolor(14);cprintf("Success.\n\r");

textcolor(13);cprintf("Writing Personal Log Files: ");delay(200);
  stream = fopen("SMURFLOG.XXX", "w+");fclose(stream);
  system("DEL SMURFLOG.*");
textcolor(14);cprintf("Success.\n\r");
textcolor(13);cprintf("Writing Player Hostage File: ");delay(200);
stream = fopen("SMURF.HST", "w+");fprintf(stream,"255255");fclose(stream);
system("DEL SMURF.D0D");
textcolor(14);cprintf("Success.\n\r");
}
