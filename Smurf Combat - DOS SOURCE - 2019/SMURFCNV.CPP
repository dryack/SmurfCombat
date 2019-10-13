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
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

#include"smurfdef.h"

#include"smurfgen.h"

#include"smurfver.h"

#include"smurfsav.h"

#include"smurfcnv.h"





void main(void){
int a=0,b=0,c=0;
getdate(&d);

clrscr();
printf("This program will convert your old Smurf Combat save game files\n");
printf("from version 69a-69c to version 91.   If you are not sure which\n");
printf("version you are converting FROM, press letter X to abort.  Your\n");
printf("current version number will be displayed on the title screen of\n");
printf("Smurf Combat.\n\n");
printf("Press X to abort, any other key to continue...");


proc=getch();


if(proc=='X' || proc=='x')exit(1);



clrscr();textcolor(12);cprintf("\n");
cprintf("   S M U R F   C O M B A T\n\n\r");textcolor(10);
cprintf("   69-91 Conversion Module\n\r");
cprintf("        %sVersion %s\n\r",__vcnvsp,__vcnv);
cprintf("     By Laurence Maar\n\n\r");
textcolor(9);cprintf("From Version 69a, 69b, or 69c? [abC]: ");textcolor(12);proc=getch();
if(proc=='A' || proc=='a')a=1;	else if(proc=='B' || proc=='b')b=1; else c=1;
textcolor(9);cprintf("\n\n\rProceed?   [Yn]: ");textcolor(12);proc=getch();
if(proc!='Y' && proc!='y'){cprintf("Nope\n\r");return;}cprintf("Yea\n\n\r");
textcolor(9);cprintf("Sure!?!?!? [Yn]: ");textcolor(12);proc=getch();
if(proc!='Y' && proc!='y'){cprintf("Nope\n\r");return;}cprintf("Yea\n\n\r");
textcolor(9);cprintf("SURE!?!?!? [Yn]: ");textcolor(12);proc=getch();
if(proc!='Y' && proc!='y'){cprintf("Nope\n\r");return;}cprintf("Yea\n\n\r");
if(a)loadgame69a();
if(b)loadgame69b();
if(c)loadgame69c();
for(cyc=0;cyc<noplayers;cyc++){__morale[cyc]=3;__ettemorale[cyc]=0;}
savegame();
}





